#pragma once

#include "Airplane.h"
#include "IFlyable.h"
#include "ISailable.h"
 

namespace assignment2
{
	class Boatplane : public Boat, public IFlyable
	{
	public:

		Boatplane(unsigned int maxPassengersCount);
		~Boatplane();

		unsigned int GetMaxSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetSailSpeed() const;
		bool IsMoveable() const;
	};
}