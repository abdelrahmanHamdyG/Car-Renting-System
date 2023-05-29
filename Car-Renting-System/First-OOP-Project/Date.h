#pragma once
#include<string>
#include <iostream>
#include <ctime>
#include "DateInformation.h"
using namespace std;
class Date {
public:
	DateInformation dateInformation;
	Date();
	Date(int _minutes, int _hour, int _day, int _month, int _year);
	static Date getCurrentDate();
	void displayDate();
	Date(string _date);
	string getString1();
	static float getDuration(Date _beginningDate);



};
