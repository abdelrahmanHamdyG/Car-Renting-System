#pragma once
#include "Car.h"
#include "Notification.h"
#include"Car.h"
#include<vector>
#include "User.h"
#include<string>

class Owner:public User
{
private:
	vector<Car*>cars;
	vector<Notification*>inbox;
public:
	Owner(string _id, string _userName, string _password, int _totalMoney, vector<Car*>_cars,
		vector<Notification*>_inbox);
	Owner(string _id, string _userName, string _password, int _totalMoney);
	void displayInfo();
	string toBeWrittenInFile();
	void addNewCar();
	void showMyCars();
	void showInbox();
	void changeMoney(float money);
	void displayData();
	void displayTheUniqueHistory();
};

