// Reference Monitor Class

#ifndef __REFMON__
#define __REFMON__

#include "Object.h"
#include "Subject.h"
#include <iostream>
#include <vector>

using namespace std;

class RefMon {
private:
	enum SecurityLevel {LOW, MEDIUM, HIGH};
	struct mSubject {
		Subject* sub = NULL;
		SecurityLevel clearance;
	};
	struct mObject {
		Object* obj = NULL;
		SecurityLevel clearance;
	};
	vector<mObject> objects;
	vector<mSubject> subjects;
public: // Return interger to help keep track of the vaious states (granted, denied, bad instruction)
	~RefMon(); // destructor to free memory
	int addSubject(vector<string>);
	int addObject(vector<string>);
	int executeQuery(vector<string>);
	int executeDeposit(vector<string>);
	int executeWithdraw(vector<string>);
	int printState();
	void printStateFinal(); // Special Print statement for the very end
};

#endif // __REFMON__