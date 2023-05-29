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


private:
	static Organization* instance;

	Organization();
	
public:
	static const int STARTING_ID_OF_RENTERS = 100;
	static const int STARTING_ID_OF_OWNERS = 300;
	static Organization* getInstance();
	Organization( const Organization& org) = delete;
	vector<User*> allUsers;
	vector<Car> allCars;
	vector<Notification> allNotifications;
	vector<RentingProcess> allRentingProcesses;
	void readFiles();
	void writeFiles();
	vector<Car> readCars();
	User* signUp(string _userName, string _password,int response);
	User* authenticate(string userName, string password);
	vector<string> formatAsVectorOfString(string s);
	vector<Notification> readNotifications();
	vector<RentingProcess>readRentingProcesss();
	User* readOwner(int id, string name, string password, float totalMoney, string carString, string inboxString);
	User* readRenter(int id, string name, string password, float totalMoney, string currentCar, string rentingProcessString);

};


