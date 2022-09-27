#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{
		memset(mPoints, 0, sizeof(Point*) * MAX);
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mCount(other.mCount)
	{
		for (int i = 0; i < MAX; i++)
		{
			if (other.mPoints[i] != NULL)
			{
				mPoints[i] = new Point(*other.mPoints[i]);
			}
			else
			{
				mPoints[i] = NULL;
			}
		}
	}

	PolyLine::~PolyLine()
	{
		const Point** pp = mPoints;
		for (int i = 0; i < MAX; i++)
		{
			if (*pp != NULL)
			{
				delete* pp;
			}
			pp++;
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		return AddPoint(new Point(x, y));
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		for (int i = 0; i < MAX; i++)
		{
			if (mPoints[i] == NULL)
			{
				mPoints[i] = point;
				mCount++;
				return true;
			}
		}

		return false;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i >= mCount || mPoints[i] != NULL)
		{
			delete mPoints[i];
			mPoints[i] = NULL;
			mCount--;
			return true;
		}
		return false;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		const Point* p;
		float minX = FLT_MAX;
		float maxX = FLT_MIN;
		float minY = FLT_MAX;
		float maxY = FLT_MIN;

		for (int i = 0; i < MAX - 1; i++)
		{
			const Point* p = mPoints[i + 1];
			if (p == NULL)
			{
				continue;
			}
			float x = p->GetX();
			float y = p->GetY();
			minX = std::min(minX, x);
			maxX = std::max(maxX, x);
			minY = std::min(minY, y);
			maxY = std::max(maxY, y);
		}

		*outMin = Point(minX, minY);
		*outMax = Point(maxX, maxY);

		return minX != maxX && minY != maxY;
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i >= mCount)
		{
			return NULL;
		}
		return mPoints[i];
	}
}