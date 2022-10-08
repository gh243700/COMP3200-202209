#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(MAX)
	{
	}

	UBoat::~UBoat()
	{
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed = GetSailSpeed();
		unsigned int diveSpeed = GetDiveSpeed();

		return (sailSpeed > diveSpeed) ? sailSpeed : diveSpeed;
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		double v = 550 - GetPassengersWeight() / 10.0 + 0.5;

		if (v > 200)
		{
			return static_cast<unsigned int>(v);
		}

		return 200;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		double result = 500 * log10((GetPassengersWeight() + 150) / 150.0) + 30.5;

		return static_cast<unsigned int>(result);
	}

	bool UBoat::IsMoveable() const
	{
		return mTurn % 6 == 0 || mTurn % 6 == 1;
	}
}