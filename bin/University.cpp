//Main driver program


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <iomanip>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Course.h"

using namespace std;

int main(void)
{
	int ID;
	string fName;
	string lName;
	int bDay;
	bool sex;
	bool enroll;
	int grad;
	double GPA;
	string dept;
	int i = 0; //counters
	int k = 0;
	int j;
	int l;
	bool mainLoop = true; //flag for main menu selection
	int switchLoop;
	int deptLoop;
	int position;
	int overflow;
	bool teach;
	bool courseLoop = true; //flag for course selection
	string CRN;
	string cName;
	string courseData;
	string courseFind;
	size_t found;
	string deptName;
	string courseSelect;
	string deptSelect;
	string line;
	//vectors to hold info to print
	vector<Student*> studentsEnrolled;
	vector<Teacher*> teachersEmployed;
	vector<Course*> coursesAvailible;
	vector<Department*> deptTypes;

//---------------Course.txt read in----------------------------------------------------------------
	   	
   	ifstream courses("Course.txt", ios::in);
    if(!courses)
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
    while(courses >> cName >> CRN >> dept)
    {
        coursesAvailible.push_back(new Course(cName, CRN, dept));
    }
    courses.close();

//---------------Teacher.txt read in----------------------------------------------------------------
	ifstream teachers("Teacher.txt", ios::in);
    if(!teachers)
    {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
 
    teachers >> ID >> fName >> lName >> bDay >> sex >> teach >> position >> dept;
    teachersEmployed.push_back(new Teacher(ID, fName + " " + lName, bDay, sex, teach, position, dept));
    
	while(getline(teachers, line))
	{
    	teachers >> ID >> fName >> lName >> bDay >> sex >> teach >> position >> dept;
    	teachersEmployed.push_back(new Teacher(ID, fName + " " + lName, bDay, sex, teach, position, dept));
	}
	overflow = teachersEmployed.size();
	teachersEmployed.erase(teachersEmployed.begin() + overflow - 1); //prints the last element twice, this gets rid of the duplicate

	for(i = 0; i < coursesAvailible.size(); i++)
	{
		l = 0;
		courseFind = coursesAvailible[i]->getCRN();
		
		teachers.clear();
		teachers.seekg(0, ios::beg);
		while(getline(teachers, courseData)) //info for teachers who teach a course are put into an array
		{
			found = courseData.find(courseFind);
			if(found != string::npos)
			{
				coursesAvailible[i]->setArray(teachersEmployed[l]->getName(), 1);
				coursesAvailible[i]->setArrayUID(teachersEmployed[l]->getUID(), 1);
			}
			l++;
		}
	}
    teachers.close();
   	
 //--------------Department.txt read in----------------------------------------------------------------  	
	ifstream departments("Department.txt", ios::in);
	if(!departments)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	while(departments >> deptName)
	{
		deptTypes.push_back(new Department(deptName));
	}
	departments.close();
	
//---------------Student.txt read in----------------------------------------------------------------	
	ifstream students("Student.txt", ios::in);
    if(!students)
    {
    	cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
    }

	students >> ID >> fName >> lName >> bDay >> sex >> enroll >> grad >> GPA >> dept;
    studentsEnrolled.push_back(new Student(ID, fName + " " + lName, bDay, sex, enroll, grad, GPA, dept));
    
	while(getline(students, line)) 
	{
    	students >> ID >> fName >> lName >> bDay >> sex >> enroll >> grad >> GPA >> dept;
    	studentsEnrolled.push_back(new Student(ID, fName + " " + lName, bDay, sex, enroll, grad, GPA, dept));
	}
	overflow = studentsEnrolled.size();
	studentsEnrolled.erase(studentsEnrolled.begin() + overflow - 1);

	for(i = 0; i < coursesAvailible.size(); i++) //finds courses students are taking and stores them into an array
	{
		l = 0;
		courseFind = coursesAvailible[i]->getCRN();
		
		students.clear();
		students.seekg(0, ios::beg);
		while(getline(students, courseData))
		{
			found = courseData.find(courseFind);
			if(found != string::npos)
			{
				coursesAvailible[i]->setArray(studentsEnrolled[l]->getName(), 0);
				coursesAvailible[i]->setArrayUID(studentsEnrolled[l]->getUID(), 0);
				studentsEnrolled[i]->setClasses(coursesAvailible[i]->getCRN());
			}

			if(found < 150) //finds their grade for the course
			{
				char grade = (courseData.at(found + 8));
				coursesAvailible[i]->setGrade(grade);
			}
			l++;
		}
	}	
    students.close();
    
//---------students and teachers in a department-------------------------------------------------------
	for(k = 0; k < deptTypes.size(); k++)
	{
		for(i = 0; i < studentsEnrolled.size(); i++)
		{
			if(studentsEnrolled[i]->getMajorDept() == deptTypes[k]->getDept())
				deptTypes[k]->setArray(studentsEnrolled[i]->getName(), 0);
		}
		for(i = 0; i < teachersEmployed.size(); i++)
		{
			if(teachersEmployed[i]->getDept() == deptTypes[k]->getDept())
				deptTypes[k]->setArray(teachersEmployed[i]->getName(), 1);
		}
	}
	
//-----------Main menu--------------------------------------------------------------------
	while(mainLoop)
	{
		cout << "Welcome to University University, please make a selection" << endl;
		cout << "(0 - quit) | (1 - Students) | (2 - Teachers) | (3 - Courses) | (4 - Departments)";
		cin >> switchLoop;
		
		switch(switchLoop) //main menu selection
		{
			case 0: //quit program
				{ 
					mainLoop = false;
					break;
				}
			case 1: //students
				{
					cout << left << setw(8) << "UID" << setw(18) << "Student Name" << setw(13) << "Birthday" 
						 << setw(10) << "Gender" << setw(12) << "Status" << setw(7) << "GPA"  << "Department" << endl;
			 			
			 		for(i = 0; i < studentsEnrolled.size(); i++)
			 			studentsEnrolled[i]->printStudent();
					break;
				}
			case 2:	//teachers
				{
					cout << left << setw(8) << "UID" << setw(18) << "Teacher Name" << setw(13) << "Birthday"
			 		<< setw(10) << "Gender" << setw(12) << "Position" << setw(8) << "Department" << endl;

					for(i = 0; i < teachersEmployed.size(); i++)
							teachersEmployed[i]->printTeacher();
					break;
				}
			case 3: //course
				{	
					courseLoop = true;
					while(courseLoop) //type in CRN of course you want to look at
					{
						cout << "Select Course by entering CRN (enter 'quit' to exit): " << endl;
						cout << left << setw(3) << " " << setw(14) << "Course Name" << setw(11) << "CRN" << "Department" << endl;
							
						for(i = 0; i < coursesAvailible.size(); i++)
						{
							cout << i << ". " << left << setw(14) << coursesAvailible[i]->getName() << setw(11)
								 << coursesAvailible[i]->getCRN() << coursesAvailible[i]->getDept() << endl;
						}
						
						cin >> courseSelect;
						cout << endl;
						cout << left << setw(8) << "UID" << setw(21) << "Sudents" << "Grades" << endl;
						
						for(i = 0; i < coursesAvailible.size(); i++) //prints students in course
						{
	
							if(coursesAvailible[i]->getCRN() == courseSelect)
							{
								coursesAvailible[i]->printStudents();
								cout << endl;
							}
							else if(courseSelect == "quit")
								courseLoop = false;
						}
						
						cout << endl;
						cout << left << setw(8) << "UID" << setw(21) << "Teachers" << endl;
						
						for(i = 0; i < coursesAvailible.size(); i++) //prints teacher who teaches the course
						{
	
							if(coursesAvailible[i]->getCRN() == courseSelect)
							{
								coursesAvailible[i]->printTeachers();
								cout << endl;
							}
							else if(courseSelect == "quit")
								courseLoop = false;
						}		
						
					}
					break;
				}
			case 4: //departments
				{
					deptLoop = true;
					while(deptLoop) //type in department you want to look at
					{
						cout << "Select Department by entering course name (enter 'quit' to exit): " << endl;
					
						for(int j = 0; j < deptTypes.size(); j++)
						{
							cout << j + 1 << ". " << deptTypes[j]->getDept() << endl;
						}
						cin >> deptSelect;
						cout << endl;
						
						for(i = 0; i < deptTypes.size(); i++) //prints students and teachers in a certain department
							{	
								if(deptTypes[i]->getDept() == deptSelect)
								{
									cout << "Students: " << endl;
									deptTypes[0]->printStudents();
									cout << endl;
									
									cout <<"Teachers: " << endl;
									deptTypes[0]->printTeachers();
									cout << endl;
								}
								else if(deptSelect == "quit")
									deptLoop = false;
							}
					}
					break;
				}

			default: cout << "Please choose a correct option" << endl;
		}
	}
	
	return 0;
}
