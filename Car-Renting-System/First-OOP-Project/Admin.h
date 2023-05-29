#pragma once
#include "AdminModel.h"
#include "AdminView.h"
class AdminModel;
class AdminView;
class Organization;
class Admin
{
public:
	AdminModel* adminModel;
	AdminView* adminView;
	static float totalMoney;
	void launch();
	void executeUserCmd(int input);

};

