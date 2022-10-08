#pragma once

#include "Vehicle.h"
#include "ISailable.h"
#include "Airplane.h"
#include "Boatplane.h"

namespace assignment2
{
	class Airplane;
	class Boatplane;

	class Boat : public Vehicle, public ISailable
	{
		friend class Airplane;
		friend class BBoatplane;
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;

		Boatplane operator+(Airplane& plane);

		bool IsMoveable() const;
	};
}