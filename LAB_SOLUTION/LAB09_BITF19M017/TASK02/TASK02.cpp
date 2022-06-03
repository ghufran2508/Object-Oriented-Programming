#include<iostream>
#include"ShiftSupervisor.h"

using namespace std;

int main()
{
	ShiftSuperVisor supervisor;

	char* name = new char[50];
	char* date = new char[20];
	int num;

	cout << "Enter Name: ";
	cin.getline(name, 50);
	supervisor.setName(name);
	cout << "Enter hiredate: ";
	cin.getline(date, 20);
	supervisor.setDate(date);
	cout << "Enter Employee Num: ";
	cin >> num;
	while (num < 0)
	{
		cout << "INVALID NUMBER!!!" << endl;
		cout << "Enter Employee Num: ";
		cin >> num;
	}
	supervisor.setNum(num);
	cout << "Enter Annual Salary: ";
	cin >> num;
	while (num < 0)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "Enter Annual Salary: ";
		cin >> num;
	}
	supervisor.setAnnualSalary(num);
	cout << "Emter Annual Production: ";
	cin >> num;
	while (num < 0)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "Emter Annual Production: ";
		cin >> num;
	}
	supervisor.setProduction(num);

	supervisor.displayData();

	return 0;
}