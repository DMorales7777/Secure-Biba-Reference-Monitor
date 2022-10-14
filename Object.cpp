// Defining Setters and Getters for Object Class
#include "Object.h"

Object::Object(std::string name) {
	this->name = name;
}

std::string Object::getName() {
	return name;
}

float Object::getBalance() {
	return balance;
}

void Object::setName(std::string name) {
	this->name = name;
}

void Object::setBalance(float balance) {
	this->balance = balance;
}
