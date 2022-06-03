#include<iostream>
#include"Employee.h"

using namespace std;

int main()
{
	ProductionWorker worker;
	char* name = new char[50];
	char* date = new char[20];
	int num;

	cout << "Enter Name: ";
	cin.getline(name, 50);
	worker.setName(name);
	cout << "Enter hiredate: ";
	cin.getline(date, 20);
	worker.setDate(date);
	cout << "Enter Employee Num: ";
	cin >> num;
	while (num < 0)
	{
		cout << "INVALID NUMBER!!!" << endl;
		cout << "Enter Employee Num: ";
		cin >> num;
	}
	worker.setNum(num);
	cout << "Enter Shift(1-2): ";
	cin >> num;
	while (num < 1 || num > 2)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "Enter Shift(1-2): ";
		cin >> num;
	}
	worker.setShift(num);
	cout << "Emter hourly Pay: ";
	cin >> num;
	while (num < 0)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "Emter hourly Pay: ";
		cin >> num;
	}
	worker.setPay(num);

	worker.displayData();
	return 0;
}
