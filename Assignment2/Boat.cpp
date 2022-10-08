#include "Boat.h"
#include <cmath>
#include "Boatplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	unsigned int Boat::GetSailSpeed() const
	{
		int speed = 800 - 10 * GetPassengersWeight();

		if (speed > 20)
		{
			return static_cast<unsigned int>(speed);
		}

		return 20;
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane bp(GetMaxPassengersCount() + plane.GetMaxPassengersCount());
		bp.mIndex = mIndex + plane.mIndex;
		memcpy(bp.mPassengers, plane.mPassengers, sizeof(Person*) * plane.mIndex);
		memset(plane.mPassengers, 0, sizeof(Person*) * plane.mIndex);

		memcpy(bp.mPassengers + plane.mIndex, mPassengers, sizeof(Person*) * mIndex);
		memset(mPassengers, 0, sizeof(Person*) * mIndex);
		mIndex = 0;
		plane.mIndex = 0;
		
		return bp;
	}

	bool Boat::IsMoveable() const
	{
		return mTurn % 3 != 2;
	}
}