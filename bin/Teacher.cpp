//cpp file for Teacher

#include <string>
#include <iomanip>
#include <iostream>
#include "Teacher.h"

Teacher::Teacher(int UID, std::string name, int birthday, bool gender, bool newCanTeach, int newTeachType, 
				std::string newDept) : Person(UID, name, birthday, gender)
{
	canTeach = newCanTeach;
	teachType = newTeachType;
	dept = newDept;
}

bool Teacher::getCanTeach()
{
	return canTeach;
}

int Teacher::getTeachType()
{
	return teachType;
}

std::string Teacher::getDept()
{
	return dept;
}

std::string Teacher::getName()
{
	return name;
}

void Teacher::printTeacher() //prints teacher info
{
	printPerson(); //basic info
	
	if(getTeachType() == 1) //prints type of teacher
		std::cout << std::left << std::setw(11) << "Lecturer" << " ";
	else if(getTeachType() == 2)
		std::cout << std::left << std::setw(11) << "Adjunct" << " ";
	else
		std::cout << std::left << std::setw(11) << "Professor" << " ";
		
	std::cout << std::left << std::setw(8) << getDept() << std::endl; //prints dept
}

Teacher::~Teacher()
{

	
}

