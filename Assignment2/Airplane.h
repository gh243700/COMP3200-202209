#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "Boat.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boatplane;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
		friend class Boat;

	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		virtual unsigned int GetMaxSpeed() const;
		virtual unsigned int GetFlySpeed() const;
		virtual unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);
		bool IsMoveable() const;
	};
}
