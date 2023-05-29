#pragma once
#include "Car.h"
#include <vector>
#include "Admin.h"
#include "Organization.h"

class AdminModel
{
private:
	vector<Car*>carsToBeVerified;
public:
	vector<Car*> getCars() {
		return carsToBeVerified;
	}
	void initializeCarsToBeVerified();
	void confirm(int indexOfCar);
	void reject(int indexOfCar);
};

