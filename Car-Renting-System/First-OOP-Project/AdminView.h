#pragma once
#include <vector>
#include "Car.h"
#include "Organization.h"
#include "Admin.h"
class AdminView
{
public:
	void displayAllCars(vector<Car*> carsToBeVerified);
	void displayAllUsers(int flag, vector<Car*> carsToBeVerified);
	pair<int,int> showCarsToBeVerified(vector<Car*> carsToBeVerified);
	int displayInfo(vector<Car*> carsToBeVerified);
	pair<int,int> verifyCar(Organization* org, int inp1, int* key, vector<Car*> carsToBeVerified);
};

