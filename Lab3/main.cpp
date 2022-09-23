#include "TimeSheet.h";
#include <cassert>
#include <iostream>

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

	system("pause");
}