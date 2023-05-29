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
void RentingProcess::displayInfo(string s)
{
	// we are display the information of a specific rentingProcess
	cout << "totalCost: " << cost<<"\t\t"; 
	cout << "Beginning of the contract: ";
	beginningDate.displayDate();
	cout << "\n\n";
	if (!isRunning) {
		cout << "duration:" << duration << " hour\n\n";
	}
	else {
		cout << "StillRunning: YES\t\t";
		
	}
	if (s != " ") {
		cout << "CarModel: " << s << '\n';
	}
	
	cout << "------------------------------------------------\n";
	
}



string RentingProcess::getWhatToWrite() {
	// we are preparing the string that will be written in the File 
	return(id + " " + carOwner +  " " + to_string(beginningDate.dateInformation.day) + "/" + to_string(beginningDate.dateInformation.month) + "/" + to_string(beginningDate.dateInformation.year) + " " + to_string(cost) + " " + to_string(isRunning) + " " + to_string(duration));
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
	// we are preparing the string that will be written in the File 
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
