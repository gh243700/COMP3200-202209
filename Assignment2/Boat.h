#pragma once

#include "Vehicle.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;
	class Boatplane;

	class Boat : public Vehicle, public ISailable
	{
		friend class Airplane;
	public:
		Boat(unsigned int maxPassengersCount);
		~Boat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;

		Boatplane operator+(Airplane& plane);

		bool IsMoveable() const;
	};
}