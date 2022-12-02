#include "BinarySearchTree.h"
#include <cassert>

using namespace assignment4;
void Test_Insert_GetRoot()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	tree.Insert(std::make_unique<int>(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
	assert(*test0->Data.get() == 10);
	assert(test0->Parent.lock().get() == nullptr);
	std::shared_ptr<TreeNode<int>> test1 = test0->Left;
	assert(*test1->Data.get() == 5);
	assert(*test1->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test2 = test1->Left;
	assert(*test2->Data.get() == 4);
	assert(*test2->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test3 = test1->Right;
	assert(*test3->Data.get() == 7);
	assert(*test3->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test4 = test0->Right;
	assert(*test4->Data.get() == 15);
	assert(*test4->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test5 = test4->Left;
	assert(*test5->Data.get() == 12);
	assert(*test5->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test6 = test4->Right;
	assert(*test6->Data.get() == 19);
	assert(*test6->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test7 = test6->Left;
	assert(*test7->Data.get() == 17);
	assert(*test7->Parent.lock()->Data.get() == 19);
	std::shared_ptr<TreeNode<int>> test8 = test6->Right;
	assert(*test8->Data.get() == 20);
	assert(*test8->Parent.lock()->Data.get() == 19);

	return;
}

void Test_Search()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	assert(!tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[0]));
	assert(tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	assert(tree.Search(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	assert(tree.Search(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	assert(tree.Search(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	assert(tree.Search(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	assert(tree.Search(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	assert(tree.Search(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	assert(tree.Search(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));
	assert(tree.Search(arr[8]));
	assert(!tree.Search(arr[9]));

	return;
}

void Test_Delete()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	//	End
	assert(!tree.Delete(9)); 	// 존재하지 않는 노드 삭제
	assert(tree.Delete(20));	// Right 노드 삭제
	assert(!tree.Search(20));	// 삭제 확인
	assert(tree.Delete(12));	// Left 노드 삭제
	assert(!tree.Search(12));	// 삭제 확인
	assert(!tree.Delete(11));	// 존재하지 않는 노드 삭제

	//	Middle
	assert(tree.Delete(19));	// Left만 있는 노드 삭제
	assert(!tree.Search(19));	// 삭제 확인
	assert(tree.Search(17));

	assert(tree.Delete(4));
	assert(tree.Delete(7));
	assert(tree.Delete(17));	// Left, Right 모두 없는 헤드 삭제
	assert(!tree.Search(17));	// 삭제 확인
	assert(!tree.Delete(17));	// 비어있는 상태에서 삭제

	assert(tree.Delete(15));	// Right만 있는 노드 삭제
	assert(!tree.Search(15));	// 삭제 확인
	assert(tree.Delete(5)); 	// Left, Right 모두 있는 노드 삭제
	assert(!tree.Search(5));
	assert(!tree.Delete(5));	// 존재하지 않는 노드 삭제

	//	Head
	assert(tree.Delete(10)); 	// Left, Right 모두 있는 헤드 삭제
	assert(!tree.Search(10));	// 삭제 확인

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	tree.Delete(arr[0]);
	tree.Delete(arr[1]);
	tree.Delete(arr[2]);
	tree.Delete(arr[3]);
	tree.Delete(arr[4]);
	tree.Delete(arr[5]);
	tree.Delete(arr[6]);
	tree.Delete(arr[7]);
	tree.Delete(arr[8]);

	return;
}

void Test_Traverse()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };
	int arr_chk[9] = { 4, 5, 7, 10, 12, 15, 17, 19, 20 };

	// 빈 트리
	std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 0);
	assert(v1.empty());

	tree.Insert(std::make_unique<int>(arr[0]));
	// 헤드만 있는 트리
	std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v2.size() == 1);
	assert(v2[0] == arr[0]);

	// empty 포인터
	std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
	assert(v3.size() == 0);
	assert(v3.empty());

	// 트리 입력
	for (size_t i = 1; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	// 헤드 노드 입력
	std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v4.size() == 9);
	assert(v4[0] == arr_chk[0]);
	assert(v4[1] == arr_chk[1]);
	assert(v4[2] == arr_chk[2]);
	assert(v4[3] == arr_chk[3]);
	assert(v4[4] == arr_chk[4]);
	assert(v4[5] == arr_chk[5]);
	assert(v4[6] == arr_chk[6]);
	assert(v4[7] == arr_chk[7]);
	assert(v4[8] == arr_chk[8]);

	// 중간 노드 입력
	std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
	assert(v5.size() == 3);
	assert(v5[0] == arr_chk[6]);
	assert(v5[1] == arr_chk[7]);
	assert(v5[2] == arr_chk[8]);

	// 말단 노드 입력
	std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
	assert(v6.size() == 1);
	assert(v6[0] == arr_chk[4]);

	// 노드 삭제
	for (size_t i = 0; i < 8; i++)
	{
		tree.Delete(arr[i]);
	}

	// 7만 남기고 모두 삭제된 트리
	std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v7.size() == 1);
	assert(v7[0] == arr[8]);

	// 노드가 모두 삭제된 트리
	tree.Delete(arr[8]);
	std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v8.size() == 0);
	assert(v8.empty());

	return;
}


int main()
{

	Test_Insert_GetRoot();
	Test_Search();
	Test_Delete();
	Test_Traverse();
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

//		node = nullptr;
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

	{
		BinarySearchTree<int> bt;
		bt.Insert(std::make_unique<int>(5));
		bt.Insert(std::make_unique<int>(8));
		bt.Insert(std::make_unique<int>(8));


	
	
	
	}

	system("pause");
}