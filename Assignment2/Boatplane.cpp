#include "Boatplane.h"
#include <cmath>

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{

	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		return flySpeed > sailSpeed ? flySpeed : sailSpeed;
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(150 * std::exp((-static_cast<int>(GetPassengersWeight()) + 500) / 300.0) + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		double speed = 800 - 1.7 * GetPassengersWeight() + 0.5;
		if (speed > 20)
		{
			return static_cast<unsigned int>(speed);
		}

		return 20;
	}

	bool Boatplane::IsMoveable() const
	{
		return mTurn % 4 == 0;
	}
}