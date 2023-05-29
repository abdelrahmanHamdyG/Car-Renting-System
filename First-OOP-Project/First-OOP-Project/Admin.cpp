#include "Admin.h"
#include "Organization.h"
#include<vector>
#include "openingUI.h"
using namespace std;
#include <iostream>

float Admin::totalMoney = 0;
void Admin::displayAllCars(Organization* org)
{

	int counter = 1;
	vector<int>key(org->allCars.size() + 1);
	for (int i = 0; i < org->allCars.size(); i++) {

		if ((org->allCars[i]).getVerification()) {
			if (counter == 1) {
				system("cls");
			}
			cout << counter << ":\n";
			cout << org->allUsers[stoi(org->allCars[i].getCarOwnerID()) - 300]->username << "\n";

			org->allCars[i].displayInfo();
			key[counter] = i;
			cout << '\n';
			counter++;
		}

	}
	if (counter == 1) {

		cout << "\nThere is no Available Cars to be displayed\n";
		system("pause");
		displayInfo(org);
	}


	bool ff = false;
	string s = "0";
	int n = 1;
	while (!ff) {
		cout << "Choose car index to show or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(org);
		else if (s[0] < '9' && s[0] > '0') {
			ff = true;
			if (s.size() > 1) {
				if (s[1] < '9' && s[1] > '0') {
				}
				else ff = false;
			}
		}
		if (ff)
			n = stoi(s);
		else {
			cout << "unvalid input please try again" << endl;
			system("pause");
		
		}
	}
	if (n >= counter||n<=0) {
		cout << "unavailabe car id \n";
		system("pause");
		system("cls");
		displayAllCars(org);
	}
	else {
		n = key[n];
		Car choosenCar = org->allCars[n];
		counter = 1;

		
		system("cls");
		cout << "Car:" << choosenCar.getModel() << "\n\n\n";


		if (choosenCar.getRentingProcesses().size()) {
			for (int i = 0; i < choosenCar.getRentingProcesses().size(); i++) {

				cout << counter << ":";
				choosenCar.getRentingProcesses()[i]->displayInfo();
			}
		}
		else {
			
			cout << "sorry but this car doesn't have any rentingProcesses till now\n";
		}
		system("pause");
		displayAllCars(org);
	}
	/*
	string ss = "0";
	while (ss != "1" && ss != "2") {
		cout << "do you want to show another car\n";
		cout << "1- yes\n";
		cout << "2- no\n";
		cin >> ss;
		if (ss == "1")
			displayAllCars(org);
		else if (ss == "2")
			displayInfo(org);
		else {
			system("cls");
			cout << "unvlaid input please enter 1 or 2\n";
		}
	}
	*/

}
void Admin::displayAllUsers(Organization* org, int flag)
{
	// flag=3 renters 
	// flag==4 owners
	//
	int counter = 1;
	int i2 = 0;
	vector<int>key(org->allUsers.size() + 1);
	for (auto i : org->allUsers) {
		if (((stoi(i->id) / 100) % 10 < 3 && flag == 3) || (flag == 4 && (stoi(i->id) / 100) % 10 >= 3)) {
			if (counter==1)
				system("cls");
			cout << counter << ":\n";
			i->displayData();

			key[counter] = i2;
			counter++;

		}
		i2++;

	}

	if (counter == 1) {
		string s;
		if (flag == 3) {
			s = "Renters\n";
		}
		else {
			s = "Owners\n";
		}
		cout << "\nThere are no " << s << " to be shown\n";
		system("pause");
		displayInfo(org);
	}

	bool ff = false;
	string s = "0";
	int n = 1;
	while (!ff) {
		cout << "Choose user ID to show or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(org);
		else if (s[0] < '9' && s[0] > '0') {
			ff = true;
			if (s.size() > 1) {
				if (s[1] < '9' && s[1] > '0') {
				}
				else ff = false;
			}
		}
		if (ff) {
			n = stoi(s);
		}
		else {
			cout << "unvalid input please try again" << endl;
			system("pause");
			system("cls");
			displayAllUsers(org,flag);
			

		}
	}
	if (n >= counter) {
		cout << "unavailabe person id \n";
		system("pause");
		system("cls");
		displayAllUsers(org, flag);
	}
	else {
		n = key[n];
		User* choosenRenter = org->allUsers[n];
		system("cls");
		choosenRenter->displayTheUniqueHistory();
		system("pause");
		displayAllUsers(org, flag);

	}
	/*
	string ss = "0";
	while (ss != "1" && ss != "2") {
		cout << "do you want to show another user\n";
		cout << "1- yes\n";
		cout << "2- no\n";
		cin >> ss;
		if (ss == "1")
			displayAllUsers(org, flag);
		else if (ss == "2")
			displayInfo(org);
		else {
			system("cls");
			cout << "unvlaid input please enter 1 or 2\n";
		}
	}
	*/
}

void Admin::showCarsToBeVerified(Organization* org)
{

	int key[100] = { 0 };
	int k = 1;

	///
	for (int i = 0; i < carsToBeVerified.size(); i++) {

		if (!carsToBeVerified[i]->isSeenByTheAdmin) {
			if (k == 1)
				system("cls");
			cout << k  << ": ";
			carsToBeVerified[i]->displayInfo();
			key[k] = i;
			k++;
		}
	}
	if (k == 1) {

		cout << "No Cars to be verified \nPress any key to continue \n";
		system("pause");
		

		displayInfo(org);
	}

	// 1- car1
	// 2- car2
	// 3-

	// 1
	// 2
	// 3
	// 4
	//////
	/////

	bool flag = false;
	string s = "0";
	int inp1 = 0;
	while (!flag) {
		cout << "Choose car no to verify or enter \"a\" to go back : ";
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
			inp1 = stoi(s);
		else {
			system("cls");
			cout << "unvalid input please try again" << endl;
		}
	}
	cout << inp1 << '\n';
	if (inp1 >=k)
		cout << "unavailabe car id \n";
	else {
		inp1 = key[inp1];

		string type;
		string inp2 = "0";
		
		// we should add notification for the user
		while (inp2 != "1" && inp2 != "2") {
			
			cout << "Do you want to accept it?\n";
			
			cout << "1- yes\n";
			cout << "2- no\n";
			cin >> inp2;
			if (inp2 == "1") {
				carsToBeVerified[inp1]->isSeenByTheAdmin = true;
				carsToBeVerified[inp1]->setVerification(true);
				type = "newCarAdded";
			}
			else if (inp2 == "2") {
				type = "carVerification";
				carsToBeVerified[inp1]->isSeenByTheAdmin = true;
				carsToBeVerified[inp1]->setVerification(false);
			}
			else {
				
				cout << "unvalid input please try again\n";
			}
		}

		User* owner = org->allUsers[stoi(carsToBeVerified[inp1]->getCarOwnerID()) - 300];
		Date d = Date::getCurrentDate();
		Notification n(type, to_string(org->allNotifications.size()), (carsToBeVerified[inp1]->getModel()), "-1", d.getString1());
		org->allNotifications.push_back(n);
		owner->changeMoney(0, org);
	}

	string ss = "0";
	while (ss != "1" && ss != "2") {
		cout << "do you want to verify another car\n";
		cout << "1- yes\n";
		cout << "2- no\n";
		cin >> ss;
		if (ss == "1")
			showCarsToBeVerified(org);
		else if (ss == "2")
			displayInfo(org);
		else {
			system("cls");
			cout << "unvlaid input please enter 1 or 2\n";
		}
	}


}



void Admin::displayInfo(Organization* org)
{
	int i = 0;
	while (true) {
		system("cls");
		if (i)
			cout << "unvalid input please try again" << endl;
		i++;
		cout << "\t\t\t\tHello ADMIN\n";
		cout << "total money: " << totalMoney << '\n';
		cout << "1-Cars To be verified\n";
		cout << "2-show all verified Cars\n";
		cout << "3-show all Renter\n";
		cout << "4-show all Owners\n";
		cout << "5-go back\n";
		string inp = "0";
		cin >> inp;
		if (inp == "1") {
			i = 0;
			if (carsToBeVerified.size() == 0) {
				cout << "There is no cars to be verified\n";
				system("pause");
				continue;
			}
			showCarsToBeVerified(org);
			
		}
		if (inp == "2") {
			i = 0;
			displayAllCars(org);
		}
		if (inp == "3" || inp == "4") {
			int x = stoi(inp);
			displayAllUsers(org, x);
			i = 0;
		}
		if (inp == "5") {
			openingUI(org);
		}
	}
}

Admin::Admin(Organization* org)
{

	for (int i = 0; i < org->allCars.size(); i++) {
		if (!(org->allCars[i].isSeenByTheAdmin)) {

			carsToBeVerified.push_back(&org->allCars[i]);

		}
	}

}