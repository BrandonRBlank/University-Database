//Header file for Person

#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
	public:
	Person();
	Person(int, std::string, int, bool);
	int getUID();
	std::string getName();
	int getBirthday();
	bool getGender();
	void printPerson();
	~Person();
	
	protected:
	int UID;
	std::string name;
	int birthday;
	bool gender;
};
#endif
