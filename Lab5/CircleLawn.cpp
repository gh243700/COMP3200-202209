#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int halfRadius)
		: mHalfRadius(halfRadius)
	{
	}

	CircleLawn::CircleLawn(const CircleLawn& other)
		: CircleLawn(other.mHalfRadius)
	{
	}

	void CircleLawn::operator=(const CircleLawn& other)
	{
		mHalfRadius = other.mHalfRadius;
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return static_cast<unsigned int>(std::pow(mHalfRadius, 2) * PI + 0.5);
	}
}