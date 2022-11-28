#include "Storage.h"
#include <cassert>
#include <iostream>

using namespace lab11;
int main()
{

	{
		
		Storage<int> dummy(5, 5);
		Storage<int> st(dummy);

		assert(st.GetSize() == 5);

		const std::unique_ptr<int[]>& copy = st.GetData();
		assert(copy[0] == 5);
		assert(copy[1] == 5);
		assert(copy[2] == 5);
		assert(copy[3] == 5);
		assert(copy[4] == 5);

	}
	{
		Storage<int> dummy(5, 5);
		dummy = dummy;
	
		const std::unique_ptr<int[]>& copy = dummy.GetData();
		assert(copy[0] == 5);
		assert(copy[1] == 5);
		assert(copy[2] == 5);
		assert(copy[3] == 5);
		assert(copy[4] == 5);
	}

	{
		Storage<int> dummy(5, 5);
		Storage<int> st(9);

		st = dummy;

		assert(st.GetSize() == 5);

		const std::unique_ptr<int[]>& copy = st.GetData();
		assert(copy[0] == 5);
		assert(copy[1] == 5);
		assert(copy[2] == 5);
		assert(copy[3] == 5);
		assert(copy[4] == 5);
	
	
	
	}

	{
		Storage<int> st(5);
		
		st = std::move(st);
		assert(st.GetSize() == 5);
		assert(st.GetData() != nullptr);

		const std::unique_ptr<int[]>& copy = st.GetData();

		assert(copy[0] == 0);
		assert(copy[1] == 0);
		assert(copy[2] == 0);
		assert(copy[3] == 0);
		assert(copy[4] == 0);
	}
	{
		Storage<int> st(5);

		const std::unique_ptr<int[]>& copy = st.GetData();
		assert(copy[0] == 0);
		assert(copy[1] == 0);
		assert(copy[2] == 0);
		assert(copy[3] == 0);
		assert(copy[4] == 0);
	}
	{
		Storage<int> st(5, 4);
		const std::unique_ptr<int[]>& copy = st.GetData();
		assert(copy[0] == 4);
		assert(copy[1] == 4);
		assert(copy[2] == 4);
		assert(copy[3] == 4);
		assert(copy[4] == 4);
	}
	{
		Storage<int> st(5);
		st.Update(0, 0);
		st.Update(1, 1);
		st.Update(2, 2);
		st.Update(3, 3);
		st.Update(4, 4);

		const std::unique_ptr<int[]>& copy = st.GetData();
		assert(copy[0] == 0);
		assert(copy[1] == 1);
		assert(copy[2] == 2);
		assert(copy[3] == 3);
		assert(copy[4] == 4);
	}

	{
		Storage<int> s1(9);
		Storage<int> s2(5, 10);

		assert(s1.GetSize() == 9);
		s1 = std::move(s2);
		
		assert(s1.GetSize() == 5);
		assert(s2.GetSize() == 0);

		assert(s2.GetData() == nullptr);
		const std::unique_ptr<int[]>& copy = s1.GetData();
		assert(copy[0] == 10);
		assert(copy[1] == 10);
		assert(copy[2] == 10);
		assert(copy[3] == 10);
		assert(copy[4] == 10);
	}

	{
		Storage<int> s2(5, 10);
		Storage<int> s1(std::move(s2));

		assert(s1.GetSize() == 5);
		assert(s2.GetSize() == 0);

		assert(s2.GetData() == nullptr);
		const std::unique_ptr<int[]>& copy = s1.GetData();
		assert(copy[0] == 10);
		assert(copy[1] == 10);
		assert(copy[2] == 10);
		assert(copy[3] == 10);
		assert(copy[4] == 10);
	}

	std::cout << "TEST COMPLETE" << std::endl;

	system("pause");
}