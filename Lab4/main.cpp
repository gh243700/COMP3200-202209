#include "Point.h"
#include "PolyLine.h"
#include <iostream>
#include <cassert>

using namespace lab4;

void TEST1() 
{
	Point p1(0, 0);
	Point p2(1, 2);
	Point p3 = p1 + p2;

	assert(p1 == Point(0, 0));
	assert(p2 == Point(1, 2));
	assert(p3 == Point(1, 2));
}

void TEST2() 
{
	Point p1(0, 0);
	Point p2(1, 2);
	Point p3 = p1 - p2;

	assert(p1 == Point(0, 0));
	assert(p2 == Point(1, 2));
	assert(p3 == Point(-1, -2));
}

void TEST3() 
{
	Point p1(1.0f, 2.0f);
	Point p2(1.0f, 4.0f);

	float dotProduct = p1.Dot(p2); // dotProduct는 9.0f
	assert(dotProduct == 9.0f);
}

void TEST4()
{
	Point p1(1.2f, 2.5f);

	Point p2 = p1 * 4.0f; // p2는 [4.8f, 10.0f]
	assert(p2 == Point(4.8f, 10.0f));
	Point p3 = 5.0f * p1; // p3는 [6.0f, 12.5f]
	assert(p3 == Point(6.0f, 12.5f));
}

void TEST5() 
{
	PolyLine pl;
	bool b;
	b = pl.AddPoint(1.0f, 2.0f);
	assert(b == true);
	b = pl.AddPoint(new Point(2.0f, 3.0f));
	assert(b == true);
	b = pl.AddPoint(2.2f, 1.9f); // pl은 [1.0f, 2.0f], [2.0f, 3.0f], [2.2f, 1.9f]
	assert(b == true);
	b = pl.AddPoint(5.2f, 8.9f);
	assert(b == true);
	b = pl.AddPoint(2.2f, 1.4f);
	assert(b == true);
	b = pl.AddPoint(10.1f, 11.9f);
	assert(b == true);
	b = pl.AddPoint(7.5f, 1.9f);
	assert(b == true);
	b = pl.AddPoint(6.6f, 4.5f);
	assert(b == true);
	b = pl.AddPoint(3.1f, 0.9f);
	assert(b == true);
	b = pl.AddPoint(0.1f, 0.1f); // 10번째 점. 이때까지 AddPoint()는 true를 반환.
	assert(b == true);
	b = pl.AddPoint(2.2f, 1.9f); // 11번째 점 추가 시도. AddPoint()는 false를 반환하고 이 점을 PolyLine 개체에 추가하지 않아야 함.
	assert(b == false);
}


void TEST6()
{
	PolyLine pl;
	pl.AddPoint(1.4f, 2.8f);
	pl.AddPoint(3.7f, 2.5f);
	pl.AddPoint(5.5f, 5.5f);
	pl.AddPoint(-2.9f, 4.1f);
	pl.AddPoint(4.3f, -1.0f);
	pl.AddPoint(6.2f, 4.4f);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);
	pl.TryGetMinBoundingRectangle(&minP, &maxP); // min: [-2.9f, -1.0f], max: [6.2f, 5.5f]

	Point expectedMin(-2.9f, -1.0f);
	Point expectedMax(6.2f, 5.5f);
	assert(minP == expectedMin && maxP == expectedMax);
}

void TEST7()
{
	const double EPSILON = 0.0009765625;

	Point p1(2, 3);
	Point p2(-1, 4);

	Point p3 = p1 + p2;

	assert(std::abs(p3.GetX() - 1) <= EPSILON);
	assert(std::abs(p3.GetY() - 7) <= EPSILON);

	Point p4 = p2 - p1;

	assert(std::abs(p4.GetX() - (-3)) <= EPSILON);
	assert(std::abs(p4.GetY() - 1) <= EPSILON);

	float dotProduct = p1.Dot(p2);

	assert(std::abs(dotProduct - 10) <= EPSILON);

	Point p5 = p1 * 5;

	assert(std::abs(p5.GetX() - 10) <= EPSILON);
	assert(std::abs(p5.GetY() - 15) <= EPSILON);

	Point p6 = 2 * p2;

	assert(std::abs(p6.GetX() - (-2)) <= EPSILON);
	assert(std::abs(p6.GetY() - 8) <= EPSILON);

	/* ----------------------- */

	PolyLine pl1;
	pl1.AddPoint(1, 2);
	pl1.AddPoint(3, 2);
	pl1.AddPoint(5, 5);
	pl1.AddPoint(-2, 4);
	pl1.AddPoint(4, -1);
	pl1.AddPoint(6, 4);

	bool bRemoved = pl1.RemovePoint(4);

	assert(bRemoved);

	Point minP(0.f, 0.f);
	Point maxP(0.f, 0.f);

	pl1.TryGetMinBoundingRectangle(&minP, &maxP);

	assert(minP.GetX() == -2);
	assert(minP.GetY() == 2);
	assert(maxP.GetX() == 6);
	assert(maxP.GetY() == 5);

}

int main()
{

	TEST1();
	TEST2();
	TEST3();
	TEST4();
	TEST5();
	TEST6();
	TEST7();
	std::cout << "END\n" << std::endl;
	system("pause");
}
