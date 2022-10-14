/*
	Name: 	Daniel Morales
	EUID:	dm0698
	Class: 	CSCE 3550.001 Foundationd of Cybersecurity
	
	Reference Monitor secure program following the Biba Model
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Subject.h"
#include "Object.h"
#include "RefMon.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	// Checks to make sure the right number of args are passed
	if (argc != 2) {
		cout << "usage: ./secureBiba <instrList>\n";
		exit(1);
	}
	
	string filename = argv[1];
	
	ifstream fin;
	fin.open(filename);
	
	// File guards
	if(fin.fail()) {
		cout << "Unable to open " << filename << " file. Terminantting program..." << endl;
		exit(1);
	}
	
	RefMon rMonitor;
	string cmdLine;
	
	while (getline(fin, cmdLine)) { // Reads in one line at a time from the file
		
		stringstream line(cmdLine); // string stream to pick out individual arguments
		string arg;
		vector<string> cmd; // vector to store arguments
		
		while (line >> arg) cmd.push_back(arg); // gets number of args
		int arg_c = cmd.size();
		arg = cmd[0];
		
		int instrSuccess = 0;
		if (arg.compare("addsub") == 0 && arg_c == 3) { // addsub
			instrSuccess = rMonitor.addSubject(cmd);
		}
		else if (arg.compare("addobj") == 0 && arg_c == 3) { // addobj
			instrSuccess = rMonitor.addObject(cmd);
		}
		else if (arg.compare("deposit") == 0 && arg_c == 4) { // deposit
			if (strtof(cmd[3].c_str(), NULL) != 0)
				instrSuccess = rMonitor.executeDeposit(cmd);
			else
				instrSuccess = 0;
		}
		else if (arg.compare("withdraw") == 0 && arg_c == 4) { // withdraw
			if (strtof(cmd[3].c_str(), NULL) != 0)
				instrSuccess = rMonitor.executeWithdraw(cmd);
			else
				instrSuccess = 0;
		}
		else if (arg.compare("query") == 0 && arg_c == 3) { // query
			instrSuccess = rMonitor.executeQuery(cmd);
		}
		else if (arg.compare("status") == 0 && arg_c == 1) { // status
			instrSuccess = rMonitor.printState();
		}
		
		if (instrSuccess == 0) { // statement for bad instructions
			cout << "Bad Instruction : " << cmdLine << endl;
		}
	}
	
	rMonitor.printStateFinal(); // final print statement
	
	return 0;
}