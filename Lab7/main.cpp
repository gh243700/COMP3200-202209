
#include <iostream>
#include "Lab7.h"
#include <map>
#include <cassert>

using namespace lab7;

void TEST_ConvertVectorsToMap()
{

	{
		std::vector<char> keys;
		keys.push_back('a');
		keys.push_back('b');
		keys.push_back('c');

		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);

		std::map<char, int> map = ConvertVectorsToMap(keys, values);

		assert(map.size() == 3);

		int i = 0;
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			assert(iter->first == keys[i]);
			assert(iter->second == values[i]);
			i++;
		}
	}
	{
		std::vector<char> keys;
		keys.push_back('a');
		keys.push_back('b');
		keys.push_back('c');
		keys.push_back('d');
		keys.push_back('e');

		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);

		std::map<char, int> map = ConvertVectorsToMap(keys, values);
		assert(map.size() == 3);
		int i = 0;
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			assert(iter->first == keys[i]);
			assert(iter->second == values[i]);
			i++;
		}
	}

	{
		std::vector<char> keys;
		keys.push_back('a');
		keys.push_back('b');
		keys.push_back('c');

		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);
		values.push_back(5);

		std::map<char, int> map = ConvertVectorsToMap(keys, values);
		assert(map.size() == 3);

		int i = 0;
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			assert(iter->first == keys[i]);
			assert(iter->second == values[i]);
			i++;
		}
	}

	{
		std::vector<char> keys;
		keys.push_back('a');
		keys.push_back('b');
		keys.push_back('c');
		keys.push_back('c');
		keys.push_back('a');

		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);
		values.push_back(5);

		std::map<char, int> map = ConvertVectorsToMap(keys, values);

		assert(map.size() == 3);

		int i = 0;
		for (auto iter = map.begin(); iter != map.end(); ++iter)
		{
			assert(iter->first == keys[i]);
			assert(iter->second == values[i]);
			i++;
		}
	}

	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "TEST FOR ConvertVectorsToMap FIN" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

}

void TEST_GetKeysAndGetValues()
{
	{
		std::map<char, int> map;
		map.insert(std::pair<char, int>('a', 1));
		map.insert(std::pair<char, int>('b', 2));
		map.insert(std::pair<char, int>('c', 3));
		map.insert(std::pair<char, int>('d', 4));
		map.insert(std::pair<char, int>('e', 5));


		std::vector<char> keys = GetKeys(map);
		std::vector<char> expectedKeys;
		expectedKeys.push_back('a');
		expectedKeys.push_back('b');
		expectedKeys.push_back('c');
		expectedKeys.push_back('d');
		expectedKeys.push_back('e');


		std::vector<int> values = GetValues(map);
		std::vector<int> expectedValues;
		expectedValues.push_back(1);
		expectedValues.push_back(2);
		expectedValues.push_back(3);
		expectedValues.push_back(4);
		expectedValues.push_back(5);

		int i = 0;
		for (auto iter = keys.begin(); iter != keys.end(); ++iter)
		{
			assert(*iter == expectedKeys[i]);
			++i;
		}
		i = 0;
		for (auto iter = values.begin(); iter != values.end(); ++iter)
		{
			assert(*iter == expectedValues[i]);
			++i;
		}
	}
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "TEST FOR GetKeys()&&GetValues() FIN" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

}

void TEST_Reverse()
{

	{
		std::vector<int> values;
		values.push_back(1);
		values.push_back(2);
		values.push_back(3);
		values.push_back(4);
		values.push_back(5);

		std::vector<int> reversed = Reverse(values);
		const std::vector<int> expected = { 5, 4, 3, 2, 1 };

		assert(reversed.size() == expected.size());

		int i = 0;
		for (auto iter = reversed.begin(); iter != reversed.end(); ++iter)
		{
			assert(*iter == expected[i]);
			++i;
		}

		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "TEST FOR Reverse FIN" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	}


}

void TEST_operator_plus()
{

	{
		{
			const std::vector vector1 = { 1, 2, 3 };
			const std::vector vector2 = { 4, 5, 6 };
			const std::vector expected = { 1, 2, 3, 4, 5, 6 };

			std::vector result = vector1 + vector2;
			assert(result.size() == expected.size());

			int i = 0;
			for (auto iter = result.begin(); iter != result.end(); ++iter)
			{
				assert(*iter == expected[i]);
				++i;
			}
		}

		{

			const std::vector vector1 = { 1, 2, 3 };
			const std::vector vector2 = { 2, 4, 3, 5, 6 };
			const std::vector expected = { 1, 2, 3, 4, 5, 6 };

			std::vector result = vector1 + vector2;
			assert(result.size() == expected.size());

			int i = 0;
			for (auto iter = result.begin(); iter != result.end(); ++iter)
			{
				assert(*iter == expected[i]);
				++i;
			}
		}

		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "TEST FOR ::vector_operator+()" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	}

	{
		{
			std::map<char, int> map1;
			map1.insert(std::pair<char, int>('a', 1));
			map1.insert(std::pair<char, int>('b', 2));
			map1.insert(std::pair<char, int>('c', 3));
			map1.insert(std::pair<char, int>('d', 4));

			std::map<char, int> map2;
			map2.insert(std::pair<char, int>('e', 5));
			map2.insert(std::pair<char, int>('f', 6));
			map2.insert(std::pair<char, int>('g', 7));
			map2.insert(std::pair<char, int>('h', 8));


			std::map<char, int> expected;
			expected.insert(std::pair<char, int>('a', 1));
			expected.insert(std::pair<char, int>('b', 2));
			expected.insert(std::pair<char, int>('c', 3));
			expected.insert(std::pair<char, int>('d', 4));
			expected.insert(std::pair<char, int>('e', 5));
			expected.insert(std::pair<char, int>('f', 6));
			expected.insert(std::pair<char, int>('g', 7));
			expected.insert(std::pair<char, int>('h', 8));

			std::map<char, int> result = map1 + map2;
			assert(expected.size() == result.size());
			auto expected_iter = expected.begin();
			for (auto iter = result.begin(); iter != result.end(); ++iter)
			{
				assert(*iter == *expected_iter++);
			}

		}

		{
			std::map<char, int> map1;
			map1.insert(std::pair<char, int>('a', 1));
			map1.insert(std::pair<char, int>('b', 2));
			map1.insert(std::pair<char, int>('c', 3));
			map1.insert(std::pair<char, int>('d', 4));

			std::map<char, int> map2;
			map2.insert(std::pair<char, int>('b', 2));
			map2.insert(std::pair<char, int>('e', 5));
			map2.insert(std::pair<char, int>('f', 6));
			map2.insert(std::pair<char, int>('g', 7));
			map2.insert(std::pair<char, int>('h', 8));
			map2.insert(std::pair<char, int>('e', 5));
			map2.insert(std::pair<char, int>('f', 6));
			map2.insert(std::pair<char, int>('a', 1));
			map2.insert(std::pair<char, int>('b', 2));

			std::map<char, int> expected;
			expected.insert(std::pair<char, int>('a', 1));
			expected.insert(std::pair<char, int>('b', 2));
			expected.insert(std::pair<char, int>('c', 3));
			expected.insert(std::pair<char, int>('d', 4));
			expected.insert(std::pair<char, int>('e', 5));
			expected.insert(std::pair<char, int>('f', 6));
			expected.insert(std::pair<char, int>('g', 7));
			expected.insert(std::pair<char, int>('h', 8));

			std::map<char, int> result = map1 + map2;
			assert(expected.size() == result.size());
			auto expected_iter = expected.begin();
			for (auto iter = result.begin(); iter != result.end(); ++iter)
			{
				assert(*iter == *expected_iter++);
			}

		}

		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "TEST FOR ::map_operator+()" << std::endl;
		std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	}
}

int main()
{
	TEST_ConvertVectorsToMap();
	TEST_GetKeysAndGetValues();
	TEST_Reverse();
	TEST_operator_plus();
	
	{
		std::vector<int> v = { 1, 2, 3, 4 };
		std::cout << v << std::endl;
		
		std::map<char, int> map;
		map.insert(std::pair<char, int>('a', 1));
		map.insert(std::pair<char, int>('b', 2));
		map.insert(std::pair<char, int>('c', 3));
		map.insert(std::pair<char, int>('d', 4));
		map.insert(std::pair<char, int>('e', 5));

		std::cout << map << std::endl;
	}



	system("pause");

	return 0;
}
