#include<iostream>
#include"Employee.h"

using namespace std;

Employee::Employee()
{
	this->name = new char[50];
	this->hiredate = new char[20];
	this->emp_num = 0;
}

Employee::Employee(char* name, int num, char* date)
{
	this->name = new char[50];

	int i = 0;
	while (name[i] != '\0')	i++;

	for (int j = 0; j < i; j++)
	{
		this->name[j] = name[j];
	}
	this->name[i] = '\0';

	this->emp_num = (num > 0) ? num : 0;

	this->hiredate = new char[20];

	i = 0;
	while (date[i] != '\0')	i++;

	for (int j = 0; j < i; j++)
	{
		this->hiredate[j] = date[j];
	}
	this->hiredate[i] = '\0';
}

Employee::~Employee()
{
	delete[] name;
	name = nullptr;
	delete[] hiredate;
	hiredate = nullptr;
}

void Employee::setName(char* empname)
{
	int i = 0;
	while (empname[i] != '\0')	i++;

	for (int j = 0; j < i; j++)
	{
		this->name[j] = empname[j];
	}
	this->name[i] = '\0';
}

void Employee::setNum(int num)
{
	this->emp_num = (num > 0) ? num : 0;
}

void Employee::setDate(char* date)
{
	int i = 0;
	while (date[i] != '\0')	i++;

	for (int j = 0; j < i; j++)
	{
		this->hiredate[j] = date[j];
	}
	this->hiredate[i] = '\0';
}

char* Employee::getName() const
{
	return this->name;
}

int Employee::getNum() const
{
	return this->emp_num;
}

char* Employee::getDate() const
{
	return this->hiredate;
}

void Employee::operator=(const Employee& newemp)
{
	if(this->name == NULL)
		this->name = new char[50];

	if(this->hiredate == NULL)
		this->hiredate = new char[20];

	this->name = newemp.getName();
	this->hiredate = newemp.getDate();
	this->emp_num = newemp.getNum();
}
