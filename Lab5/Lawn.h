#pragma once
#include "eGrassType.h"
#include "cmath"

namespace lab5
{
	class Lawn
	{
	public:


		Lawn();
		Lawn(const Lawn& other);

		virtual void operator=(const Lawn& other);
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;

	protected :
		const double FENCE_LENGTH = 0.25f;
	private :
		const double GRASS_AREA = 0.3f;
	};
}