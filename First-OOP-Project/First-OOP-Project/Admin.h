#pragma once
#include "Car.h"

class Organization;
class Admin
{
private:
	vector<Car*>carsToBeVerified;
	void displayAllCars(Organization* org);
	void displayAllUsers(Organization*org,int flag);
	void showCarsToBeVerified(Organization *org);
	
	
public:
	static float totalMoney;
	void displayInfo(Organization *org);
	Admin(Organization *org);

};

