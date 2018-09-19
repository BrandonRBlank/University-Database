//header file for teacher

#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "Person.h"

class Teacher : public Person
{
	public:
	Teacher(int, std::string, int, bool, bool, int, std::string);
	bool getCanTeach();
	int getTeachType();
	std::string getName();
	std::string getDept();
	void printTeacher();
	~Teacher();
		
	private:
	bool canTeach;
	int teachType;
	std::string dept;
	
};

#endif
