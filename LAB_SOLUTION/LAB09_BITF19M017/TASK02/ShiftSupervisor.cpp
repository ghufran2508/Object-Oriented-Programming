#include<iostream>
#include"ShiftSupervisor.h"

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

Employee::Employee(const Employee& b)
{
	this->name = new char[50];
	int i = 0;
	while (b.name[i] != '\0')	i++;
	for (int j = 0; j < i; j++)
	{
		this->name[j] = b.name[j];
	}
	this->name[i] = '\0';
	this->emp_num = b.emp_num;
	this->hiredate = new char[20];
	i = 0;
	while (b.hiredate[i] != '\0')	i++;
	for (int j = 0; j < i; j++)
	{
		this->hiredate[j] = b.hiredate[j];
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

ShiftSuperVisor::ShiftSuperVisor():Employee(), annualSalary(0), annualProduction(0)
{}

ShiftSuperVisor::ShiftSuperVisor(int sal, int prod, Employee& b): Employee(b)
{
	this->annualSalary = (sal > 0) ? sal : 0;
	this->annualProduction = (prod > 0) ? prod : 0;
}

ShiftSuperVisor::ShiftSuperVisor(char* name, int num, char* date, int sal, int prod):Employee(name, num, date)
{
	this->annualSalary = (sal > 0) ? sal : 0;
	this->annualProduction = (prod > 0) ? prod : 0;
}

ShiftSuperVisor::ShiftSuperVisor(const ShiftSuperVisor& b)
{
	this->setName(b.getName());
	this->setDate(b.getDate());
	this->setNum(b.getNum());
	this->annualSalary = b.annualSalary;
	this->annualProduction = b.annualProduction;
}

ShiftSuperVisor::~ShiftSuperVisor()
{}

void ShiftSuperVisor::setAnnualSalary(int sal)
{
	this->annualSalary = (sal > 0) ? sal : 0;
}

void ShiftSuperVisor::setProduction(int prod)
{
	this->annualProduction = (prod > 0) ? prod : 0;
}

int ShiftSuperVisor::getAnnualSalary() const
{
	return this->annualSalary;
}

int ShiftSuperVisor::getProduction() const
{
	return this->annualProduction;
}

void ShiftSuperVisor::displayData()
{
	cout << "NAME: " << getName() << endl;
	cout << "HIREDATE: " << getDate() << endl;
	cout << "EMP NUMBER: " << getNum() << endl;
	cout << "Annual Salary: " << getAnnualSalary() << endl;
	cout << "Annual Production: " << getProduction() << endl;
}