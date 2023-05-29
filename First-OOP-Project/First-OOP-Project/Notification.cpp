#include "Notification.h"

string Notification::getID()
{
    return id;
}

Notification::Notification(string _type, string _id, string _rentedCar, string _renter, string _rentingDate)
{
	id = _id;
	renter = _renter;
	rentedCar = _rentedCar;
	rentingDate = _rentingDate;
	//isVerified = _isVerified;
	type = _type;

}

bool Notification::checkId(string _id){
    if (_id == id) return true;
    return false;
}

string Notification::getWhatToBeWrittenInFile()
{
	string s;
	s += type;
	s += " ";
	s += id;
	s += " ";
	s += rentedCar;
	s += " ";
	s += renter;
	s += " ";
	s += rentingDate;

	return s;

}

void Notification::displayInfo()
{

	
	if (type == "carVerification") {

		cout <<rentingDate <<" Sorry but your car (" << rentedCar << ") has been refused by admin";

	}
	if (type == "newCarAdded") {


		cout << rentingDate << " congratulation your car (" << rentedCar << ") has been accepeted and verified by admin";
	}

	if (type == "carRented") {

		cout << rentingDate << " your car (" << rentedCar << ") has been rented and you got" << renter << " pound";
	}

	cout << '\n';
}

