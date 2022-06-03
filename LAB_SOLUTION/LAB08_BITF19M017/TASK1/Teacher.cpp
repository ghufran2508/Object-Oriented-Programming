#include<iostream>
#include"Teacher.h"
#include"CString.h"

using namespace std;

Teacher::Teacher(CString a_name, int aex_nnumber)
{
	this->name = a_name;
	if (aex_nnumber > 0)
		this->ex_number = aex_nnumber;
	else
		this->ex_number = 1;
}

Teacher::Teacher(Teacher& b)
{
	this->name = b.name;
	this->ex_number = b.ex_number;
}

void Teacher::setName(CString a_name)
{
	this->name = a_name;
}

void Teacher::setEx_number(int aex_num)
{
	if (aex_num > 0)
		this->ex_number = aex_num;
	else
		this->ex_number = 1;
}

CString Teacher::getName() const
{
	return this->name;
}

int Teacher::getEx_number() const
{
	return this->ex_number;
}

void Teacher::operator=(const Teacher& b)
{
	this->name = b.getName();
	this->ex_number = b.getEx_number();
}

void Teacher::printTeacher()
{
	cout << "Teacher Name: " << this->name << endl;
	cout << "Teacher office extension number: " << this->ex_number << endl;
}