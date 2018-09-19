//header file for Department

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

class Department
{
	public:
	Department(std::string);
	std::string getDept();
	std::string departName;
	void setArray(std::string, int);
	std::vector<std::string> StudentsEnrolled;
	std::vector<std::string> TeachersEmployed;
	void printStudents();
	void printTeachers();
	~Department();
};

#endif
