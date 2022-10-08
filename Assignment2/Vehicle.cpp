#include "Vehicle.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxPassengersCount(maxPassengersCount)
		, mIndex(0)
		, mTravelledDistance(0)
		, mTurn(0)
	{
		mPassengers = new const Person * [maxPassengersCount + 1];

		memset(mPassengers, 0, sizeof(Person*) * mMaxPassengersCount);
		mPassengers[mMaxPassengersCount] = NULL;
	}

	Vehicle::Vehicle(Vehicle& other)
		: mMaxPassengersCount(other.mMaxPassengersCount)
		, mIndex(other.mIndex)
		, mTravelledDistance(other.mTravelledDistance)
		, mTurn(other.mTurn)
	{
		mPassengers = new const Person * [other.mMaxPassengersCount + 1];
		const Person** ppm = mPassengers;
		const Person** oppm = other.mPassengers;

		while (*oppm != NULL)
		{
			*ppm = *oppm;
			*oppm = NULL;
			ppm++;
			oppm++;
		}
		mPassengers[mMaxPassengersCount] = NULL;
		other.mIndex = 0;
	}

	void Vehicle::operator=(Vehicle& other)
	{
		const Person** ppm = mPassengers;
		while (*ppm != NULL)
		{
			delete* mPassengers;
			ppm++;
		}
		delete[] mPassengers;
		mTravelledDistance = other.mTravelledDistance;
		mTurn = other.mTurn;
		mIndex = other.mIndex;
		mMaxPassengersCount = other.mMaxPassengersCount;
		mPassengers = new const Person* [mMaxPassengersCount + 1];
		mPassengers[mMaxPassengersCount] = NULL;
		ppm = mPassengers;

		const Person** oppm = other.mPassengers;
		while(*oppm != NULL)
		{
			*ppm = *oppm;
			*oppm = NULL;
			oppm++;
			ppm++;
		}
		other.mIndex = 0;
	}

	Vehicle::~Vehicle()
	{
		const Person** mPassengersPtr = mPassengers;
		while (*mPassengersPtr != NULL)
		{
			delete * mPassengersPtr;
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

		for (int index = i; i < mIndex - 1; i++)
		{
			mPassengers[i] = mPassengers[i + 1];
		}
		mPassengers[--mIndex] = NULL;
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

	unsigned int Vehicle::GetPassengersWeight() const
	{
		unsigned int totalWeight = 0;
		for (unsigned int i = 0; i < mIndex; i++)
		{
			totalWeight += mPassengers[i]->GetWeight();
		}

		return totalWeight;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < 0 || i >= mIndex)
		{
			return NULL;
		}

		return mPassengers[i];
	}

	void Vehicle::Move()
	{
		if (IsMoveable())
		{
			mTravelledDistance += GetMaxSpeed();
		}
		mTurn++;
	}

	void Vehicle::ResetMove()
	{
		mTurn = 0;
		mTravelledDistance = 0;
	}

	unsigned int Vehicle::GetTraveledDistance() const
	{
		return mTravelledDistance;
	}
}