#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mDeusExMachina = NULL;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mDeusExMachina != NULL)
		{
			return mDeusExMachina;
		}

		mDeusExMachina = new DeusExMachina();

		return mDeusExMachina;
	}


	DeusExMachina::~DeusExMachina()
	{
		for (unsigned int i = 0; i < mIndex; i++)
		{
			if (mVehicles[i] != NULL)
			{
				delete mVehicles[i];
			}
		}
		mDeusExMachina = NULL;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mIndex; i++)
		{
			mVehicles[i]->Move();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (mIndex >= MAX)
		{
			return false;
		}

		vehicle->ResetMove();

		mVehicles[mIndex++] = vehicle;

		return true;
	}

	Vehicle* DeusExMachina::GetVehicle(unsigned int i) const
	{
		return mVehicles[i];
	}


	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i < 0 || i >= mIndex)
		{
			return false;
		}

		delete mVehicles[i];

		for (unsigned int index = i; index < mIndex - 1; index++)
		{
			mVehicles[index] = mVehicles[index + 1];
		}

		mVehicles[--mIndex] = NULL;
		return true;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mIndex < 1)
		{
			return NULL;
		}

		Vehicle* result = mVehicles[0];
		for (unsigned int i = 0; i < mIndex - 1; i++)
		{
			Vehicle* v = mVehicles[i + 1];
			if (result->GetTraveledDistance() < v->GetTraveledDistance())
			{
				result = v;
			}
		}
		return result;
	}

	DeusExMachina::DeusExMachina()
		: mIndex(0)
	{
		memset(mVehicles, 0, sizeof(Vehicle*) * MAX);
	}
}