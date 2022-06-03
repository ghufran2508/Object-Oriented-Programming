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

ProductionWorker::ProductionWorker() :Employee(), shift(1), hourlypay(0)
{}

ProductionWorker::ProductionWorker(char* name, int num, char* date, int sft, int pay) : Employee(name, num, date)
{
	this->shift = (sft == 1 || sft == 2) ? sft: 1;
	this->hourlypay = (pay > 0) ? pay : 0;
}

void ProductionWorker::setShift(int sft)
{
	this->shift = (sft == 1 || sft == 2) ? sft : 1;
}

void ProductionWorker::setPay(int pay)
{
	this->hourlypay = (pay > 0) ? pay : 0;
}

int ProductionWorker::getShift() const
{
	return this->shift;
}

int ProductionWorker::getPay() const
{
	return this->hourlypay;
}

void ProductionWorker::displayData()
{
	int work;

	cout << "Enter the number of hours worked this week: ";
	cin >> work;

	cout << "NAME: " << getName() << endl;
	cout << "HIREDATE: " << getDate() << endl;
	cout << "EMP NUMBER: " << getNum() << endl;
	cout << "Monthly Pay: " << work * 4 * hourlypay << endl;
	cout << "Shift: ";
	if (shift == 1)	cout << "DAY" << endl;
	if (shift == 2) cout << "NIGHT" << endl;
	cout << "HourlyPay: " << getPay() << endl;
}