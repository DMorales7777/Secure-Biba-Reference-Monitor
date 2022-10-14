// Defining Setters and Getters for Subject Class
#include "Subject.h"

Subject::Subject(std::string name) {
	this->name = name;
}

std::string Subject::getName() {
	return name;
}

float Subject::getBalance() {
	return balance;
}

void Subject::setName(std::string name) {
	this->name = name;
}

void Subject::setBalance(float balance) {
	this->balance = balance;
}
