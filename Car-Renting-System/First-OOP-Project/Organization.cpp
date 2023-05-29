#include "Organization.h"
#include"Helper.h"

using namespace std;


Organization::Organization(){
	allNotifications.reserve(200);
	allRentingProcesses.reserve(200);
	allCars.reserve(200);
	
}

Organization* Organization::instance = NULL;


Organization* Organization::getInstance()
{
	
	if (instance == NULL) {

		instance = new Organization();

	}

	return instance;
}

void Organization::readFiles()
{

	/*
	
	We are reading all users and adding their specific attributes depending on wether the user is Renter or Owner

	*/
	ifstream readFile("Users.txt");
	int id;
	float totalMoney;
	string currentCar, rentingProcessString,carString,inboxString, name, password;

	
	allNotifications = readNotifications();
	allRentingProcesses = readRentingProcesss();
	allCars = readCars();


	
	while (readFile.peek() != EOF) {
		User* user;
		readFile >> id;
		readFile >> name;
		readFile >> password;
		readFile >> totalMoney;

		if ((id/Helper::STARTING_ID_OF_RENTERS) % 10 <3) {
			//Renter
			readFile>> currentCar;
			readFile>> rentingProcessString;
			user = readRenter(id, name, password, totalMoney, currentCar, rentingProcessString);
		}
		else {
			//Owner
			readFile >> carString;
			readFile >> inboxString;
			user = readOwner(id, name, password, totalMoney, carString, inboxString);
	
		}

		allUsers.push_back(user);
	}
	readFile.close();
}
User* Organization::readRenter(int id, string name, string password, float totalMoney, string currentCar, string rentingProcessString) {
	vector<string>RentingProcessAsId = formatAsVectorOfString(rentingProcessString);
	vector<RentingProcess*>rp;
	for (int i = 0; i < RentingProcessAsId.size(); i++) {
		RentingProcess  rentingProcess = allRentingProcesses[stoi(RentingProcessAsId[i])];
		rp.push_back(&allRentingProcesses[stoi(RentingProcessAsId[i])]);
	}
	return new Renter(to_string(id), name, password, totalMoney, currentCar, rp);
}

User* Organization::readOwner(int id, string name, string password, float totalMoney, string carString, string inboxString) {
	vector<string>carIdsAsVector = formatAsVectorOfString(carString);
	vector<string>inboxAsVector = formatAsVectorOfString(inboxString);
	vector<Car*>userCar;
	vector<Notification*>userInbox;
	for (int i = 0; i < allNotifications.size(); i++) {
		for (int j = 0; j < inboxAsVector.size(); j++) {
			if (allNotifications[i].checkId(inboxAsVector[j])) {
				userInbox.push_back(&allNotifications[i]);
			}
		}
	}
	for (int i = 0; i < carIdsAsVector.size(); i++) {
		userCar.push_back(&allCars[stoi(carIdsAsVector[i])]);
	}
	return new Owner(to_string(id), name, password, totalMoney, userCar, userInbox);
}

void Organization::writeFiles()
{
	// we are writing to the files 
	ofstream myFile;
	myFile.open("Users.txt");
	for (int i = 0; i < allUsers.size(); i++) {
		if (i)
			myFile<< '\n';
		string s=allUsers[i]->toBeWrittenInFile();
		myFile << s;
	}
	myFile.close();

	ofstream carsFiles;
	carsFiles.open("Cars.txt");
	for (int i = 0; i < allCars.size(); i++) {
		
		if (i)
			carsFiles << '\n';
		string s = allCars[i].getWhatToBeWrittenInFile();
		carsFiles << s;
		
		
	}
	carsFiles.close();

	ofstream rentingFile;
	rentingFile.open("RentingProcesses.txt");

	for (int i = 0; i < allRentingProcesses.size(); i++) {
		if (i)
			rentingFile << '\n';
		string s=allRentingProcesses[i].getWhatToBeWrittenInFile();
		rentingFile << s;

	}
	rentingFile.close();
	
	ofstream notificationsFile;
	notificationsFile.open("Notifications.txt");
	
	for (int i = 0; i < allNotifications.size(); i++) {
		if (i)
			notificationsFile << '\n';

		string s= allNotifications[i].getWhatToBeWrittenInFile();
		notificationsFile << s;

	}
	notificationsFile.close();
	
	


}



vector<Car> Organization::readCars()
{

	//we are readingCars from cars.txt

	vector<Car>v;
	v.reserve(100);
	ifstream readFile("Cars.txt");
	string id;
	string model;
	string carOwnerID;
	vector<RentingProcess*>RentingProcesses; string RentingProcessesAsString; vector<string>RentingProcessAsStringVector;


	int horsePower;
	int torque;
	string carType;
	string gear;
	int maxSpeed;
	bool isRented;
	int rentingPrice;
	bool isVerified;
	float commision;
	float totalMoneyGotFromTheCar;
	bool isSeenByTheAdmin;

	int i = 0;


	
	while (readFile.peek() != EOF) {
		RentingProcesses.clear();
		readFile >> id;
		readFile >> model;
		readFile >> carOwnerID;
		readFile >> RentingProcessesAsString;
		
		readFile >> horsePower;
		readFile >> torque;
		readFile >> carType;
		readFile >> gear;
		
		readFile >> maxSpeed;
		readFile >> isRented;
		readFile >> rentingPrice;
		readFile >> isVerified;

		readFile >> commision;
		readFile >> totalMoneyGotFromTheCar;
		readFile >> isSeenByTheAdmin;

		Car car;
		car.setID(id);
		car.setModel(model);
		car.setCarOwnerID(carOwnerID);
		RentingProcessAsStringVector = formatAsVectorOfString(RentingProcessesAsString);
		for (auto i : RentingProcessAsStringVector) {
			RentingProcesses.push_back(&allRentingProcesses[stoi(i)]);

		}
		car.setRentingProcesses(RentingProcesses);

		car.setHorsePower(horsePower);

		car.setTorque(torque);

		car.setCarType(carType);
		car.setGear(gear);
		
		
		car.setMaxSpeed(maxSpeed);
		car.setRentingStatus(isRented);
		
		car.setRentingPrice(rentingPrice);
		
		car.setVerification(isVerified);
		car.setCommision(commision);
		car.totalMoneyGotFromTheCar = totalMoneyGotFromTheCar;
		Admin::totalMoney += (car.totalMoneyGotFromTheCar * (1-commision));
		car.isSeenByTheAdmin = isSeenByTheAdmin;

		v.push_back(car);

		i++;
	}

	return v;
}




User* Organization::signUp(string _userName, string _password, int response)
{

	// we are creating a new ID and returning instance of user type to apply the polymorphism concept
	// implementing factory design Pattern 
	User* user;
	int id = User::makeNewID(response);
	//1 renter 2 owner
	if (response == 1) {
		
		user = new Renter( to_string(id),_userName,_password,0);
	}
	else {
		user = new Owner(to_string(id),_userName,_password,0);
	}

	allUsers.push_back(user);
	writeFiles();
	return user;

}


User* Organization::authenticate(string userName, string password)
{
	// we are making Authentication
	for (auto i : allUsers) {
		if (i->checkUsernameWithPassword(userName,password)) {
			
			return i;
		}
	}
	
	return NULL;

}

vector<string> Organization::formatAsVectorOfString(string s)
{
	// we are reading from the file a form like this {15,16,5};
	// and return it as vectorOfString v[0]="15" v[1]="16" v[2]="5"

	string str = s.substr(1, s.length() - 2);
	vector<string>V;
	stringstream  ss(str);

	while (ss.good()) {
		string sub;
		getline(ss, sub, ',');
		V.push_back(sub);
	}

	if (V[0] == "")
		V.clear();

	return V;
}

vector<Notification> Organization::readNotifications	(){

	// we are reading Notifications


	vector <Notification> notifications;
	notifications.reserve(100);
	ifstream file("Notifications.txt");
	string fields[5];
	// type - id - car  - renter  -  isVerified - date

	if (file.is_open()) {
		while (file >> fields[0] >> fields[1] >> fields[2] >> fields[3] >> fields[4]) {
			Notification n(fields[0], fields[1], fields[2], fields[3], fields[4]);
			notifications.push_back(n);
		}
		file.close();
	}
	else {
		//cout << "Unable to open file" << endl;
	}

	return notifications;
}

vector<RentingProcess> Organization::readRentingProcesss() {
	// we are reading RentingProcesses from RentingProcesses.txt
	vector<RentingProcess> rp;
	rp.reserve(100);
	ifstream readf("RentingProcesses.txt");
	string id;
	string carOwner;
	string carRenter;
	
	string beginningDateString;
	float cost;
	float duration;
	bool isRunning = 1;
	string car_id;
	while (readf.peek() != EOF) {
		readf >> id;
		readf >> carOwner;
		readf >> carRenter;

		readf >> beginningDateString;
		Date date(beginningDateString);
		//CAR_ID
		readf >> cost >> duration>>isRunning>>car_id;

		
		RentingProcess r(id, carOwner,carRenter, date, cost, duration, isRunning,car_id);
		rp.push_back(r);
	}

	readf.close();
	return rp;
	
}



