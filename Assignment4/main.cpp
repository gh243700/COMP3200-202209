#include "BinarySearchTree.h"
#include <cassert>

using namespace assignment4;

int main()
{
	{
		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(1));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(2));
		bt.Insert(std::make_unique<int>(6));
		bt.Insert(std::make_unique<int>(11));
		std::vector<int> result = bt.TraverseInOrder(bt.GetRootNode().lock());
		assert(result[0] == 1);
		assert(result[1] == 2);
		assert(result[2] == 3);
		assert(result[3] == 4);
		assert(result[4] == 5);

		assert(result[5] == 6);
		assert(result[6] == 8);
		assert(result[7] == 11);

		std::shared_ptr<TreeNode<int>> node = bt.GetRootNode().lock();
		std::shared_ptr<TreeNode<int>> left = node->Left;
		std::shared_ptr<TreeNode<int>> right = node->Right;

		assert(*(node->Data) == 5);
		assert(*(left->Data) == 3);
		assert(*(right->Data) == 8);


		bt.Delete(5);

		node = nullptr;
		node = bt.GetRootNode().lock();
		assert(*(node->Data) == 4);
		assert(*(left->Data) == 3);
		assert(*(right->Data) == 8);
		assert(node->Parent.expired() == true);

		
		result = bt.TraverseInOrder(bt.GetRootNode().lock());

		assert(result[0] == 1);
		assert(result[1] == 2);
		assert(result[2] == 3);
		assert(result[3] == 4);
		assert(result[4] == 6);
		assert(result[5] == 8);
		assert(result[6] == 11);
	}

	{
		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(1));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(2));
		bt.Insert(std::make_unique<int>(6));
		bt.Insert(std::make_unique<int>(11));
		bt.Insert(std::make_unique<int>(3));

		std::vector<int> result = bt.TraverseInOrder(bt.GetRootNode().lock());
		assert(result[0] == 1);
		assert(result[1] == 2);
		assert(result[2] == 3);
		assert(result[3] == 3);

		assert(result[4] == 4);
		assert(result[5] == 5);

		assert(result[6] == 6);
		assert(result[7] == 8);
		assert(result[8] == 11);

		std::shared_ptr<TreeNode<int>> node = bt.GetRootNode().lock();
		std::shared_ptr<TreeNode<int>> left = node->Left;
		std::shared_ptr<TreeNode<int>> right = node->Right;

		assert(*(node->Data) == 5);
		assert(*(left->Data) == 3);
		assert(*(right->Data) == 8);


		bt.Delete(5);

		node = nullptr;
		node = bt.GetRootNode().lock();
		assert(*(node->Data) == 3);
		assert(*(node->Left->Data) == 1);
		assert(*(node->Right->Data) == 4);
		assert(*(node->Right->Right->Parent.lock()->Data) == 4);
		assert(node->Parent.expired());


		result = bt.TraverseInOrder(bt.GetRootNode().lock());

		assert(result[0] == 1);
		assert(result[1] == 2);
		assert(result[2] == 3);
		assert(result[3] == 3);
		assert(result[4] == 4);
		assert(result[5] == 6);
		assert(result[6] == 8);
		assert(result[7] == 11);

	}


	{
		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(6));
		bt.Insert(std::make_unique<int>(11));


		std::vector<int> result = bt.TraverseInOrder(bt.GetRootNode().lock());
		assert(result[0] == 3);
		assert(result[1] == 3);
		assert(result[2] == 4);
		assert(result[3] == 6);

		assert(result[4] == 8);
		assert(result[5] == 11);

		std::shared_ptr<TreeNode<int>> node = bt.GetRootNode().lock();
		std::shared_ptr<TreeNode<int>> left = node->Left;
		std::shared_ptr<TreeNode<int>> right = node->Right;

		assert(*(node->Data) == 3);
		assert(left == nullptr);
		assert(*(right->Data) == 4);


		bt.Delete(3);

		node = nullptr;
		node = bt.GetRootNode().lock();
		assert(*(node->Data) == 3);
		assert(node->Left == nullptr);
		assert(*(node->Right->Data) == 4);
		assert(node->Parent.expired());

		result = bt.TraverseInOrder(bt.GetRootNode().lock());

		assert(result[0] == 3);
		assert(result[1] == 4);
		assert(result[2] == 6);
		assert(result[3] == 8);
		assert(result[4] == 11);
	}

	{
		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(6));
		bt.Insert(std::make_unique<int>(11));


		std::vector<int> result = bt.TraverseInOrder(bt.GetRootNode().lock());
		assert(result[0] == 3);
		assert(result[1] == 3);
		assert(result[2] == 4);
		assert(result[3] == 5);
		assert(result[4] == 6);
		assert(result[5] == 8);
		assert(result[6] == 11);

		std::shared_ptr<TreeNode<int>> node = bt.GetRootNode().lock();
		std::shared_ptr<TreeNode<int>> left = node->Left;
		std::shared_ptr<TreeNode<int>> right = node->Right;

		assert(*(node->Data) == 3);
		assert(left == nullptr);
		assert(*(right->Data) == 5);


		bt.Delete(3);

		node = nullptr;
		node = bt.GetRootNode().lock();
		assert(*(node->Data) == 5);
		assert(*(node->Left->Data) == 3);
		assert(*(node->Right->Data) == 8);
		assert(node->Parent.expired());


		result = bt.TraverseInOrder(bt.GetRootNode().lock());

		assert(result[0] == 3);
		assert(result[1] == 4);
		assert(result[2] == 5);
		assert(result[3] == 6);
		assert(result[4] == 8);
		assert(result[5] == 11);


		bt.Delete(8);
		assert(bt.Search(8) == false);
		assert(bt.Search(6) == true);
		assert(bt.Search(11) == true);



	}
	{
		
		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(1));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(2));
		bt.Insert(std::make_unique<int>(6));
		bt.Insert(std::make_unique<int>(11));

		assert(bt.Search(5) == true);
		assert(bt.Search(3) == true);
		assert(bt.Search(11) == true);
		assert(bt.Search(2) == true);
		assert(bt.Search(1) == true);
		assert(bt.Search(100) == false);
		assert(bt.Search(0) == false);
	
	}

	{

		BinarySearchTree<int> bt;

		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(3));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(1));
		bt.Insert(std::make_unique<int>(4));
		bt.Insert(std::make_unique<int>(2));
		bt.Insert(std::make_unique<int>(1));
		bt.Insert(std::make_unique<int>(3));

		bt.Delete(3);
		assert(*(bt.GetRootNode().lock()->Data) == 5);
		assert(*(bt.GetRootNode().lock()->Left->Parent.lock()->Data) == 5);
		assert(*(bt.GetRootNode().lock()->Left->Right->Right->Data) == 4);
		assert(*(bt.GetRootNode().lock()->Left->Right->Right->Parent.lock()->Data) == 2);

	
	
	}

	system("pause");
}