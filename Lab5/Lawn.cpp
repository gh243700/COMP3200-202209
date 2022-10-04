#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	Lawn::Lawn(const Lawn& other)
	{

	}
	
	void Lawn::operator=(const Lawn& other)
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		float priceOfGrass;
		switch (grassType)
		{
		case lab5::BERMUDA: 
			priceOfGrass = 8.0f;
			break;
		case lab5::BAHIA:
			priceOfGrass = 5.0f;
			break;
		case lab5::BENTGRASS:
			priceOfGrass = 3.0f;
			break;
		case lab5::PERENNIAL_RYEGRASS:
			priceOfGrass = 2.5f;
			break;
		case lab5::ST_AUGUSTINE:
			priceOfGrass = 4.5f;
			break;
		default:
			priceOfGrass = 0.0f;
			break;
		}

		return static_cast<unsigned int>(priceOfGrass * GetArea() + 0.5f);
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return static_cast<unsigned int>(GetArea() / GRASS_AREA + 0.9);
	}
}