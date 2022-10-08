#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "ISailable.h"
 

namespace assignment2
{
	class Boatplane : public Vehicle, IFlyable, ISailable
	{
	public:
		friend class Airplane;
		friend class Boat;
		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		bool IsMoveable() const;
	};
}