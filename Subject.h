//Subject Class
#ifndef __SUBJECTS__
#define __SUBJECTS__

#include <string>

class Subject {
private:
	std::string name;
	float balance = 0.00;
	
public:
	Subject(std::string);
	std::string getName();
	float getBalance();
	void setName(std::string);
	void setBalance(float);
};

#endif //__SUBJECTS__