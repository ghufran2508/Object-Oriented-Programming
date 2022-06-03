#include<iostream>
#include"Teacher.h"
#include"Classroom.h"
#include"Course.h"
#include"CString.h"

using namespace std;

int main()
{
	CString name;
	int num;
	Teacher OOPTeacher;
	Classroom lab;
	Course OOP;

	cout << "Enter Teacher Name: ";
	cin >> name;
	OOPTeacher.setName(name);

	cout << "Enter office extension: ";
	cin >> num;
	OOPTeacher.setEx_number(num);

	cout << "Enter classroom number: ";
	cin >> num;
	lab.setRoomNumber(num);

	cout << "Enter classroom capacity: ";
	cin >> num;
	lab.setCapacity(num);

	cout << "Enter Course title: ";
	cin >> name;
	OOP.setTitle(name);

	cout << "Enter course code: ";
	cin >> num;
	OOP.setCode(num);
	OOP.setTeacher(OOPTeacher);
	OOP.setClassroom(lab);

	OOP.printCourse();

	return 0;
}