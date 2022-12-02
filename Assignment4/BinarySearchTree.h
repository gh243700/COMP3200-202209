#pragma once

#include <memory>
#include <vector>
#include "TreeNode.h"
#include <cassert>

namespace assignment4
{
	enum class eSearchType
	{
		OrderSuccessor,
		OrderPredecessor
	};

	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		void insertHelperRecrusive(std::shared_ptr<TreeNode<T>> node, std::unique_ptr<T> data);
		bool searchHelperRecursive(const T& data, std::shared_ptr<TreeNode<T>> node);
		std::shared_ptr<TreeNode<T>>* findNode(const T& data, std::shared_ptr<TreeNode<T>>& node);
		bool deleteLeafRecursive(std::shared_ptr<TreeNode<T>>& parant, std::shared_ptr<TreeNode<T>>& node, const eSearchType mode);
		static void traverseInOrderHelperRecursive(std::vector<T>& vector, const std::shared_ptr<TreeNode<T>> node);


		std::shared_ptr<TreeNode<T>> mRoot;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRoot == nullptr)
		{
			mRoot = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		insertHelperRecrusive(mRoot, std::move(data));
	}

	template<typename T>
	void BinarySearchTree<T>::insertHelperRecrusive(std::shared_ptr<TreeNode<T>> node, std::unique_ptr<T> data)
	{
		if (*(node->Data) > *data)
		{
			if (node->Left == nullptr)
			{
				node->Left = std::make_shared<TreeNode<T>>(node, std::move(data));
				return;
			}
			insertHelperRecrusive(node->Left, std::move(data));
			return;
		}

		if (node->Right == nullptr)
		{
			node->Right = std::make_shared<TreeNode<T>>(std::move(data));
			return;
		}

		insertHelperRecrusive(node->Right, std::move(data));
	}


	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRoot;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		return searchHelperRecursive(data, mRoot);
	}

	template<typename T>
	bool BinarySearchTree<T>::searchHelperRecursive(const T& data, std::shared_ptr<TreeNode<T>> node)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (*(node->Data) == data)
		{
			return true;
		}

		if (*(node->Data) > data)
		{
			return searchHelperRecursive(data, node->Left);
		}

		return searchHelperRecursive(data, node->Right);
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>>& node = *findNode(data, mRoot);

		if (node == nullptr)
		{
			return false;
		}

		if (deleteLeafRecursive(node, node->Left, eSearchType::OrderSuccessor))
		{
			return true;
		}

		if (node->Left != nullptr)
		{
			std::shared_ptr<TreeNode<T>> leftMaxNode = node->Left;
			while (leftMaxNode->Right != nullptr)
			{
				leftMaxNode = leftMaxNode->Right;
			}
			node->Right->Parent = leftMaxNode;
			leftMaxNode->Right = node->Right;
			node->Left->Parent = node->Parent;
			std::shared_ptr<TreeNode<T>> elderNode = node->Parent.lock();
			if (elderNode != nullptr)
			{
				if (elderNode->Left == node)
				{
					elderNode->Left = node->Left;
				}
				else
				{
					elderNode->Right = node->Left;
				}
			}
			else 
			{
				node = node->Left;
			}
			
			return true;
		}

		if (deleteLeafRecursive(node, node->Right, eSearchType::OrderPredecessor))
		{
			return true;
		}

		if (node->Right != nullptr)
		{
			node->Right->Parent = node->Parent;
			std::shared_ptr<TreeNode<T>> elderNode = node->Parent.lock();
			if (elderNode != nullptr)
			{
				if (elderNode->Left == node)
				{
					elderNode->Left = node->Right;
				}
				else
				{
					elderNode->Right = node->Right;
				}
			}
			else 
			{
				node = node->Right;
			}
			
			return true;
		}

		node = nullptr;

		return true;
	}

	template<typename T>
	bool BinarySearchTree<T>::deleteLeafRecursive(std::shared_ptr<TreeNode<T>>& parant, std::shared_ptr<TreeNode<T>>& node, const eSearchType mode)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (((mode == eSearchType::OrderSuccessor) ? node->Right : node->Left) == nullptr)
		{
			if (((mode == eSearchType::OrderSuccessor) ? node->Left : node->Right) != nullptr)
			{
				return false;
			}
			node->Data.swap(parant->Data);
			node = nullptr;
			return true;
		}

		return deleteLeafRecursive(parant, (mode == eSearchType::OrderSuccessor) ? node->Right : node->Left, mode);
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>>* BinarySearchTree<T>::findNode(const T& data, std::shared_ptr<TreeNode<T>>& node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (*(node->Data) == data)
		{
			return &node;
		}

		if (*(node->Data) > data)
		{
			return findNode(data, node->Left);
		}

		return findNode(data, node->Right);
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		traverseInOrderHelperRecursive(v, startNode);
		return v;
	}

	template<typename T>
	void BinarySearchTree<T>::traverseInOrderHelperRecursive(std::vector<T>& vector, const std::shared_ptr<TreeNode<T>> node)
	{
		if (node == nullptr)
		{
			return;
		}

		traverseInOrderHelperRecursive(vector, node->Left);
		vector.push_back(*(node->Data));
		traverseInOrderHelperRecursive(vector, node->Right);
	}

}