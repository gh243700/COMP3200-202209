#pragma once

#include <memory>
#include <vector>
#include <iostream>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;
		bool ForTestPerpose(std::vector<T> arr);

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mHead;
		size_t mCount;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mCount(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		++mCount;
		if (mHead == nullptr)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>> node = mHead;
		while (node->Next != nullptr)
		{
			node = node->Next;
		}

		node->Next = std::make_shared<Node<T>>(std::move(data), node);

	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		++mCount;
		if (mHead == nullptr)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			return;
		}

		std::shared_ptr<Node<T>> node = mHead;
		size_t i = 0;

		while (i++ < index)
		{
			if (node->Next == nullptr)
			{
				std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), node);
				newNode->Next = node->Next;
				node->Next = newNode;
				return;
			}
			node = node->Next;
		}

		if (node == mHead)
		{
			std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = mHead;
			mHead->Previous = newNode;
			mHead = newNode;

			return;
		}

		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data), node->Previous.lock());
		newNode->Next = node;
		node->Previous.lock()->Next = newNode;
		node->Previous = newNode;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> node = mHead;
		bool exists = false;
		while (node->Next != nullptr)
		{
			if (*(node->Data) == data)
			{
				exists = true;
				break;
			}

			node = node->Next;
		}

		if (!exists)
		{
			return false;
		}

		--mCount;

		if (node == mHead)
		{
			mHead = mHead->Next;
			return true;
		}

		(node->Previous).lock()->Next = node->Next;

		if (node->Next != nullptr)
		{
			node->Next->Previous = node->Previous;
		}

		return true;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> node = mHead;
		while (node != nullptr)
		{
			if (*(node->Data) == data)
			{
				return true;
			}

			node = node->Next;
		}

		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mCount)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> node = mHead;

		for (unsigned int i = 0; i < index; ++i)
		{
			node = node->Next;
		}

		return node;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mCount;
	}


	template<typename T>
	bool DoublyLinkedList<T>::ForTestPerpose(std::vector<T> arr)
	{
		if (arr.size() != GetLength())
		{
			std::cout << "count not equal , mCount : " << mCount << ", vector count : " << arr.size() << std::endl;
			return false;
		}

		std::shared_ptr<Node<T>> node = mHead;
		unsigned int i = 0;
		while (node != nullptr)
		{
			if (*(node->Data) != arr[i++])
			{
				std::cout << "not correct value at index : ";
				std::cout << i - 1;
				std::cout << "\n expected : ";
				std::cout << arr[i - 1] << ", actural : " << (*(node->Data)) << std::endl;
				return false;
			}
			std::cout << *(node->Data);
			node = node->Next;



		}
		std::cout << std::endl;
		return true;
	}
}