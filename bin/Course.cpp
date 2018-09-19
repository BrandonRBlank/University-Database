//cpp for Courses

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Course.h"

Course::Course(std::string newName, std::string newCRN, std::string newDept)
{
	courseName = newName;
	CRN = newCRN;
	department = newDept;
	std::vector<std::string>StudentsEnrolled;
	std::vector<std::string>TeachersEmployed;
	std::vector<int>StudentsUID;
	std::vector<int>TeachersUID;
	std::vector<char>Grades;
}

std::string Course::getName()
{
	return courseName;
}

std::string Course::getCRN()
{
	return CRN;
}

std::string Course::getDept()
{
	return department;
}

void Course::setGrade(char c) //add new element to end of vector
{
	Grades.push_back(c);
}

void Course::setArray(std::string roster, int i) //array to hold all the info of the course: students, teachers
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

void Course::setArrayUID(int UID, int i) // array to hold all the UID's of the students and teachers
{
	switch(i)
	{
		case(0):
			{
				StudentsUID.push_back(UID);
				break;
			}
		case(1):
			{
				TeachersUID.push_back(UID);
				break;
			}
	}
}

void Course::printStudents() //prints the students in the course
{
	for(int i = 0; i < StudentsEnrolled.size(); i++)
	{
		std::cout << std::left << std::setw(8) << StudentsUID[i] << std::setw(21) << StudentsEnrolled[i] << Grades[i] << std::endl;
	}
}

void Course::printTeachers() //print teacher who teaches the course
{
	for(int i = 0; i < TeachersEmployed.size(); i++)
	{
		std::cout << std::left << std::setw(8) << TeachersUID[i] << std::setw(21) << TeachersEmployed[i] << std::endl;
	}
}

Course::~Course()
{
	
}
