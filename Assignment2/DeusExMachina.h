#pragma once

#include "Vehicle.h"

namespace assignment2
{
	
	class DeusExMachina
	{
	public:
		DeusExMachina(const DeusExMachina& other) = delete;
		void operator=(const DeusExMachina& other) = delete;
		~DeusExMachina();

		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		
		Vehicle* GetVehicle(unsigned int i) const;
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private :
		static DeusExMachina* mDeusExMachina;
		DeusExMachina();
		enum {MAX = 10};
		Vehicle* mVehicles[MAX];
		unsigned int mIndex;
	};
}