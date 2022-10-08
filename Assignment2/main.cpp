#include "Person.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Boatplane.h"
#include "Motorcycle.h"
#include "Sedan.h"
#include "UBoat.h"
#include "DeusExMachina.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace assignment2;

void TestDeusExMachinaClass()
{
	DeusExMachina* deusExMachina1 = DeusExMachina::GetInstance();
	DeusExMachina* deusExMachina2 = DeusExMachina::GetInstance();

	deusExMachina1->Travel();


	bool bSame = deusExMachina1 == deusExMachina2; // true
	assert(bSame == true);


	Airplane* airplane = new Airplane(5);
	deusExMachina1->AddVehicle(airplane);
	Boat* boat = new Boat(5);
	deusExMachina1->AddVehicle(boat);
	Boatplane* boatplane = new Boatplane(5);
	deusExMachina1->AddVehicle(boatplane);
	Motorcycle* mortocycle = new Motorcycle();
	deusExMachina1->AddVehicle(mortocycle);
	Sedan* sedan0 = new Sedan();
	deusExMachina1->AddVehicle(sedan0);

	Sedan* sedan1 = new Sedan();
	sedan1->AddTrailer(new Trailer(50));

	deusExMachina1->AddVehicle(sedan1);
	UBoat* uBoat = new UBoat();
	deusExMachina1->AddVehicle(uBoat);


	assert(airplane->IsMoveable() == true);
	assert(boat->IsMoveable() == true);
	assert(boatplane->IsMoveable() == true);
	assert(mortocycle->IsMoveable() == true);
	assert(sedan0->IsMoveable() == true);
	assert(sedan1->IsMoveable() == true);
	assert(uBoat->IsMoveable() == true);

	deusExMachina1->Travel(); // 모든 운송 수단이 이동

	assert(airplane->IsMoveable() == false);
	assert(boat->IsMoveable() == true);
	assert(boatplane->IsMoveable() == false);
	assert(mortocycle->IsMoveable() == true);
	assert(sedan0->IsMoveable() == true);
	assert(sedan1->IsMoveable() == true);
	assert(uBoat->IsMoveable() == true);
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan, UBoat가 이동

	assert(airplane->IsMoveable() == false);
	assert(boat->IsMoveable() == false);
	assert(boatplane->IsMoveable() == false);
	assert(mortocycle->IsMoveable() == true);
	assert(sedan0->IsMoveable() == true);
	assert(sedan1->IsMoveable() == true);
	assert(uBoat->IsMoveable() == false);
	deusExMachina1->Travel(); // Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // UBoat만 빼고 모두 이동
	deusExMachina1->Travel(); // 어떤 운송 수단도 움직이지 않음
	deusExMachina1->Travel(); // Boat, Motorcycle, 트레일러 안 달린 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Boat Motorcycle, 두 Sedan, UBoat가 이동
	deusExMachina1->Travel(); // Airplane, Boatplane, Motorcycle, 두 Sedan 이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // Boat, Motorcycle, 두 Sedan이 이동
	deusExMachina1->Travel(); // 트레일러 달린 Sedan만 이동

	delete deusExMachina1;
}

void TestPersonClass()
{
	Person p0 = Person("name0", 90);
	Person expected("name0", 90);
	assert(p0 == expected);

	Person p1("test1", 100);
	p0 = p1;
	assert(p0 == p1);

	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestPersonClass()" << endl;
	cout << "-------------------------------------" << endl;
}

void TestUboatClass()
{
	Person* p1 = new Person("name1", 40);
	Person* p2 = new Person("name2", 60);
	Person* p3 = new Person("name3", 12);
	Person* p4 = new Person("name4", 1);
	Person* p5 = new Person("name5", 140);

	UBoat a;

	assert(a.AddPassenger(p1) == true); // true
	assert(a.AddPassenger(p2) == true); // true
	assert(a.AddPassenger(p3) == true); // true
	assert(a.AddPassenger(p4) == true); // true
	assert(a.AddPassenger(p5) == true); // true

	assert(a.GetPassengersWeight() == 253);

	assert(a.GetMaxSpeed() == 525);
	assert(a.GetSailSpeed() == 525);
	assert(a.GetDiveSpeed() == 245);

	//y	y	n	n	n	n	y	y	n	n	n	n	y


	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();


	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestUBoatClass()" << endl;
	cout << "-------------------------------------" << endl;
}

void TestSedanClass()
{
	{
		Person* p1 = new Person("name1", 40);
		Person* p2 = new Person("name2", 60);
		Person* p3 = new Person("name3", 12);
		Person* p4 = new Person("name4", 1);
		Person* p5 = new Person("name5", 140);

		Sedan a;

		assert(a.AddPassenger(p1) == true); // true
		assert(a.AddPassenger(p2) == true); // true
		assert(a.AddPassenger(p3) == true); // true
		assert(a.AddPassenger(p4) == true); // true
		assert(a.AddPassenger(p5) == false); // true;

		Trailer* t = new Trailer(40);

		assert(a.RemoveTrailer() == false);
		assert(a.AddTrailer(t) == true);
		assert(a.RemoveTrailer() == true);
		assert(a.RemoveTrailer() == false);

		//y	y	y	y	y	n	y	y	y	y	y	n	y

		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();


	}
	{
		Person* p1 = new Person("name1", 40);
		Person* p2 = new Person("name2", 60);
		Person* p3 = new Person("name3", 12);
		Person* p4 = new Person("name4", 1);
		Person* p5 = new Person("name5", 140);

		Sedan a;

		assert(a.AddPassenger(p1) == true); // true
		assert(a.AddPassenger(p2) == true); // true
		assert(a.AddPassenger(p3) == true); // true
		assert(a.AddPassenger(p4) == true); // true
		assert(a.AddPassenger(p5) == false); // true;

		Trailer* t = new Trailer(40);

		assert(a.AddTrailer(t) == true);

		//	y	y	y	y	y	n	n	y	y	y	y	y	n

		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == true);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();
		assert(a.IsMoveable() == false);
		a.Move();
	}


	/*
	If x <= 80, speed = 480
	If x > 80, speed = 458
	If x > 160, speed = 400
	If x > 260, speed = 380
	If x > 350, speed = 300
	*/
	{
		Person* p = new Person("name", 351);

		Sedan a;

		a.AddPassenger(p);
		assert(a.GetPassengersWeight() == 351);
		assert(a.GetDriveSpeed() == 300);
		assert(a.GetMaxSpeed() == 300);
	}
	{
		Person* p = new Person("name", 261);

		Sedan a;

		a.AddPassenger(p);
		assert(a.GetPassengersWeight() == 261);
		assert(a.GetDriveSpeed() == 380);
		assert(a.GetMaxSpeed() == 380);
	}
	{
		Person* p = new Person("name", 161);

		Sedan a;

		a.AddPassenger(p);
		assert(a.GetPassengersWeight() == 161);
		assert(a.GetDriveSpeed() == 400);
		assert(a.GetMaxSpeed() == 400);
	}
	{
		Person* p = new Person("name", 81);

		Sedan a;

		a.AddPassenger(p);
		assert(a.GetPassengersWeight() == 81);
		assert(a.GetDriveSpeed() == 458);
		assert(a.GetMaxSpeed() == 458);
	}
	{
		Person* p = new Person("name", 80);

		Sedan a;

		a.AddPassenger(p);
		assert(a.GetPassengersWeight() == 80);
		assert(a.GetDriveSpeed() == 480);
		assert(a.GetMaxSpeed() == 480);
	}



	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestSedanClass()" << endl;
	cout << "-------------------------------------" << endl;


}

void TestMotorcycleClass()
{
	Person* p1 = new Person("name1", 40);
	Person* p2 = new Person("name2", 60);
	Person* p3 = new Person("name3", 12);
	Person* p4 = new Person("name4", 1);
	Person* p5 = new Person("name5", 140);

	Motorcycle a;

	assert(a.AddPassenger(p1) == true); // true
	assert(a.AddPassenger(p2) == true); // true
	assert(a.AddPassenger(p3) == false); // false
	assert(a.AddPassenger(p4) == false); // false;
	assert(a.AddPassenger(p5) == false); // false;

	assert(a.GetPassengersWeight() == 100);

	assert(a.GetMaxSpeed() == 304);
	assert(a.GetDriveSpeed() == 304);
	//y	y	y	y	y	n	y	y	y	y	y	n	y

	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();


	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestMotorcycleClass()" << endl;
	cout << "-------------------------------------" << endl;

}

void TestBoatPlaneClass()
{
	Person* p1 = new Person("name1", 10);
	Person* p2 = new Person("name2", 11);
	Person* p3 = new Person("name3", 12);
	Person* p4 = new Person("name4", 1);
	Person* p5 = new Person("name5", 140);

	Boatplane a(4);

	assert(a.AddPassenger(p1) == true); // true
	assert(a.AddPassenger(p2) == true); // true
	assert(a.AddPassenger(p3) == true); // true
	assert(a.AddPassenger(p4) == true); // true;
	assert(a.AddPassenger(p5) == false); // false;

	assert(a.GetPassengersWeight() == 34);

	assert(a.GetMaxSpeed() == 742);
	assert(a.GetFlySpeed() == 709);
	assert(a.GetSailSpeed() == 742);
	//y	n	n	n	y	n	n	n	y	n	n	n	y

	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();


	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestBoatPlaneClass()" << endl;
	cout << "-------------------------------------" << endl;

}

void TestBoatClass()
{
	Person* p1 = new Person("name1", 10);
	Person* p2 = new Person("name2", 11);
	Person* p3 = new Person("name3", 12);
	Person* p4 = new Person("name4", 1);
	Person* p5 = new Person("name5", 140);

	Boat a(4);

	assert(a.AddPassenger(p1) == true); // true
	assert(a.AddPassenger(p2) == true); // true
	assert(a.AddPassenger(p3) == true); // true
	assert(a.AddPassenger(p4) == true); // true;
	assert(a.AddPassenger(p5) == false); // false;


	assert(a.GetMaxSpeed() == 460);
	assert(a.GetSailSpeed() == 460);

	Person* p6 = new Person("name6", 200);
	Person* p7 = new Person("name7", 210);
	Person* p8 = new Person("name8", 220);
	Airplane b(3);
	b.AddPassenger(p6);
	b.AddPassenger(p7);
	b.AddPassenger(p8);

	Boatplane bp = a + b;
	assert(bp.GetPassenger(0) == p6);
	assert(bp.GetPassenger(1) == p7);
	assert(bp.GetPassenger(2) == p8);
	assert(bp.GetPassenger(3) == p1);
	assert(bp.GetPassenger(4) == p2);
	assert(bp.GetPassenger(5) == p3);
	assert(bp.GetPassenger(6) == p4);

	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	//y	y	n	y	y	n	y	y	n	y	y	n	y
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();

	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestBoatClass()" << endl;
	cout << "-------------------------------------" << endl;
}

void TestAirplaneClass()
{

	Person* p1 = new Person("name1", 100);
	Person* p2 = new Person("name2", 110);
	Person* p3 = new Person("name3", 120);
	Person* p4 = new Person("name4", 130);
	Person* p5 = new Person("name5", 140);

	Airplane a(4);

	a.AddPassenger(p1); // true
	a.AddPassenger(p2); // true
	a.AddPassenger(p3); // true
	a.AddPassenger(p4); // true;
	a.AddPassenger(p5); // false;

	assert(a.GetMaxSpeed() == 395);
	assert(a.GetFlySpeed() == 395);
	assert(a.GetDriveSpeed() == 2);

	Boat b(3);

	Person* p6 = new Person("name6", 200);
	Person* p7 = new Person("name7", 210);
	Person* p8 = new Person("name8", 220);

	b.AddPassenger(p6);
	b.AddPassenger(p7);
	b.AddPassenger(p8);

	Boatplane bp = a + b;
	assert(a.GetPassengersCount() == 0);
	assert(b.GetPassengersCount() == 0);

	assert(bp.GetPassengersCount() == 7);
	assert(bp.GetPassengersWeight() == 1090);

	assert(bp.GetPassenger(0) == p1);
	assert(bp.GetPassenger(1) == p2);
	assert(bp.GetPassenger(2) == p3);
	assert(bp.GetPassenger(3) == p4);
	assert(bp.GetPassenger(4) == p6);
	assert(bp.GetPassenger(5) == p7);
	assert(bp.GetPassenger(6) == p8);

	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == true);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);
	a.Move();
	assert(a.IsMoveable() == false);

	cout << "-------------------------------------" << endl;
	cout << "END_OF_TestAirplaneClass()" << endl;
	cout << "-------------------------------------" << endl;
}

int main()
{
	TestPersonClass();
	TestAirplaneClass();
	TestBoatClass();
	TestBoatPlaneClass();
	TestMotorcycleClass();
	TestSedanClass();
	TestUboatClass();
	TestDeusExMachinaClass();

	uint32_t traveledDistanceArr[7][13] =
	{
		{ 1213, 1213, 1213, 1213, 2426, 2426, 2426, 2426, 3639, 3639, 3639, 3639, 4852 },
		{ 800, 1600, 1600, 2400, 3200, 3200, 4000, 4800, 4800, 5600, 6400, 6400, 7200 },
		{ 800, 800, 800, 800, 1600, 1600, 1600, 1600, 2400, 2400, 2400, 2400, 3200 },
		{ 400, 800, 1200, 1600, 2000, 2000, 2400, 2800, 3200, 3600, 4000, 4000, 4400 },
		{ 480, 960, 1440, 1920, 2400, 2400, 2880, 3360, 3840, 4320, 4800, 4800, 5280 },
		{ 480, 960, 1440, 1920, 2400, 2400, 2400, 2880, 3360, 3840, 4320, 4800, 4800 },
		{ 550, 1100, 1100, 1100, 1100, 1100, 1650, 2200, 2200, 2200, 2200, 2200, 2750 }
	};
	DeusExMachina* d = DeusExMachina::GetInstance();


	Airplane* t1 = new Airplane(2);
	Boat* t2 = new Boat(2);
	Boatplane* t3 = new Boatplane(2);
	Motorcycle* t4 = new Motorcycle();
	Sedan* t5 = new Sedan();
	Sedan* t6 = new Sedan();
	t6->AddTrailer(new Trailer(1));
	UBoat* t7 = new UBoat();

	Vehicle* vArr[7] = { t1, t2, t3, t4, t5, t6, t7 };

	for (size_t j = 0; j < 7; ++j)
	{
		d->AddVehicle(vArr[j]);
		for (size_t i = 0; i < 13; ++i)
		{
			cout << j << "::" << i << endl;
			d->Travel();
			if (traveledDistanceArr[j][i] == d->GetVehicle(0)->GetTraveledDistance() == false)
			{
				cout << "d" << endl;
			}
			assert(traveledDistanceArr[j][i] == d->GetVehicle(0)->GetTraveledDistance());
		}
		d->RemoveVehicle(0);
	}


	cout << "-------------------------------------" << endl;
	cout << "ALL_TEST_END" << endl;
	cout << "-------------------------------------" << endl;

	system("pause");
}