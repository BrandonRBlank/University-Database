//cpp for student

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Student.h"

Student::Student(int UID, std::string name, int birthday, bool gender, bool newCanEnroll, int newStatus, 
				double newGPA, std::string newMajorDept) : Person(UID, name, birthday, gender)
{
	canEnroll = newCanEnroll;
	status = newStatus;
	GPA = newGPA;
	majorDept = newMajorDept;
	std::vector<std::string>Classes;
}

bool Student::getCanEnroll()
{
	return canEnroll;
}

int Student::getStatus()
{
	return status;
}

double Student::getGPA()
{
	return GPA;
}

void Student::setClasses(std::string roster)
{
	Classes.push_back(roster);
}

std::string Student::getName()
{
	return name;
}

std::string Student::getMajorDept()
{
	return majorDept;
}

std::string Student::getClasses(int a)
{
	return Classes[a];
}

void Student::printStudent() //prints all the basic info of a student
{
	printPerson();
		
	if(getStatus() == 0)
		std::cout << std::left << std::setw(11) << "Graduate" << " ";
	else if(getStatus() == 1)
		std::cout << std::left << std::setw(11) << "UnderGrad" << " ";
	else if(getStatus() == 2)
		std::cout << std::left << std::setw(11) << "RA" << " ";
	else
		std::cout << std::left << std::setw(11) << "TA" << " ";
		
	std::cout << std::left << std::setw(7) << getGPA();
	std::cout << std::left << getMajorDept() << std::endl;
}

Student::~Student()
{
	
}
