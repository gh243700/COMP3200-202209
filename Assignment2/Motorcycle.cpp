#include "Motorcycle.h"
#include <cmath>

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(MAX)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		unsigned int weight = GetPassengersWeight();
		double speed = -std::pow(weight / 15.0, 3) + 2 * weight + 400 + 0.5;

		if (speed > 0)
		{
			return static_cast<unsigned int>(speed);
		}

		return 0;
	}

	bool Motorcycle::IsMoveable() const
	{
		return mTurn % 6 != 5;
	}
}