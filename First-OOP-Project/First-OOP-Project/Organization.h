#pragma once
#include<vector>
#include "User.h"
#include "Car.h"
#include "Renter.h"
#include "Owner.h"
#include <fstream>
#include<iostream>	
#include<string>
#include <sstream>
#include "RentingProcess.h"
#include "Admin.h"
	
using namespace std;

class Organization {


public:
	 
	vector<User*> allUsers;
	vector<Car> allCars;
	vector<Notification> allNotifications;
	vector<RentingProcess> allRentingProcesses;
	Organization();
	void readFiles();
	void writeFiles();
	vector<Car> readCars();
	User* signUp(string _userName, string _password,int response);
	User* authenticate(string userName, string password);
	vector<string> formatAsVectorOfString(string s);
	vector<Notification> readNotifications();
	vector<RentingProcess>readRentingProcesss();
	
};

