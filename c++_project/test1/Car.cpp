#include <iostream>
#include <cstring>
#include "Car.h"
using namespace std;

void Car::InitMembers(char * ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelgauge = fuel;
	curspeed = 0;
}

void Car::ShowCarState()
{
	cout << "소유자 ID: " << gamerID << endl;
	cout << "연료량 : " << fuelgauge << endl;
	cout << "현재 속도: " << curspeed << "km/s" << endl;
}

void Car::Accel()
{
	if (fuelgauge <= 0)
		return;
	else\
		fuelgauge -= CAR_CONST::FUEL_STEP;
	if ((curspeed = CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
	{
		curspeed = CAR_CONST::ACC_STEP;
		return;
	}
	curspeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
	if (curspeed < CAR_CONST::BRK_STEP)
	{
		curspeed = 0;
		return;
	}
	curspeed -= CAR_CONST::BRK_STEP;
}
