#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(MAX)
	{
		mTrailer = NULL;
	}
	Sedan::Sedan(Sedan& other)
		: Sedan()
	{
		mTrailer = NULL;
		Vehicle::operator=(other);
		mTrailer = new Trailer(other.mTrailer->GetWeight());
	}

	void Sedan::operator=(Sedan& other)
	{
		if (this == &other)
		{
			return;
		}

		if (mTrailer != NULL)
		{
			delete mTrailer;
		}
		
		mTrailer = NULL;
		Vehicle::operator=(other);
		
		if (other.mTrailer != NULL)
		{
			mTrailer = new Trailer(other.mTrailer->GetWeight());
		}
	}

	Sedan::~Sedan()
	{
		if (mTrailer != NULL)
		{
			delete mTrailer;
		}
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int x = GetPassengersWeight() + ((mTrailer != NULL) ? mTrailer->GetWeight() : 0);
		unsigned int speed;

		if (x > 350)
		{
			speed = 300;
		}
		else if (x > 260)
		{
			speed = 380;
		}
		else if (x > 160)
		{
			speed = 400;
		}
		else if (x > 80)
		{
			speed = 458;
		}
		else 
		{
			speed = 480;
		}

		return speed;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTrailer != NULL)
		{
			return false;
		}

		mTrailer = trailer;
		return true;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTrailer == NULL)
		{
			return false;
		}

		delete mTrailer;
		mTrailer = NULL;

		return true;
	}

	bool Sedan::IsMoveable() const
	{
		
		if (mTrailer == NULL)
		{
			return mTurn % 6 != 5;
		} 
		
		return mTurn % 7 != 5 && mTurn % 7 != 6;
	}
}