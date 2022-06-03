#include"Classroom.h"
#include"Course.h"
#include"Teacher.h"
#include<iostream>

using namespace std;

Course::Course()
{
	this->title = " ";
	this->code = 0;
}

Course::Course(CString c_title, int c_code, Teacher b, Classroom c) :title(c_title), CT(b), classR(c)
{
	if (c_code > 0)
		this->code = c_code;
	else
		this->code = 0;
}

Course::Course(Course& b): CT(b.CT), classR(b.classR)
{
	this->title = b.title;
	this->code = b.code;
}

void Course::setTitle(CString c_title)
{
	this->title = c_title;
}

void Course::setCode(int c_code)
{
	if (c_code > 0)
		this->code = c_code;
	else
		this->code = 0;
}

void Course::setTeacher(Teacher b)
{
	this->CT = b;
}

void Course::setClassroom(Classroom cR)
{
	this->classR = cR;
}

CString Course::getTitle() const
{
	return this->title;
}

int Course::getCode() const
{
	return this->code;
}

Teacher Course::getTeacher() 
{
	return this->CT;
}

Classroom Course::getClassroom()
{
	return classR;
}

void Course::operator=(const Course& NC)
{
	this->title = NC.title;
	this->code = NC.code;
	this->CT = NC.CT;
	this->classR = NC.classR;
}

void Course::changeTeacher(Teacher& b)
{
	CT.setName(b.getName());
	CT.setEx_number(b.getEx_number());
}

void Course::allocateCapacity(Classroom& c)
{
	classR.setRoomNumber(c.getRoomNumber());
	classR.setCapacity(c.getCapacity());
}

void Course::printCourse()
{
	cout << "Course title: " << this->title << endl;
	cout << "Course code: " << this->code << endl;
	CT.printTeacher();
	classR.printClassroom();
}