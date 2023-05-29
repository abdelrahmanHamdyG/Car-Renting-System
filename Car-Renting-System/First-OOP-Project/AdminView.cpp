#include "AdminView.h"
#include "OpeningUI.h"
#include"Helper.h"

void AdminView::displayAllCars(vector<Car*> carsToBeVerified)
{
	// we are trying to displaying all Verified Cars and getting the history of each car onClick
	Organization* org = Organization::getInstance();

	int counter = 1;
	vector<int>key(org->allCars.size() + 100);
	for (int i = 0; i < org->allCars.size(); i++) {

		if ((org->allCars[i]).getVerification()) {
			if (counter == 1) {
				system("cls");
			}
			cout << counter << ":\n";
			cout << org->allUsers[stoi(org->allCars[i].getCarOwnerID()) - Helper::STARTING_ID_OF_OWNERS]->username << "\n";

			org->allCars[i].displayInfo();
			key[counter] = i;
			cout << '\n';
			counter++;
		}

	}
	if (counter == 1) {

		cout << "\nThere is no Available Cars to be displayed\n";
		system("pause");
		displayInfo(carsToBeVerified);
	}


	bool ff = false;
	string s = "0";
	int n = 1;
	while (!ff) {
		cout << "Choose car index to show car history or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(carsToBeVerified);
		else if ((Helper::checkDigit(s[0]))) {
			ff = true;
			if (s.size() > 1) {
				if ((Helper::checkDigit(s[1]))) {
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
	if (n >= counter || n <= 0) {
		cout << "unavailabe car id \n";
		system("pause");
		system("cls");
		displayAllCars(carsToBeVerified);
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
				choosenCar.getRentingProcesses()[i]->displayInfo(choosenCar.getModel());
			}
		}
		else {

			cout << "sorry but this car doesn't have any rentingProcesses till now\n";
		}
		system("pause");
		displayAllCars(carsToBeVerified);
	}

}
void AdminView::displayAllUsers(int flag, vector<Car*> carsToBeVerified)
{
	Organization* org = Organization::getInstance();

	// we are displaying allUsers  and onClick on a specific ID we show History for Renter and Cars for Owners
	// flag=3 renters 
	// flag=4 owners

	int counter = 1;
	int i2 = 0;
	vector<int>key(org->allUsers.size() + 100);
	for (auto i : org->allUsers) {
		if (((stoi(i->id) / 100) % 10 < 3 && flag == 3) || (flag == 4 && (stoi(i->id) / 100) % 10 >= 3)) {
			if (counter == 1)
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
		displayInfo(carsToBeVerified);
	}

	bool ff = false;
	string s = "0";
	int n = 1;
	while (!ff) {
		if (flag == 3) {
			cout << "Choose Renter ID to show history or enter \"a\" to go back : ";
		}
		else {
			cout << "Choose Owner ID to show his cars or enter \"a\" to go back : ";

		}
		cin >> s;
		if (s == "a")
			displayInfo(carsToBeVerified);
		else if ((Helper::checkDigit(s[0]))) {
			ff = true;
			if (s.size() > 1) {
				if ((Helper::checkDigit(s[1]))) {
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
			displayAllUsers(flag, carsToBeVerified);
			

		}
	}
	if (n >= counter) {
		cout << "unavailabe person id \n";
		system("pause");
		system("cls");
		displayAllUsers(flag, carsToBeVerified);
	}
	else {
		n = key[n];
		User* choosenRenter = org->allUsers[n];
		system("cls");
		choosenRenter->displayTheUniqueHistory();
		system("pause");
		displayAllUsers(flag, carsToBeVerified);

	}
}

pair<int,int> AdminView::showCarsToBeVerified(vector<Car*> carsToBeVerified)
{
	Organization* org = Organization::getInstance();

	// we are showing cars to be verified and the admin has the right to weather  verify it or refuse it 
	int key[100] = { 0 };
	int k = 1;


	for (int i = 0; i < carsToBeVerified.size(); i++) {

		if (!carsToBeVerified[i]->isSeenByTheAdmin) {
			if (k == 1)
				system("cls");
			cout << k << ": ";
			carsToBeVerified[i]->displayInfo();
			key[k] = i;
			k++;
		}
	}
	if (k == 1) {

		cout << "No Cars to be verified \n\n";
		system("pause");


		displayInfo(carsToBeVerified);
	}

	bool flag = false;
	string s = "0";
	int inp1 = 0;
	while (!flag) {
		cout << "Choose car no to verify or enter \"a\" to go back : ";
		cin >> s;
		if (s == "a")
			displayInfo(carsToBeVerified);
		else if ((Helper::checkDigit(s[0]))) {
			flag = true;
			if (s.size() > 1) {
				if ((Helper::checkDigit(s[1]))) {
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
	if (inp1 >= k)
		cout << "unavailabe car id \n";
	else {
		return verifyCar(org, inp1, key, carsToBeVerified);
	}
}
pair<int,int> AdminView::verifyCar(Organization* org, int inp1, int* key, vector<Car*> carsToBeVerified) {
	inp1 = key[inp1];

	string inp2 = "0";

	while (inp2 != "1" && inp2 != "2") {

		cout << "Do you want to verify it?\n";
		cout << "1- yes\n";
		cout << "2- no\n";
		cin >> inp2;
		if (inp2 == "1") {
			return { stoi(inp2),inp1};
		}
		else if (inp2 == "2") {
			return { stoi(inp2), inp1};
		}
		else {
			cout << "unvalid input please try again\n";
		}
	}

}


int AdminView::displayInfo(vector<Car*> carsToBeVerified)
{


	// the opening UI for the Admin
	int i = 0;
	while (true) {
		system("cls");
		if (i)
			cout << "unvalid input please try again" << endl;
		i++;
		cout << "\t\t\t\tHello ADMIN\n";
		//cout << "total money: " << totalMoney << '\n';
		cout << "1-Cars To be verified\n";
		cout << "2-show all verified Cars\n";
		cout << "3-show all Renters\n";
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
			return 1;

		}
		if (inp == "2") {
			i = 0;
			displayAllCars(carsToBeVerified);
		}
		if (inp == "3" || inp == "4") {
			int x = stoi(inp);
			displayAllUsers(x, carsToBeVerified);
			i = 0;
		}
		if (inp == "5") {
			openingUI();
		}
	}
}
