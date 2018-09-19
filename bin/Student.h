//header file for Student

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "Person.h"

class Student : public Person
{
	public:
	Student(int, std::string, int, bool, bool, int, double, std::string);
	bool getCanEnroll();
	int getStatus();
	double getGPA();
	std::vector<std::string> Classes;
	void setClasses(std::string);
	std::string getName();
	std::string getMajorDept();
	std::string getClasses(int);
	void printStudent();
	~Student();
	
	private:
	bool canEnroll;
	int status;
	double GPA;
	std::string majorDept;
};

#endif
