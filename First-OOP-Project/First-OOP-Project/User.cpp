#include "User.h"
#include<iostream>


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
	

void User::displayInfo(Organization* org)
{
	cout << "This shouldn't be called\n";
}

int User::makeNewID(int i)
{	

	int h = 0;
	if (i == 1) {

		h = nOfUsers + 100;
	}
	else {
		h = nOfUsers + 300;
	}
	return h;

}

string User::toBeWrittenInFile()
{
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

void User::changeMoney(float fees,Organization *org)
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
}



	

