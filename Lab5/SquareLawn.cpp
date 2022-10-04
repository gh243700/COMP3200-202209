#include "SquareLawn.h"

namespace lab5
{
	SquareLawn::SquareLawn(unsigned int width)
		: RectangleLawn(width, width)
	{
	}

	SquareLawn::SquareLawn(const SquareLawn& other)
		: SquareLawn(other.mWidth)
	{
	}

	void SquareLawn::operator=(const SquareLawn& other)
	{
		RectangleLawn::operator=(other);
	}
}
