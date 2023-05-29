#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include <fstream>	
using namespace std;

class RentingProcess	
{
private:
	string id;
	string carOwner;
	string carRenter;
	Date beginningDate;
	float cost;
	float duration;
	bool isRunning=1;
	string carID;
public:

	RentingProcess(string _id ,string _carOwner,string _carRenter, Date _beginningDate, string _carID);
	RentingProcess(string _id, string _carOwner, string _carRenter, Date _beginningDate, float cost, float duration, bool _isRunning,string _carID);

	void displayInfo(string s);	
	string getWhatToWrite();
	bool getIsRunning();
	void setIsRunning(bool s);
	string getCarId();
	string getID();
	string getWhatToBeWrittenInFile();
	Date getBeginningDate();
	float getDuration();
	void setDuration(float f);
	void setCost(float c);
	
};

