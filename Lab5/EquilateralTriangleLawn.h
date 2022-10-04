#pragma once

#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class EquilateralTriangleLawn : public Lawn, IFenceable
	{
	public:
		EquilateralTriangleLawn(unsigned int side);
		EquilateralTriangleLawn(const EquilateralTriangleLawn& other);
		void operator=(const EquilateralTriangleLawn& other);
		~EquilateralTriangleLawn();

		unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;

	private:
		unsigned int mSide;
	};
}