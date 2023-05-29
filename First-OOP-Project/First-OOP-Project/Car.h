#pragma once
#include<string>
#include<vector>
#include "RentingProcess.h"
using namespace std;



class Car
{
private:

		string model;
		string carOwnerID;
		vector<RentingProcess*>RentingProcesses;

		int horsePower;
		int torque;
		string carType;
		string gear;
		int maxSpeed;
		bool isRented;
		int rentingPrice;
		bool isVerified;
		float commision;
	
public:
	string ID;
	float totalMoneyGotFromTheCar;
	bool isSeenByTheAdmin;
	Car();
	Car(string _model, int _maxSpeed, int _rentingPrice,vector<RentingProcess*>_rentingProcesses);
	void setIsRented();
	bool getIsRented();
	void displayInfo();
	string getModel();
	string getID();
	string getCarOwnerID();
	int getHorsePower();
	int getTorque();
	string getGear();
	string getCarType();
	int getRentingPrice();
	int getMAxSpeed();
	bool getVerification();
	bool getRentingStatus();
	float getCommision();
	vector<RentingProcess*> getRentingProcesses();
	string getWhatToBeWrittenInFile();
	

	void setModel(string m);
	void setID(string id);
	void setCarOwnerID(string idd);
	void setHorsePower(int hp);
	void setTorque(int tor);
	void setGear(string g);
	void setCarType(string t);
	void setRentingPrice(int p);
	void setMaxSpeed(int s);
	void setVerification(bool v);
	void setRentingStatus(bool r);
	void setCommision(float c);
	void getCarInput(int _id,int _carOwnerID);
	void setRentingProcesses(vector<RentingProcess*> _rps);
	void pushToRentingProcesses(RentingProcess* rp);
	
	
};