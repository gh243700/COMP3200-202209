#include <iostream>
#include "Lab6.h"
#include <cassert>
#include <limits>

using namespace std;
using namespace lab6;

int main()
{
	vector<int> v = { 3, 4, 1, 3, 2, 5, 7, 9, 0, -3, 12, -6, 5};

	assert(Sum(v) == 42);
	assert(Max(v) == 12);
	assert(Min(v) == -6);
	float a = Average(v);
	assert(abs(Average(v) - 3.230769231) <= numeric_limits<float>::epsilon());
	vector<int> expected = { 12, 9, 7, 5, 5, 4, 3, 3, 2, 1, 0, -3, -6 };
	SortDescending(v);


	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		int i = iter - v.begin();
		assert(*iter == expected[iter - v.begin()]);
	}
	assert(NumberWithMaxOccurrence(v) == 5 || NumberWithMaxOccurrence(v) == 3);

	cout << INT_MIN;

	cout << "END_OF TEST" << endl;
	system("pause");
}