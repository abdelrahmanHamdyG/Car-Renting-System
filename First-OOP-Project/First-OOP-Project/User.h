#pragma once
#include <string>
#include<vector>
using namespace std;
class Organization;

class User
{
public:
	string id;
	string username;
	string password;
	float totalMoney;
	static int nOfUsers;
public:
	User(string _id, string _username, string _password,int _totalMoney=0);
	User(string _username, string _password);
	bool checkUsernameWithPassword(string _username,string _password);
	virtual void displayInfo(Organization* org);
	static int makeNewID(int i);
	virtual string toBeWrittenInFile();
	virtual void changeMoney(float fees,Organization *org);
	virtual void displayData();
	virtual void displayTheUniqueHistory();


};

