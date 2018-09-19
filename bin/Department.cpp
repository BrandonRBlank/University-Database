//cpp for Department

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Department.h"

Department::Department(std::string name)
{
	departName = name;
	std::vector<std::string>StudentsEnrolled; //students in the dept
	std::vector<std::string>TeachersEmployed; //teachers in the dept
}

std::string Department::getDept()
{
	return departName;
}

void Department::setArray(std::string roster, int i) //array to hold all the info of dept: students and teachers
{
	switch(i)
	{
		case(0):
			{
				StudentsEnrolled.push_back(roster);
				break;
			}
		case(1):
			{
				TeachersEmployed.push_back(roster);
				break;
			}
	}
}

void Department::printStudents() //print students in dept
{
	for(int i = 0; i < StudentsEnrolled.size(); i++)
	{
		std::cout << StudentsEnrolled[i] << std::endl;
	}
}

void Department::printTeachers() //prints teachers in dept
{
	for(int i = 0; i < TeachersEmployed.size(); i++)
	{
		std:: cout << TeachersEmployed[i] << std::endl;
	}
}

Department::~Department()
{
	
}
