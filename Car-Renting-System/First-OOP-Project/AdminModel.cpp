#include "AdminModel.h"
#include"Helper.h"

void AdminModel::initializeCarsToBeVerified() {
	Organization* org = Organization::getInstance();
	//we read cars that should be reviewed  by admin 
	for (int i = 0; i < org->allCars.size(); i++) {
		if (!(org->allCars[i].isSeenByTheAdmin)) {
			carsToBeVerified.push_back(&org->allCars[i]);
		}
	}
}
void AdminModel::confirm(int input) {
	Organization* org = Organization::getInstance();
	string type;
	carsToBeVerified[input]->isSeenByTheAdmin = true;
	carsToBeVerified[input]->setVerification(true);
	type = "newCarAdded";
	cout << "You verified this car\n";
	system("pause");
	User* owner = org->allUsers[stoi(carsToBeVerified[input]->getCarOwnerID()) - Helper::STARTING_ID_OF_OWNERS];
	Date d = Date::getCurrentDate();
	Notification n(type, to_string(org->allNotifications.size()), (carsToBeVerified[input]->getModel()), "-1", d.getString1());
	org->allNotifications.push_back(n);
	owner->changeMoney(0);
	org->writeFiles();

}
void AdminModel::reject(int input) {
	Organization* org = Organization::getInstance();
	string type;
	type = "carVerification";
	carsToBeVerified[input]->isSeenByTheAdmin = true;
	carsToBeVerified[input]->setVerification(false);
	cout << "You refused this car\n";
	system("pause");
	User* owner = org->allUsers[stoi(carsToBeVerified[input]->getCarOwnerID()) - Helper::STARTING_ID_OF_OWNERS];
	Date d = Date::getCurrentDate();
	Notification n(type, to_string(org->allNotifications.size()), (carsToBeVerified[input]->getModel()), "-1", d.getString1());
	org->allNotifications.push_back(n);
	owner->changeMoney(0);
	org->writeFiles();

}

