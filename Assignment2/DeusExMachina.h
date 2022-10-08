#pragma once

#include "Vehicle.h"

namespace assignment2
{
	
	class DeusExMachina
	{
	public:
		~DeusExMachina();
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		
		Vehicle* GetVehicle(unsigned int i) const;
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
	private :
		static DeusExMachina* S_DEUS_EX_MACHINA;
		DeusExMachina();
		DeusExMachina(const DeusExMachina& other);
		void operator=(const DeusExMachina& other);
		enum {MAX = 10};
		Vehicle* mVehicles[MAX];
		unsigned int mIndex;
	};
}