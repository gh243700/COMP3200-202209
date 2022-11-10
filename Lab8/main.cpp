#include "FixedVector.h"
#include <cassert>
#include <iostream>
#include <cstdint>

using namespace lab8;

void TEST1()
{
	{
		FixedVector<int, 5> v1;
		assert(v1.Remove(1) == false);
		assert(v1.GetCapacity() == 5);

		for (unsigned int i = 0; i < v1.GetCapacity(); ++i)
		{
			assert(v1.Add(i));
		}

		assert(v1.GetSize() == v1.GetCapacity());
		assert(v1.Add(-1) == false);


		assert(v1.Remove(0) == true);
		assert(v1.GetSize() == 4);
		assert(v1.Get(0) == 1);
		assert(v1.Get(1) == 2);
		assert(v1.Get(2) == 3);
		assert(v1.Get(3) == 4);



		assert(v1.Remove(2) == true);
		assert(v1.GetSize() == 3);
		assert(v1.Get(0) == 1);
		assert(v1.Get(1) == 3);
		assert(v1.Get(2) == 4);

		assert(v1.Remove(4) == true);
		assert(v1.GetSize() == 2);
		assert(v1.Get(0) == 1);
		assert(v1.Get(1) == 3);

		assert(v1[0] == 1);
		v1[0] = 4;
		assert(v1[0] == 4);
		assert(v1.GetIndex(4) == 0);
		assert(v1.GetIndex(3) == 1);
	}
	{
		FixedVector<int, 33> v1;
		assert(v1.GetCapacity() == 33);

		for (unsigned int i = 0; i < v1.GetCapacity(); ++i)
		{
			assert(v1.Add(i + 1));
		}

		assert(v1.GetSize() == v1.GetCapacity());
		assert(v1.Add(-1) == false);


		assert(v1.Remove(1) == true);
		assert(v1.GetSize() == 32);
		int expected[32];
		for (unsigned int i = 0; i < 32; ++i)
		{
			expected[i] = i + 2;
		}

		for (unsigned int i = 0; i < 32; ++i)
		{
			assert(expected[i] == v1[i]);
			assert(expected[i] == v1.Get(i));
		}


		assert(v1.Remove(3) == true); //2 4
		assert(v1.GetSize() == 31);
		assert(v1[0] == 2);
		assert(v1[1] == 4);
		assert(v1[2] == 5);


		assert(v1.Remove(32) == true);
		assert(v1.GetSize() == 30);
		assert(v1.Get(29) == 33);
		assert(v1.Get(28) == 31);
		assert(v1.Remove(100) == false);
		assert(v1.GetIndex(100) == -1);
	}


}

int main()
{
	TEST1();


	{
		FixedVector<bool, 5> v1;
		assert(v1.Remove(true) == false);
		assert(v1.GetCapacity() == 5);

		v1.Add(true);
		v1.Add(false);
		v1.Add(true);
		v1.Add(false);
		v1.Add(true);




		assert(v1.GetSize() == v1.GetCapacity());
		assert(v1.Add(-1) == false);


		assert(v1.Remove(true) == true);
		assert(v1.GetSize() == 4);
		assert(v1.Get(0) == false);
		assert(v1.Get(1) == true);
		assert(v1.Get(2) == false);
		assert(v1.Get(3) == true);



		assert(v1.Remove(1) == true); // f f t
		assert(v1.GetSize() == 3);
		assert(v1.Get(0) == false);
		assert(v1.Get(1) == false);
		assert(v1.Get(2) == true);

		assert(v1.Remove(4) == true);
		assert(v1.GetSize() == 2);
		assert(v1.Get(0) == false);
		assert(v1.Get(1) == false);

		assert(v1[0] == false);
		assert(v1[0] == false);
		assert(v1.GetIndex(false) == 0);
		assert(v1.GetIndex(true) == -1);
	}


	{
		FixedVector<bool, 16> v1;
		assert(v1.GetCapacity() == 16);

		for (unsigned int i = 0; i < v1.GetCapacity(); ++i)
		{
			assert(v1.Add(i % 2 == 0 ? true : false));
		}

		assert(v1.GetSize() == v1.GetCapacity());
		//assert(v1.Add(-1) == false);

		assert(v1.Remove(1) == true);
		{
			int expected[15] = {
				false, true, false, true, false, true, false, true, false, true,
				false, true, false, true, false
			};

			for (unsigned int i = 0; i < 15; ++i)
			{
				assert(expected[i] == v1[i]);
				assert(expected[i] == v1.Get(i));
			}


		}

	}

	{
		FixedVector<bool, 51> v1;
		for (unsigned int i = 0; i < 40; ++i)
		{
			v1.Add(false);
		}

		v1.Add(true);
		v1.Add(true);
		v1.Add(false);
		v1.Add(true);
		v1.Add(false);
		v1.Add(false);

		v1.Print();

		assert(v1.Remove(false) == true);

		bool expected[50] =
		{
			false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			true, true, false, true, false, false
		};



		for (unsigned int i = 0; i < 50; ++i)
		{
			assert(expected[i] == v1[i]);
			assert(expected[i] == v1.Get(i));
		}


		assert(v1.Remove(true) == true);

		bool expected1[49] =
		{
			false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			true, false, true, false, false
		};
		v1.Print();
		for (unsigned int i = 0; i < 49; ++i)
		{
			if (i % 10 == 0)
			{
				std::cout << std::endl;
			}
			std::cout << v1[i] << ",";

			assert(expected1[i] == v1[i]);
			assert(expected1[i] == v1.Get(i));
		}

	}


	{
		FixedVector<bool, 51> v1;
		for (unsigned int i = 0; i < 32; ++i)
		{
			v1.Add(false);
		}

		v1.Add(true);
		for (unsigned int i = 0; i < 8; ++i)
		{
			v1.Add(false);
		}
		v1.Add(true);
		v1.Add(true);
		v1.Add(false);
		v1.Add(true);
		v1.Add(false);
		v1.Add(false);

		assert(v1.Remove(true) == true);

		bool expected1[49] =
		{
			false, false, false, false,	 false,	 false, false,	 false, false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			false, false, false, false, false,	 false,	 false, false,	 false, false,
			true, true, false, true, false, false
		};
		v1.Print();
		for (unsigned int i = 0; i < 49; ++i)
		{
			assert(expected1[i] == v1[i]);
			assert(expected1[i] == v1.Get(i));
		}

	}

	{
		{
			FixedVector<bool, 51> v1;
			for (unsigned int i = 0; i < 31; ++i)
			{
				v1.Add(false);
			}
			v1.Add(true);

			v1.Add(true);
			for (unsigned int i = 0; i < 8; ++i)
			{
				v1.Add(false);
			}
			v1.Add(true);
			v1.Add(true);
			v1.Add(false);
			v1.Add(true);
			v1.Add(false);
			v1.Add(false);

			assert(v1.Remove(true) == true);

			bool expected1[49] =
			{
				false, false, false, false,	 false,	 false, false,	 false, false, false,
				false, false, false, false, false,	 false,	 false, false,	 false, false,
				false, false, false, false, false,	 false,	 false, false,	 false, false,
				false, true, false, false, false,	 false,	 false, false,	 false, false,
				true, true, false, true, false, false
			};
			v1.Print();
			for (unsigned int i = 0; i < 49; ++i)
			{
				assert(expected1[i] == v1[i]);
				assert(expected1[i] == v1.Get(i));
			}

		}
	
	
	
	}



	std::cout << "FIN";
	system("pause");
}