#include "Lab6.h"
#include <limits>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		{
			sum += *iter;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() <= 0)
		{
			return INT32_MAX;;
		}

		int min = *v.begin();

		for (std::vector<int>::const_iterator iter = v.begin() + 1; iter != v.end(); iter++)
		{
			if (min > *iter)
			{
				min = *iter;
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() <= 0)
		{
			return INT32_MIN;
		}

		int max = *v.begin();

		for (std::vector<int>::const_iterator iter = v.begin() + 1; iter != v.end(); iter++)
		{
			if (max < *iter)
			{
				max = *iter;
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() <= 0)
		{
			return 0.0f;
		}

		return Sum(v) / static_cast<float>(v.size());
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() <= 0)
		{
			return 0;
		}

		std::vector<int> copy = v;
		SortDescending(copy);

		unsigned int maxCount = 1;
		int maxValue = *copy.begin();

		unsigned int tempCount = maxCount;
		int tempValue = maxValue;
		for (std::vector<int>::iterator iter = copy.begin() + 1; iter != copy.end(); iter++)
		{
			if ((tempValue != *iter || iter == copy.end() - 1))		
			{
				if (maxCount < tempCount)
				{
					maxValue = tempValue;
					maxCount = tempCount;
				}

				tempCount = 0;
				tempValue = *iter;
			}

			tempCount++;
		}

		return maxValue;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (std::vector<int>::iterator j = v.begin(); j != v.end(); j++)
		{
			for (std::vector<int>::iterator i = j + 1; i != v.end(); i++)
			{
				if (*j < *i)
				{
					int temp = *j;
					*j = *i;
					*i = temp;
				}
			}
		}

	}
}