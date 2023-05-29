#pragma once
#include <string>
#include "Date.h"
using namespace std;
class Notification {
private:
	string id;
	string renter;
	string rentedCar;
	string type; // carVerification - newCarAdded - carRented
	string rentingDate;
	//string isVerified;
public:
	string getID();
	Notification(string _type, string _id, string _rentedCar, string _renter, string _rentingDate);
	
	bool checkId(string _id);
	string getWhatToBeWrittenInFile();
	void displayInfo();


};

