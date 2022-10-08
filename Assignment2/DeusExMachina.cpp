#include "DeusExMachina.h"

namespace assignment2
{
	DeusExMachina* DeusExMachina::S_DEUS_EX_MACHINA = NULL;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (S_DEUS_EX_MACHINA != NULL)
		{
			return S_DEUS_EX_MACHINA;
		}

		S_DEUS_EX_MACHINA = new DeusExMachina();

		return S_DEUS_EX_MACHINA;
	}


	DeusExMachina::~DeusExMachina()
	{
		
		for (int i = 0; i < mIndex; i++)
		{
			if (mVehicles[i] != NULL)
			{
				delete mVehicles[i];
			}
		}

		S_DEUS_EX_MACHINA = NULL;
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

		for (int index = i; i < mIndex - 1; i++)
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
			if (result->GetTraveledDistance() < mVehicles[i]->GetTraveledDistance())
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

	DeusExMachina::DeusExMachina(const DeusExMachina& other)
		: mIndex(other.mIndex)
	{
		memcpy(mVehicles, other.mVehicles, sizeof(Vehicle*) * MAX);
	}

	void DeusExMachina::operator=(const DeusExMachina& other)
	{
		if (this == &other)
		{
			return;
		}

		mIndex = other.mIndex;
		memcpy(mVehicles, other.mVehicles, sizeof(Vehicle*) * MAX);
	}
}