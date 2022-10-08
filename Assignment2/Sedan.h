#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		Sedan(Sedan& other);
		void operator=(Sedan& other);
		
		~Sedan();
		
		unsigned int GetMaxSpeed() const;
		unsigned int GetDriveSpeed() const;
		
		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		bool IsMoveable() const;
	private:
		enum { MAX = 4 };
		const Trailer* mTrailer;
	};
}