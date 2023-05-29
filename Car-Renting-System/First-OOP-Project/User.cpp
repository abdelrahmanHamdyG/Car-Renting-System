#include "User.h"
#include"Helper.h"
#include<iostream>


// replacing magic numbers with constants

int User::nOfUsers = 0;
User::User(string _id, string _username, string _password,int _totalMoney)
{

	id = _id;
	username = _username;
	password = _password;
	totalMoney = _totalMoney;
	nOfUsers++;
}

User::User(string _username, string _password)
{
	username = _username;
	password = _password;
	totalMoney = 0;
	nOfUsers++;
}

bool User::checkUsernameWithPassword(string _username, string _password)
{
	if (this->username == _username && this->password == _password)
		return true;
		
	return false;
}
	

void User::displayInfo()
{
	// a virtual Function that displays the openning UI of owner or renter 
	
	cout << "This shouldn't be called\n";
}

int User::makeNewID(int i)
{	

	int h = 0;
	if (i == 1) {

		h = nOfUsers + Helper::STARTING_ID_OF_RENTERS;
		// replacing magic numbers with constants
	}
	else {
		h = nOfUsers + Helper::STARTING_ID_OF_OWNERS;
		// replacing magic numbers with constants
	}
	return h;

}

string User::toBeWrittenInFile()
{
	// virtual function that get what to be writteb in file
	string s;
	s += this->id;
	s += " ";
	s += username;
	s += " ";
	s += password;
	s += " ";
	s += to_string(totalMoney);
	s += " ";
	return s;


}

void User::changeMoney(float fees)
{
	totalMoney += fees;
}

void User::displayData()
{
	cout << "name:" << username<<'\n';
	cout << "total money:" << totalMoney << '\n';


}

void User::displayTheUniqueHistory()
{
	// virtual function
	cout << "This shouldn't be called\n";

}



	

