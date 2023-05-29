#include "RentingProcess.h"
#include<string>
using namespace std;



RentingProcess::RentingProcess(string _id, string _carOwner, string _carRenter, Date _beginningDate,string _carid)
{
	id = _id;
	carOwner = _carOwner;	
	carRenter = _carRenter;
	beginningDate = _beginningDate;
	cost = -1;
	duration = -1;
	isRunning = true;
	carID = _carid;

}
RentingProcess::RentingProcess(string _id, string _carOwner, string _carRenter, Date _beginningDate, float _cost, float _duration, bool _isRunning, string _carID)
{

	id = _id;
	carOwner = _carOwner;
	carRenter = _carRenter;
	beginningDate = _beginningDate;
	cost = _cost;
	duration = _duration;
	isRunning = _isRunning;
	carID = _carID;
}
void RentingProcess::displayInfo()
{

	cout << "totalCost: " << cost<<"\t\t"; 
	cout << "Beginning of the contract: ";
	beginningDate.displayDate();
	cout << "\n\n";
	if (!isRunning) {
		cout << "duration:" << duration << " hour\n\n";
	}
	else {
		cout << "StillRunning: YES\n";
	}
	
	cout << "------------------------------------------------\n";
	
}



string RentingProcess::getWhatToWrite() {
	return(id + " " + carOwner +  " " + to_string(beginningDate.day) + "/" + to_string(beginningDate.month) + "/" + to_string(beginningDate.year) + " " + to_string(cost) + " " + to_string(isRunning) + " " + to_string(duration));
}

bool RentingProcess::getIsRunning()
{
	return isRunning;
}

void RentingProcess::setIsRunning(bool s)
{
	isRunning = s;
}

string RentingProcess::getCarId()
{
	return carID;
}

string RentingProcess::getID()
{
	return id;
	
}

string RentingProcess::getWhatToBeWrittenInFile()
{
	string s;
	
	s += id; s += " ";
	s += carOwner; s += " ";
	s += carRenter; s += " ";
	s += beginningDate.getString1(); s += " ";
	s += to_string(cost); s += " ";
	s += to_string(duration); s += " ";
	s += to_string(isRunning); s += " ";
	s += carID;
	return s;

}

Date RentingProcess::getBeginningDate()
{
	return beginningDate;
}

float RentingProcess::getDuration()
{
	return duration;
}

void RentingProcess::setDuration(float f)
{

	duration = f;
}

void RentingProcess::setCost(float c)
{
	cost = c;
}
