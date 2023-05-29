#include "Renter.h"
#include"Organization.h"
#include"OpeningUI.h"


Renter::Renter(string _id, string _userName, string _password, int _totalMoney, string _currentCar, vector<RentingProcess*> _rentingProcesses) :User(_id, _userName, _password, _totalMoney)
{
	this->currentCar = _currentCar;
	this->rentingProcesses = _rentingProcesses;
}

Renter::Renter() :User("-1", "dummy", "dummy") {


}

Renter::Renter(string _id, string _userName, string _password, int _totalMoney) :User(_id, _userName, _password, _totalMoney)
{
	this->currentCar = "-1";

}


void Renter::displayInfo(Organization* org)
{
	// logic of Renter
	int i = 0;
	while (true) {
		
		if (i)
			cout << "unvalid input please try again" << endl;
		i++;
		system("cls");
		cout << "\t\t\t\t\t Hello " << username << "\n\n";
		cout << "total Money Paid: "<<totalMoney << "\n\n";
		if (currentCar != "-1") {
			cout << "current car :" << currentCar << '\n';
		}
		cout << "1-See available cars\n";
		cout << "2-View my history\n";
		cout << "3-go back\n";
		if (currentCar != "-1") {
			cout << "4-End my Rent\n";
		}

		string inp = "0";
		cin >> inp;
		
		if (inp == "1") {
			i = 0;
			if (currentCar != "-1") {	
				
				cout << "Sorry but you have to end the rent before you start a new rent\n";
				system("pause");
				continue;
			}
			showAvailableCars(org);
			
		}
		else if (inp == "2") {
			if(rentingProcesses.size()==0){
			
				cout << "\n you don't have any rentingProcesses yet\n";

			}
			else {
				for (auto r : rentingProcesses) {
					r->displayInfo();
				}
			}
			system("pause");
			i = 0;
		}
		else if (inp == "4" && currentCar != "-1") {


			endRent(org);
			i = 0;
		}
		else if (inp == "3") {
			openingUI(org);
			i = 0;
		}
	}
}

string Renter::toBeWrittenInFile()
{

	string s = User::toBeWrittenInFile();
	s += currentCar;
	s += " ";
	///
	/// this will be discussed later
	s += "{";
	int counter = 0;
	for (auto i : rentingProcesses) {
		if (counter)
			s += ',';

		s += i->getID();
		counter++;
	}
	s += "}";
	//
	return s;

}

void Renter::showAvailableCars(Organization* org) {
	system("cls");
	cout << "To rent a car write its index\n";
	int i = 1;
	int h = 0;
	vector<int>key(org->allCars.size());

	vector<Car> cars = org->allCars;
	for (auto car : cars) {
		if (!car.getIsRented() && car.getVerification()) {
			cout << i << ": ";
			car.displayInfo();
			key[i] = h;
			i++;
		}
		h++;
	}
	if (i == 1) {

		cout << "sorry but there are no available cars now\n";
		system("pause");
		displayInfo(org);
		
	}

	bool flag = false;
	string s = "0";
	int n = 0;
	while (!flag) {
		cout << "Choose car no to show or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(org);
		else if (s[0] < '9' && s[0] > '0') {
			flag = true;
			if (s.size() > 1) {
				if (s[1] < '9' && s[1] > '0') {
				}
				else flag = false;
			}
		}
		if (flag)
			n = stoi(s);
		else {
			cout << "unvalid input please try again" << endl;
		}
	}
	if (n >= i||n<=0) {
		cout << "unavailabe car id \n";
		system("pause");
		showAvailableCars(org);
	}
	else {
		n = key[n];
		Car car = org->allCars[n];
		
			org->allCars[n].setIsRented();
			Date date = Date::getCurrentDate();
			int sz = org->allRentingProcesses.size();
			string str = to_string(sz);
			currentCar = car.getModel();
			RentingProcess rentingProcess(str, car.getCarOwnerID(), id, date, car.getID());
			org->allRentingProcesses.push_back(rentingProcess);
			rentingProcesses.push_back(&(org->allRentingProcesses[(org->allRentingProcesses.size() - 1)]));
			org->allCars[n].pushToRentingProcesses(&(org->allRentingProcesses[(org->allRentingProcesses.size() - 1)]));
			cout << "\n\n\nYou started renting a " << car.getModel() << " at " << date.getString1() << "\n\n";
			system("pause");
		
	}
	
}

void Renter::endRent(Organization* org) {


	RentingProcess* lastRentingProcess = rentingProcesses[rentingProcesses.size() - 1];

	Car car = org->allCars[stoi(lastRentingProcess->getCarId())];
	string currentCarsss = currentCar;
	currentCar = "-1";
	org->allCars[stoi(lastRentingProcess->getCarId())].setIsRented();

	string CarOwnerID = car.getCarOwnerID();

	User* carOwner = org->allUsers[stoi(CarOwnerID) - 300];



	Date d2 = lastRentingProcess->getBeginningDate();



	float duration = Date::getDuration(d2);
	float cost = car.getRentingPrice() * duration;
	org->allCars[stoi(lastRentingProcess->getCarId())].totalMoneyGotFromTheCar += cost;
	Admin::totalMoney += (1 - car.getCommision()) * cost;

	rentingProcesses[rentingProcesses.size() - 1]->setCost(cost);
	rentingProcesses[rentingProcesses.size() - 1]->setDuration(duration);
	Notification notification("carRented", to_string(org->allNotifications.size()), car.getModel(), to_string(cost * car.getCommision()), Date::getCurrentDate().getString1());

	
	org->allNotifications.push_back(notification);


	rentingProcesses[rentingProcesses.size() - 1]->setIsRunning(0);
	carOwner->changeMoney(cost * car.getCommision(), org);
	changeMoney(cost, org);
	cout << "You have rented " << currentCarsss << " for " << duration << " hours " << " and the cost is " << cost<<'\n';

	system("pause");

	return;
	


}

void Renter::displayData()
{
	User::displayData();

	if (currentCar != "-1") {
		cout << "current car ID:\n" << currentCar;
	}
	cout << "number of rentings: " << rentingProcesses.size() << '\n';

}

void Renter::displayTheUniqueHistory()
{

	if (rentingProcesses.size() == 0) {
		cout << "this Renter has no history\n";

	}
	else {
		for (int i = 0; i < rentingProcesses.size(); i++) {

			cout << i + 1 << ":";
			rentingProcesses[i]->displayInfo();
			cout << '\n';

		}
	}
	
}
