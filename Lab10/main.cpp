#include <memory>
#include "Node.h"
#include <cassert>
#include <vector>
#include "DoublyLinkedList.h"

using namespace lab10;

int main()
{
	/*
	{
		std::unique_ptr<int> number1 = std::make_unique<int>(1);
		std::unique_ptr<int> number2 = std::make_unique<int>(2);
		std::unique_ptr<int> number3 = std::make_unique<int>(3);
		std::unique_ptr<int> number4 = std::make_unique<int>(4);
		std::unique_ptr<int> number5 = std::make_unique<int>(5);
		std::unique_ptr<int> number6 = std::make_unique<int>(6);
		std::unique_ptr<int> number7 = std::make_unique<int>(7);
		std::unique_ptr<int> number8 = std::make_unique<int>(8);
		std::unique_ptr<int> number9 = std::make_unique<int>(9);

		std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		DoublyLinkedList<int> list;
		list.Insert(std::move(number1));
		list.Insert(std::move(number2));
		list.Insert(std::move(number3));
		list.Insert(std::move(number4));
		list.Insert(std::move(number5));
		list.Insert(std::move(number6));
		list.Insert(std::move(number7));
		list.Insert(std::move(number8));
		list.Insert(std::move(number9));

		list.ForTestPerpose(expected);

		expected.erase(expected.begin());
		list.Delete(1);
		assert(list.ForTestPerpose(expected) == true);

		list.Insert(std::make_unique<int>(1), 0);
		expected.insert(expected.begin(), 1);
		assert(list.ForTestPerpose(expected) == true);
		assert(*(list[0]->Next->Previous.lock()->Data) == 1);

		list.Delete(3);
		expected.erase(expected.begin() + 2);
		assert(list.ForTestPerpose(expected));

		expected.insert(expected.begin() + 2, 3);
		list.Insert(std::make_unique<int>(3), 2);
		assert(list.ForTestPerpose(expected));
		assert(*(list[2]->Previous.lock()->Data) == 2);

		expected.push_back(10);
		list.Insert(std::make_unique<int>(10), 9);
		assert(list.ForTestPerpose(expected));

		assert(list.Search(11) == false);
		assert(list.Search(1) == true);
		assert(list.Search(10) == true);

		assert(*(list[0]->Data) == 1);
		assert(*(list[9]->Data) == 10);
		assert(list[11] == nullptr);

		assert(list.GetLength() == 10);


		list.Insert(std::make_unique<int>(99), 9);
		expected.insert(expected.begin() + 9, 99);
		assert(list.ForTestPerpose(expected));
		assert(*(list[9]->Previous.lock()->Data) == 9);

	}
	*/
	{
		DoublyLinkedList<int> list;
		std::vector<int> expected;

		list.Insert(std::make_unique<int>(1), 0);
		expected.push_back(1);
		assert(list.ForTestPerpose(expected));
	
		list.Insert(std::make_unique<int>(0), 0);
		expected.insert(expected.begin(), 0);
		assert(list.ForTestPerpose(expected));


		list.Insert(std::make_unique<int>(3), 3);
		expected.push_back(3);
		assert(list.ForTestPerpose(expected));


		list.Insert(std::make_unique<int>(6), 2);
		expected.insert(expected.begin() + 2, 6);
		assert(list.ForTestPerpose(expected));

		list.Insert(std::make_unique<int>(9), 2);
		expected.insert(expected.begin() + 2, 9);
		assert(list.ForTestPerpose(expected));

		list.Insert(std::make_unique<int>(0), 4);
		expected.insert(expected.begin() + 4, 0);
		assert(list.ForTestPerpose(expected));

	}



	std::cout << "dddddd";
	system("pause");
}