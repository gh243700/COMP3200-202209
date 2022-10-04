#pragma once
#include "Lawn.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, IFenceable
	{
	public :
		RectangleLawn(unsigned int width, unsigned int height);

		~RectangleLawn();
		RectangleLawn(const RectangleLawn& other);
		void operator=(const RectangleLawn& other);

		unsigned int GetArea() const;

		unsigned int GetMinimumFencesCount() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
	protected : 
		unsigned int mWidth;
		unsigned int mHeight;

	};
}