#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(Vehicle& other);
		virtual void operator=(Vehicle& other);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0;

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;

		unsigned int GetPassengersWeight() const;
		virtual bool IsMoveable() const = 0;
		void Move();
		void ResetMove();
		unsigned int GetTraveledDistance() const;
	protected :
		const Person** mPassengers;
		unsigned int mMaxPassengersCount;
		unsigned int mIndex;
		unsigned int mTravelledDistance;
		unsigned int mTurn;  
	};
}