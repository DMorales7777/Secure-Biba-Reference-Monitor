#include <iomanip>
#include "RefMon.h"
#define DENIED 2
#define SUCCESS 1
#define BADINSTR 0

RefMon::~RefMon() { // Frees memory for structs used
	for (int i=0; i<subjects.size(); i++) delete subjects[i].sub;
	for (int i=0; i<objects.size(); i++) delete objects[i].obj;
}

int RefMon::addSubject(vector<string> input) {
	string inName = input[1];
	string inClearance_str = input[2];
	
	bool nameInList = false;
	for (int i=0; i<subjects.size(); i++) { // verifies that name is unique
		if (subjects[i].sub->getName().compare(inName) == 0) {
			nameInList = true;
			break;
		}
	}
	
	bool validSecuiryLevel = true;
	SecurityLevel inClearance;
	
	// converts security level to enum
	if (inClearance_str.compare("LOW") == 0) inClearance = LOW;
	else if (inClearance_str.compare("MEDIUM") == 0) inClearance = MEDIUM;
	else if (inClearance_str.compare("HIGH") == 0) inClearance = HIGH;
	else validSecuiryLevel = false;
	
	// if not valid, returns bad instruction
	if (nameInList || !validSecuiryLevel) return BADINSTR;
	
	// temp object is created and passed onto struct dynamically
	mSubject temp;
	temp.sub = new Subject(inName);
	temp.clearance = inClearance;
	
	subjects.push_back(temp);
	
	// display message
	cout << "Subject Added   : addobj " << inName << 
			" " << inClearance_str << endl;
	
	return SUCCESS;
}

int RefMon::addObject(vector<string> input) {	
	string inName = input[1];
	string inClearance_str = input[2];
	
	bool nameInList = false;
	for (int i=0; i<objects.size(); i++) { // verifies that name is unique
		if (objects[i].obj->getName().compare(inName) == 0) {
			nameInList = true;
			break;
		}
	}
	
	bool validSecuiryLevel = true;
	SecurityLevel inClearance;
	
	// converts security level to enum
	if (inClearance_str.compare("LOW") == 0) inClearance = LOW;
	else if (inClearance_str.compare("MEDIUM") == 0) inClearance = MEDIUM;
	else if (inClearance_str.compare("HIGH") == 0) inClearance = HIGH;
	else validSecuiryLevel = false;
	
	// if not valid, returns bad instruction
	if (nameInList || !validSecuiryLevel) return BADINSTR;
	
	// temp object is created and passed onto struct dynamically
	mObject temp;
	temp.obj = new Object(inName);
	temp.clearance = inClearance;
	
	objects.push_back(temp);
	
	// display message
	cout << "Object Added    : addobj " << inName << 
			" " << inClearance_str << endl;
	
	return SUCCESS;
}

int RefMon::executeQuery(vector<string> input) {
	int sIndex;
	int oIndex;
	string eSub = input[1];
	string eObj = input[2];
	
	bool nameInList = false;
	for (int i=0; i<subjects.size(); i++) { // verifies that name exists
		if (subjects[i].sub->getName().compare(eSub) == 0) {
			nameInList = true;
			sIndex = i;
			break;
		}
	}
	
	if (!nameInList) return BADINSTR; // if not valid, returns bad instruction
	
	bool objInList = false;
	for (int i=0; i<objects.size(); i++) { // verifies that obj exists
		if (objects[i].obj->getName().compare(eObj) == 0) {
			objInList = true;
			oIndex = i;
			break;
		}
	}
	
	if (!objInList) return BADINSTR; // if not valid, returns bad instruction
	
	// NO READ DOWN
	if (subjects[sIndex].clearance <= objects[oIndex].clearance) { // access granted
		subjects[sIndex].sub->setBalance(objects[oIndex].obj->getBalance());
		cout << "Access Granted  : " << subjects[sIndex].sub->getName() << 
			" queries " << objects[oIndex].obj->getName() << endl;
		return SUCCESS;
	}
	else { // access denied
		cout << "Access Denied   : query " << subjects[sIndex].sub->getName() << 
			" " << objects[oIndex].obj->getName() << endl;
		return DENIED;
	}
	
}

int RefMon::executeDeposit(vector<string> input) {
	int sIndex;
	int oIndex;
	string eSub = input[1];
	string eObj = input[2];
	float deposit = stof(input[3]);
	
	bool nameInList = false;
	for (int i=0; i<subjects.size(); i++) { // verifies that name exists
		if (subjects[i].sub->getName().compare(eSub) == 0) {
			nameInList = true;
			sIndex = i;
			break;
		}
	}
	
	if (!nameInList) return BADINSTR; // if not valid, returns bad instruction
	
	bool objInList = false;
	for (int i=0; i<objects.size(); i++) { // verifies that obj exists
		if (objects[i].obj->getName().compare(eObj) == 0) {
			objInList = true;
			oIndex = i;
			break;
		}
	}
	
	if (!objInList) return BADINSTR; // if not valid, returns bad instruction
	
	//NO WRITE UP
	if (subjects[sIndex].clearance >= objects[oIndex].clearance) { // access granted
		float newBalance = (objects[oIndex].obj->getBalance()) + deposit;
		objects[oIndex].obj->setBalance(newBalance);
		
		cout << "Access Granted  : " << subjects[sIndex].sub->getName() << 
			" deposits $" << deposit << " to " <<objects[oIndex].obj->getName() << endl;
		return SUCCESS;
	}
	else { // access denied
		cout << "Access Denied   : deposit " << eSub << " " 
			<< eObj << " " << deposit << endl;
		return DENIED;
	}
	
}

int RefMon::executeWithdraw(vector<string> input) {
	int sIndex;
	int oIndex;
	string eSub = input[1];
	string eObj = input[2];
	float withdraw = stof(input[3]);
	
	bool nameInList = false;
	for (int i=0; i<subjects.size(); i++) { // verifies that name exists
		if (subjects[i].sub->getName().compare(eSub) == 0) {
			nameInList = true;
			sIndex = i;
			break;
		}
	}
	
	if (!nameInList) return BADINSTR; // if not valid, returns bad instruction
	
	bool objInList = false;
	for (int i=0; i<objects.size(); i++) { // verifies that obj exists
		if (objects[i].obj->getName().compare(eObj) == 0) {
			objInList = true;
			oIndex = i;
			break;
		}
	}
	
	if (!objInList) return BADINSTR; // if not valid, returns bad instruction
	
	//NO WRITE UP
	if (subjects[sIndex].clearance >= objects[oIndex].clearance) { // access granted
		float newBalance = (objects[oIndex].obj->getBalance()) - withdraw;
		objects[oIndex].obj->setBalance(newBalance);
		
		cout << "Access Granted  : " << subjects[sIndex].sub->getName() << 
			" withdraws $" << withdraw << " to " <<objects[oIndex].obj->getName() << endl;
		return SUCCESS;
	}
	else { // access denied
		cout << "Access Denied   : withdraw " << eSub << " " 
			<< eObj << " " << withdraw << endl;
		return DENIED;
	}
}

int RefMon::printState() {
	cout.precision(2);
	cout << fixed;
	
	cout << "+---------current state---------+\n";
	cout << "|-subject-|--level--|--balance--|\n";
	
	// For loop for all subjects
	for (int i=0; i<subjects.size(); i++) {
		string strLevel;
		switch (subjects[i].clearance) {
			case LOW: strLevel = "LOW"; break;
			case MEDIUM: strLevel = "MEDIUM"; break;
			case HIGH: strLevel = "HIGH"; break;
			default: break;
		}
		
		cout << "| " << setw(7) << subjects[i].sub->getName() << 
		" | " << setw(7) << strLevel <<
		" | " << setw(9) << subjects[i].sub->getBalance() << " |\n";
	}
	cout << "|-subject-|--level--|--balance--|\n";
	// For loop for all objects
	for (int i=0; i<objects.size(); i++) {
		string strLevel;
		switch (objects[i].clearance) {
			case LOW: strLevel = "LOW"; break;
			case MEDIUM: strLevel = "MEDIUM"; break;
			case HIGH: strLevel = "HIGH"; break;
			default: break;
		}
		
		cout << "| " << setw(7) << objects[i].obj->getName() << 
		" | " << setw(7) << strLevel <<
		" | " << setw(9) << objects[i].obj->getBalance() << " |\n";
	}
	
	cout << "+-------------------------------+\n";
	
	return SUCCESS;
}

void RefMon::printStateFinal() {
	cout.precision(2);
	cout << fixed;
	
	cout << "+----------final state----------+\n";
	cout << "|-subject-|--level--|--balance--|\n";
	
	// For loop for all subjects
	for (int i=0; i<subjects.size(); i++) {
		string strLevel;
		switch (subjects[i].clearance) {
			case LOW: strLevel = "LOW"; break;
			case MEDIUM: strLevel = "MEDIUM"; break;
			case HIGH: strLevel = "HIGH"; break;
			default: break;
		}
		
		cout << "| " << setw(7) << subjects[i].sub->getName() << 
		" | " << setw(7) << strLevel <<
		" | " << setw(9) << subjects[i].sub->getBalance() << " |\n";
	}
	cout << "|-subject-|--level--|--balance--|\n";
	// For loop for all objects
	for (int i=0; i<objects.size(); i++) {
		string strLevel;
		switch (objects[i].clearance) {
			case LOW: strLevel = "LOW"; break;
			case MEDIUM: strLevel = "MEDIUM"; break;
			case HIGH: strLevel = "HIGH"; break;
			default: break;
		}
		
		cout << "| " << setw(7) << objects[i].obj->getName() << 
		" | " << setw(7) << strLevel <<
		" | " << setw(9) << objects[i].obj->getBalance() << " |\n";
	}
	
	cout << "+-------------------------------+\n";
}
