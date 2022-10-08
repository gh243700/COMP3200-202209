#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, ISailable, IDivable
	{
	public:
		UBoat();
		~UBoat();

		unsigned int GetMaxSpeed() const;
		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;
	
		bool IsMoveable() const;

	private:
		enum {MAX = 50};
	};
}