#include "Car.h"
#include"Helper.h"
using namespace std;

Car::Car()
{
	isVerified = false;
	isSeenByTheAdmin = false;
	totalMoneyGotFromTheCar = 0;

}



Car::Car(string _model, int _maxSpeed, int _rentingPrice,vector<RentingProcess*>_rentingProcesses) :
isRented(false), rentingPrice(_rentingPrice)
{
	specs.maxSpeed = _maxSpeed;
	specs.model = _model;
	this->RentingProcesses = _rentingProcesses;

}

void Car::setIsRented() {

	isRented = !isRented;
}

bool Car::getIsRented() {

	return isRented;
}
void Car::displayInfo()
{

	// displaying Car specs
	string isRenteds = isRented ? "YES" : "NO";
	string isVerifieds = isVerified ? "YES" : "NO";
	cout << "model: " << specs.model << "\t\tRentingPrice: " << rentingPrice << " EGP\n\n" << "HorsePower: " << specs.horsePower << " HP\t\t" << "toruq: " << specs.torque << " N-m\n\n";
	cout << "isRented: " << isRenteds << "\t\t\tisVerified: " << isVerifieds<< "\n\n";

	cout << "totalMoneyPaidOnThisCar: " << totalMoneyGotFromTheCar<< "\n";
	cout << "commisionRateForTheOwner: " << commision<<'\n';
	cout << "----------------------------------------------\n";


}
string Car::getModel() {

	return specs.model;
}

string Car::getID()
{
	return ID;
}

string Car::getCarOwnerID()
{
	return carOwnerID;
}

string Car::getCarType()
{
	return specs.carType;
}

string Car::getGear()
{
	return specs.gear;
}

int Car::getHorsePower()
{
	return specs.horsePower;
}

int Car::getTorque()
{
	return specs.torque;
}

int Car::getRentingPrice()
{
	return rentingPrice;
}

int Car::getMAxSpeed() {
	return specs.maxSpeed;
}

bool Car::getRentingStatus()
{
	return isRented;
}

float Car::getCommision()
{
	return commision;
}

vector<RentingProcess*> Car::getRentingProcesses()
{
	return RentingProcesses;
}

string Car::getWhatToBeWrittenInFile()
{

	// here we preparing the string that will be written in cars file
	string s;
	s += ID; s += " ";
	s += specs.model; s += " ";
	s += carOwnerID; s += " ";
	s += "{";
	int c = 0;
	for (auto i : RentingProcesses) {
		if (c)
			s += ",";
		s += i->getID();
		c++;
		
	}
	s += "} ";
	s += to_string(specs.horsePower); s += " ";
	s += to_string(specs.torque); s += " ";
	s += specs.carType; s += " ";
	s += specs.gear; s += " ";
	s += to_string(specs.maxSpeed); s += " ";
	s += to_string(isRented); s += " ";
	s += to_string(rentingPrice); s += " ";
	s += to_string(isVerified); s += " ";
	s += to_string(commision); s += " ";
	s += to_string(totalMoneyGotFromTheCar); s += " ";
	s += to_string(isSeenByTheAdmin);
	return s;
}

bool Car::getVerification()
{
	return isVerified;
}


void Car::setID(string id)
{
	ID = id;
}

void Car::setCarOwnerID(string idd)
{
	carOwnerID = idd;
}

void Car::setCarType(string t)
{
	specs.carType = t;
}

void Car::setGear(string g)
{
	specs.gear = g;
}

void Car::setModel(string m) {
	specs.model = m;
}

void Car::setHorsePower(int hp)
{
	specs.horsePower = hp;
}

void Car::setTorque(int tor)
{
	specs.torque = tor;
}

void Car::setRentingPrice(int p)
{
	rentingPrice = p;
}

void Car::setMaxSpeed(int s)
{
	specs.maxSpeed = s;
}

void Car::setRentingStatus(bool r)
{
	isRented = r;
}

void Car::setCommision(float c)
{
	commision = c;
}

void Car::getCarInput(int _id, int _carOwnerID)
{

	//here we are taking the input and the data of the car 
	string s;
	bool flag = false;
	this->ID = to_string(_id);
	isVerified = false;
	this->carOwnerID = to_string(_carOwnerID);
	cout << "Model: ";
	cin >> specs.model;
	while (!flag) {
		cout << "HorsePower: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(Helper::checkDigit(s[i])))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	specs.horsePower = stoi(s);

	while (!flag) {
		cout << "Torque: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(Helper::checkDigit(s[i])))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	specs.torque = stoi(s);

	cout << "Car Type: ";
	cin >> specs.carType;
	cout << "Gear: ";
	cin >> specs.gear;

	while (!flag) {
		cout << "Speed: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(Helper::checkDigit(s[i])))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	specs.maxSpeed = stoi(s);

	while (!flag) {
		cout << "CarPricePerH: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(Helper::checkDigit(s[i])))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	rentingPrice = stoi(s);

	float x = 0;
	float y = 0.1;
	while (!flag) {
		cout << "Commision rate(decimalNumber from 0 to 1 ): ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				for (int j = i + 1; j < s.size(); j++) {
					if ((Helper::checkDigit(s[j]))) {
						x += y * (s[j] - '0');
						y *= 0.1;
					}
				}
				break;
			}
			if (!(Helper::checkDigit(s[i])))
			{
				cout << "Unvalid input, please enter a number from 0 to 1 \n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	int t = stoi(s);
	commision = x + (float)t;

	cout << "\nYour car has been sent to the administration to be verified\n\n";
	system("pause");
	

}
void Car::setRentingProcesses(vector<RentingProcess*> _rps)
{
	this->RentingProcesses = _rps;
}

void Car::pushToRentingProcesses(RentingProcess* rp)
{
	RentingProcesses.push_back(rp);
}



void Car::setVerification(bool v)
{
	isVerified = v;
}