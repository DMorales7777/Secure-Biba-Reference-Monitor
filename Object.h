// Object Class
#ifndef __OBJECT__
#define __OBJECT__

#include <string>

class Object {
private:
	std::string name;
	float balance = 0.00;
	
public:
	Object(std::string);
	std::string getName();
	float getBalance();
	void setName(std::string);
	void setBalance(float);
};

#endif //__OBJECT__