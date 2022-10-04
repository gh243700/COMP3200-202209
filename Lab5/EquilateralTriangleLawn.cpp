#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int side)
		: mSide(side)
	{
	}

	EquilateralTriangleLawn::EquilateralTriangleLawn(const EquilateralTriangleLawn& other)
		: EquilateralTriangleLawn(other.mSide)
	{
	}
	
	void EquilateralTriangleLawn::operator=(const EquilateralTriangleLawn& other)
	{
		mSide = other.mSide;
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		return static_cast<unsigned int>(std::sqrt(std::pow(mSide, 2) - std::pow(mSide / 2.0f, 2)) * mSide / 2.0f + 0.5f);
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return static_cast<unsigned int>(mSide * 3.0 / FENCE_LENGTH + 0.5);
	}
	
	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int fencePrice;

		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			fencePrice = 6;
			break;
		case lab5::SPRUCE:
			fencePrice = 7;
			break;
		default:
			fencePrice = 0;
			break;
		}

		return GetMinimumFencesCount() / 4 * fencePrice;
	}
}