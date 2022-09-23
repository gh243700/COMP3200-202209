#include "TimeSheet.h"

#include <cassert>
#include <iostream>

using namespace std;
void TestCopyConstructor();
void TestAssignmentOperator();

int main()
{
	lab3::TimeSheet p("Pope", 10);

	p.AddTime(4);
	p.AddTime(7);
	p.AddTime(6);
	p.AddTime(5);
	p.AddTime(1);
	p.AddTime(2);
	std::cout << "Employee: " << p.GetName() << " / AverageTime: " << p.GetAverageTime() << " / TotalTime: " << p.GetTotalTime() << "/ sd : " << p.GetStandardDeviation() << std::endl;

	lab3::TimeSheet t = p;

	TestCopyConstructor();
	TestAssignmentOperator();
	system("pause");
}

void TestCopyConstructor()
{
	lab3::TimeSheet m("mong", 5);
	m.AddTime(1);
	m.AddTime(2);
	m.AddTime(3);

	lab3::TimeSheet m2 = m;

	assert(m.GetName() == m2.GetName());
	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) == m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() == m2.GetTotalTime());
	assert(m.GetAverageTime() == m2.GetAverageTime());
	assert(m.GetStandardDeviation() == m2.GetStandardDeviation());

	m.AddTime(4);

	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) != m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() != m2.GetTotalTime());
	assert(m.GetAverageTime() != m2.GetAverageTime());
	assert(m.GetStandardDeviation() != m2.GetStandardDeviation());

	m2.AddTime(5);

	assert(m.GetTimeEntry(0) == m2.GetTimeEntry(0));
	assert(m.GetTimeEntry(1) == m2.GetTimeEntry(1));
	assert(m.GetTimeEntry(2) == m2.GetTimeEntry(2));
	assert(m.GetTimeEntry(3) != m2.GetTimeEntry(3));
	assert(m.GetTimeEntry(4) == m2.GetTimeEntry(4));
	assert(m.GetTotalTime() != m2.GetTotalTime());
	assert(m.GetAverageTime() != m2.GetAverageTime());
	assert(m.GetStandardDeviation() != m2.GetStandardDeviation());
}

void TestAssignmentOperator()
{
	lab3::TimeSheet m("mong", 3);
	m.AddTime(1);
	m.AddTime(2);
	m.AddTime(3);

	lab3::TimeSheet s("shell", 5);
	s.AddTime(2);
	s.AddTime(4);
	s.AddTime(6);
	s.AddTime(8);
	s.AddTime(10);

	assert(m.GetName() == "mong");
	assert(m.GetTimeEntry(0) == 1);
	assert(m.GetTimeEntry(1) == 2);
	assert(m.GetTimeEntry(2) == 3);
	assert(m.GetTimeEntry(3) == -1);
	assert(m.GetTimeEntry(4) == -1);

	m = m;

	assert(m.GetName() == "mong");
	assert(m.GetTimeEntry(0) == 1);
	assert(m.GetTimeEntry(1) == 2);
	assert(m.GetTimeEntry(2) == 3);
	assert(m.GetTimeEntry(3) == -1);
	assert(m.GetTimeEntry(4) == -1);

	m = s;

	assert(m.GetName() == "shell");
	assert(m.GetTimeEntry(0) == 2);
	assert(m.GetTimeEntry(1) == 4);
	assert(m.GetTimeEntry(2) == 6);
	assert(m.GetTimeEntry(3) == 8);
	assert(m.GetTimeEntry(4) == 10);
}
