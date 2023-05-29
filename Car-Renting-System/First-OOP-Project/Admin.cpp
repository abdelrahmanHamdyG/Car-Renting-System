#include "Admin.h"
#include "Organization.h"
#include<vector>
#include "openingUI.h"
#include <iostream>
using namespace std;

float Admin::totalMoney = 0;

void Admin::launch() {
	adminModel = new AdminModel();
	adminView = new AdminView();
	adminModel->initializeCarsToBeVerified();
	int input = adminView->displayInfo(adminModel->getCars());
	executeUserCmd(input);
}
void Admin::executeUserCmd(int input) {
	if (input == 1) {
		pair<int, int> input = adminView->showCarsToBeVerified(adminModel->getCars());
		if (input.first)
			adminModel->confirm(input.second);
		else
			adminModel->reject(input.second);
	}
}