#include <cstring>
#include <cmath>
#include <limits>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX);
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX);
		operator=(other);
	}

	void PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return;
		}

		mCount = other.mCount;

		for (unsigned int i = 0; i < mCount; i++)
		{
			mPoints[i] = new Point(*other.mPoints[i]);
		}
	}

	PolyLine::~PolyLine()
	{
		const Point** pp = mPoints;
		for (unsigned int i = 0; i < mCount; i++)
		{
			delete *pp;
			pp++;
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount >= MAX)
		{
			return false;
		}

		return AddPoint(new Point(x, y));
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mCount >= MAX)
		{
			return false;
		}

		mPoints[mCount++] = point;
		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount || i < 0) 
		{
			return false;
		}

		delete mPoints[i];
		for (int index = i; i < mCount - 1; i++) 
		{
			mPoints[i] = mPoints[i + 1];
		}
		mPoints[--mCount] = NULL;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount <= 0)
		{
			return false;
		}
		const Point* p = mPoints[0];
		float minX = p->GetX();
		float maxX = p->GetX();
		float minY = p->GetY();
		float maxY = p->GetY();

		for (unsigned int i = 0; i < mCount; i++)
		{
			p = mPoints[i];
			float x = p->GetX();
			float y = p->GetY();
			minX = std::min(minX, x);
			maxX = std::max(maxX, x);
			minY = std::min(minY, y);
			maxY = std::max(maxY, y);
		}

		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return true;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < 0 || i >= mCount)
		{
			return NULL;
		}
		return mPoints[i];
	}
}