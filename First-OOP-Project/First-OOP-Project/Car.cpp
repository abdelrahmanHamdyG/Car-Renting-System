#include "Car.h"
using namespace std;

Car::Car()
{
	isVerified = false;
	isSeenByTheAdmin = false;
	totalMoneyGotFromTheCar = 0;

}



Car::Car(string _model, int _maxSpeed, int _rentingPrice,vector<RentingProcess*>_rentingProcesses) :model(_model), maxSpeed(_maxSpeed),
isRented(false), rentingPrice(_rentingPrice)
{
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
	string isRenteds = isRented ? "YES" : "NO";
	string isVerifieds = isVerified ? "YES" : "NO";
	cout << "model: " << model << "\t\tRentingPrice: " << rentingPrice << " EGP\n\n" << "HorsePower: " << horsePower << " HP\t\t" << "toruq: " << torque << " N-m\n\n";
	cout << "isRented: " << isRenteds << "\t\t\tisVerified: " << isVerifieds<< "\n\n";

	cout << "totalMoneyPaidOnThisCar: " << totalMoneyGotFromTheCar<< "\n";
	cout << "commisionRateForTheOwner: " << commision<<'\n';
	cout << "----------------------------------------------\n";


}
string Car::getModel() {

	return model;
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
	return carType;
}

string Car::getGear()
{
	return gear;
}

int Car::getHorsePower()
{
	return horsePower;
}

int Car::getTorque()
{
	return torque;
}

int Car::getRentingPrice()
{
	return rentingPrice;
}

int Car::getMAxSpeed() {
	return maxSpeed;
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
	string s;
	s += ID; s += " ";
	s += model; s += " ";
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
	s += to_string(horsePower); s += " ";
	s += to_string(torque); s += " ";
	s += carType; s += " ";
	s += gear; s += " ";
	s += to_string(maxSpeed); s += " ";
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
	carType = t;
}

void Car::setGear(string g)
{
	gear = g;
}

void Car::setModel(string m) {
	model = m;
}

void Car::setHorsePower(int hp)
{
	horsePower = hp;
}

void Car::setTorque(int tor)
{
	torque = tor;
}

void Car::setRentingPrice(int p)
{
	rentingPrice = p;
}

void Car::setMaxSpeed(int s)
{
	maxSpeed = s;
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
	string s;
	bool flag = false;
	this->ID = to_string(_id);
	isVerified = false;
	this->carOwnerID = to_string(_carOwnerID);
	cout << "Model: ";
	cin >> model;
	while (!flag) {
		cout << "HorsePower: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	horsePower = stoi(s);

	while (!flag) {
		cout << "Torque: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	torque = stoi(s);

	cout << "Car Type: ";
	cin >> carType;
	cout << "Gear: ";
	cin >> gear;

	while (!flag) {
		cout << "Speed: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				cout << "Unvalid input, please enter an Integer\n";
				flag = false;
				break;
			}
		}
	}
	flag = false;
	maxSpeed = stoi(s);

	while (!flag) {
		cout << "CarPricePerH: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (!(s[i] >= '0' && s[i] <= '9'))
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
		cout << "Commision: ";
		cin >> s;
		flag = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') {
				for (int j = i + 1; j < s.size(); j++) {
					if ((s[j] >= '0' && s[j] <= '9')) {
						x += y * (s[j] - '0');
						y *= 0.1;
					}
				}
				break;
			}
			if (!(s[i] >= '0' && s[i] <= '9'))
			{
				cout << "Unvalid input, please enter an Integer\n";
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