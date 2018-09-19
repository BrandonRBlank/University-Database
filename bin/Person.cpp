//cpp for Person

#include <string>
#include <iostream>
#include <iomanip>
#include "Person.h"

Person::Person()
{
	UID = 9999;
	name = "Teddyy Roosevelt";
	birthday = 19960217 ;
	gender = false;		//True = girl, False = boy
}

Person::Person(int newUID, std::string newName, int newBirthday, bool newGender)
{
	UID = newUID;
	name = newName;
	birthday = newBirthday;
	gender = newGender;
}

int Person::getUID() 
{
	return UID;
}

std::string Person::getName()
{
	return name;
}

int Person::getBirthday()
{
	return birthday;
}

bool Person::getGender()
{
	return gender;
}

void Person::printPerson()
{
	std::cout << std::left << std::setw(7) << getUID() << " ";
	std::cout << std::left << std::setw(17) << getName() << " ";
	std::cout << std::left << std::setw(12) << getBirthday() << " ";
	if(getGender() == true)
		std::cout << std::left << std::setw(10) << "Female";// << std::endl;
	else
		std::cout << std::left << std::setw(10) << "Male";// << std::endl;
}

Person::~Person()
{
	
}
