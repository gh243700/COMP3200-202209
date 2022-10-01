#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mPassengers(new const Person* [maxPassengersCount + 1])
		, mMaxPassengersCount(maxPassengersCount)
		, mIndex(0)
	{
		memset(mPassengers, 0, sizeof(Person*) * mMaxPassengersCount);
		mPassengers[mMaxPassengersCount] = NULL;
	}

	Vehicle::Vehicle(const Vehicle& other)
		: mPassengers(new const Person* [other.mMaxPassengersCount + 1])
		, mMaxPassengersCount(other.mMaxPassengersCount)
		, mIndex(other.mIndex)
	{
		const Person** ppm = mPassengers;
		const Person** oppm = other.mPassengers;

		while (*oppm != NULL)
		{
			*ppm = new Person(*oppm[0]);
			ppm++;
			oppm++;
		}
		mPassengers[mMaxPassengersCount] = NULL;
	}

	void Vehicle::operator=(const Vehicle& other)
	{
		const Person** ppm = mPassengers;
		while (*ppm != NULL)
		{
			delete* mPassengers;
			ppm++;
		}
		delete[] mPassengers;

		mIndex = other.mIndex;
		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengers = new const Person* [mMaxPassengersCount];
		ppm = mPassengers;

		const Person** oppm = other.mPassengers;
		while(*oppm != NULL)
		{
			*ppm = new Person(*oppm[0]);
			oppm++;
			ppm++;
		}
	}

	Vehicle::~Vehicle()
	{
		const Person** mPassengersPtr = mPassengers;
		while (*mPassengersPtr != NULL)
		{
			delete *mPassengers;
			mPassengersPtr++;
		}
		delete[] mPassengers;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (mIndex >= mMaxPassengersCount)
		{
			return false;
		}

		mPassengers[mIndex] = person;
		mIndex++;
		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i < 0 || i >= mIndex)
		{
			return false;
		}

		delete mPassengers[i];
		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mIndex;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxPassengersCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < 0 || i >= mIndex)
		{
			return NULL;
		}

		return mPassengers[i];
	}
}