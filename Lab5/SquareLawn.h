#pragma once

#include "RectangleLawn.h"

namespace lab5
{
	class SquareLawn : public RectangleLawn
	{
	public:
		SquareLawn(unsigned int width);
		SquareLawn(const SquareLawn& other);
		void operator=(const SquareLawn& other);
	private:
	};
}