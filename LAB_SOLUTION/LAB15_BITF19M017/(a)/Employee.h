#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using namespace std;

class Employee
{
private:
	char* name;
	int emp_num;
	char* hiredate;
public:
	Employee();
	Employee(char* name, int num, char* date);
	~Employee();
	void setName(char* name);
	void setNum(int num);
	void setDate(char* date);
	char* getName() const;
	int getNum() const;
	char* getDate() const;
	void operator=(const Employee& newemp);
	void display() const
	{
		cout << "Name: " << name << endl;
		cout << "Date: " << hiredate << endl;
		cout << "emp num: " << emp_num << endl;
	}
};

#endif // !EMPLOYEE_H