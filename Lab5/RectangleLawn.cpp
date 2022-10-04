#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	RectangleLawn::RectangleLawn(const RectangleLawn& other)
		: RectangleLawn(other.mWidth, other.mHeight)
	{

	}

	void RectangleLawn::operator=(const RectangleLawn& other)
	{
		mWidth = other.mWidth;
		mHeight = other.mHeight;
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return static_cast<unsigned int>(2 * (mWidth + mHeight)
			/ 0.25f + 0.5f);
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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