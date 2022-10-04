#pragma once
#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int halfRadius);
		CircleLawn(const CircleLawn& other);
		void operator=(const CircleLawn& other);

		~CircleLawn();

		unsigned int GetArea() const;

	private:
		unsigned int mHalfRadius;
		const double PI = 3.14;
	};

}
	