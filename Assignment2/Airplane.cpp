#include "Airplane.h"
#include "cmath"
#include "Boatplane.h"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int v1 = GetFlySpeed();
		unsigned int v2 = GetDriveSpeed();
		return v1 > v2 ? v1 : v2;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(200 * std::exp((-1 * static_cast<int>(GetPassengersWeight()) + 800.0) / 500.0) + 0.5);
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		return static_cast<unsigned int>(4 * std::exp((-static_cast<int>(GetPassengersWeight()) + 400) / 70.0) + 0.5);
	}


	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane bp(GetMaxPassengersCount() + boat.GetMaxPassengersCount());
		bp.mIndex = mIndex + boat.mIndex;
		memcpy(bp.mPassengers, mPassengers, sizeof(Person*) * mIndex);
		memset(mPassengers, 0, sizeof(Person*) * mIndex);

		memcpy(bp.mPassengers + mIndex, boat.mPassengers, sizeof(Person*) * boat.mIndex);
		memset(boat.mPassengers, 0, sizeof(Person*) * boat.mIndex);
		mIndex = 0;
		boat.mIndex = 0;

		return bp;
	}

	bool Airplane::IsMoveable() const
	{
		return mTurn % 4 == 0;
	}
}