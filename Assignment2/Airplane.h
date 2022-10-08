#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "Boat.h"
#include "Boatplane.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boatplane;
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
		friend class Boat;
		friend class Boatplane;
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetDriveSpeed() const;

		Boatplane operator+(Boat& boat);
		bool IsMoveable() const;
	};
}
