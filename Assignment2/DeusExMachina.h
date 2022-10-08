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
		DeusExMachina();
		DeusExMachina(const DeusExMachina& other);
		void operator=(const DeusExMachina& other);
		static DeusExMachina* DEUS_EX_MACHINA;
		enum {MAX = 10};
		Vehicle* mVehicles[MAX];
		unsigned int mIndex;
	};
}