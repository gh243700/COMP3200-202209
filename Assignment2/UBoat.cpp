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
		int v = static_cast<int>(550 - GetPassengersWeight() / 10.0 + 0.5);		
		return (v > 200) ? v : 200;
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		return static_cast<unsigned int>(500 * log10((GetPassengersWeight() + 150) / 150.0) + 30.5);
	}

	bool UBoat::IsMoveable() const
	{
		return mTurn % 6 == 0 || mTurn % 6 == 1;
	}
}