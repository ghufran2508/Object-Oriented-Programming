#pragma once
#ifndef SHIFTSUPERVISOR_H
#define SHIFTSUPERVISOR_H

class Employee
{
private:
	char* name;
	int emp_num;
	char* hiredate;
public:
	Employee();
	Employee(char* name, int num, char* date);
	Employee(const Employee&);
	~Employee();
	void setName(char* name);
	void setNum(int num);
	void setDate(char* date);
	char* getName() const;
	int getNum() const;
	char* getDate() const;
};

class ShiftSuperVisor : public Employee
{
private:
	int annualSalary;
	int annualProduction;
public:
	ShiftSuperVisor();
	ShiftSuperVisor(const ShiftSuperVisor&);
	ShiftSuperVisor(int, int, Employee&);
	ShiftSuperVisor(char*, int, char*, int, int);
	~ShiftSuperVisor();
	void setAnnualSalary(int salary);
	void setProduction(int production);
	int getAnnualSalary() const;
	int getProduction() const;
	void displayData();
};

#endif