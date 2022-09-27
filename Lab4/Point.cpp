#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mX(x) 
		, mY(y)
	{
	}

	Point::~Point()
	{
	}

	Point::Point(const Point& other) 
		: Point::Point(other.mX, other.mY)
	{
	}
	
	void Point::operator=(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;
	}

	bool Point::operator==(const Point& other) const 
	{
		return mX == other.mX && mY == other.mY;
	}

	Point Point::operator+(const Point& other) const
	{
		return Point(mX + other.mX, mY + other.mY);
	}

	Point Point::operator-(const Point& other) const
	{
		return Point(mX - other.mX, mY - other.mY);
	}

	float Point::Dot(const Point& other) const
	{
		return mX * other.mX + mY * other.mY;
	}

	Point Point::operator*(float operand) const
	{
		return Point(mX * operand, mY * operand);
	}

	Point operator*(float operand, const Point& point)
	{
		return Point(operand * point.mX, operand * point.mY);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}
}