#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

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
};

class ProductionWorker : public Employee
{
private:
	int shift;
	int hourlypay;
public:
	ProductionWorker();
	ProductionWorker(char* name, int num, char* date, int sft, int pay);
	void setShift(int sft);
	void setPay(int pay);
	int getShift() const;
	int getPay() const;
	void displayData();
};

#endif // !EMPLOYEE_H
