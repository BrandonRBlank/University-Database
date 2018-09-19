//Header file for Courses

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
	public:
	Course(std::string, std::string, std::string);
	std::string courseName;
	std::string CRN;
	std::string department;
	std::vector<std::string> StudentsEnrolled; //vector for students who are in a course
	std::vector<std::string> TeachersEmployed; //teachers who teach the course
	std::vector<int> StudentsUID; //UID for students in the class
	std::vector<int> TeachersUID; //UID for teacher who teach the course
	std::vector<char> Grades; //grades of the students in the course
	std::string getName();
	std::string getCRN();
	std::string getDept();
	void setGrade(char);
	void setArray(std::string, int);
	void setArrayUID(int, int); 
	void printStudents();
	void printTeachers();
	~Course();
};


#endif
