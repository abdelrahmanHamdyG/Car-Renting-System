#pragma once
#include "User.h"
#include "RentingProcess.h"


class Renter:public User
{
private:
	string currentCar;
	vector<RentingProcess*>rentingProcesses;
	

public:
	Renter(string _id,string _userName,string _password,int _totalMoney,string _currentCar,
		vector<RentingProcess*>_rentingProcesses);
	Renter();
	Renter(string _id, string _userName, string _password, int _totalMoney);
	void displayInfo(Organization* org);
	string toBeWrittenInFile();
	void showAvailableCars(Organization *org);
	void endRent(Organization *org);
	void displayData();
	void displayTheUniqueHistory();
};

