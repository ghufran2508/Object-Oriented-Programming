#include<iostream>
#include"studentPU.h"

using namespace std;

PUCITstudent::PUCITstudent()
{
	name = "";
	rollNo = "";
	cgpa = 0;
}

void PUCITstudent::setName(string n)
{
	name = n;
}

void PUCITstudent::setRollNo(string rn)
{
	if (rn.length() == 10)
	{
		rollNo = rn;
	}
}

void PUCITstudent::setCGPA(float gpa)
{
	if(gpa >= 1.00 && gpa <= 4.00)
		cgpa = gpa;
}

string PUCITstudent::getName()
{
	return name;
}

string PUCITstudent::getRollNo()
{
	return rollNo;
}

float PUCITstudent::getCGPA()
{
	return cgpa;
}

string PUCITstudent::getDegreeProgram()
{
	string degree;
	degree = rollNo.substr(0, 3);
	return degree;
}

string PUCITstudent::getBatch()
{
	string batch = "FALL 20";
	batch += rollNo[4];
	batch += rollNo[5];
	return batch;
}

char PUCITstudent::getSection()
{
	if (rollNo[6] == 'M' || rollNo[6] == 'm')
		return 'M';
	if (rollNo[6] == 'A' || rollNo[6] == 'a')
		return 'A';
}

void PUCITstudent::displayStudentStatus()
{
	if (cgpa > 1.7000001)
		cout << "Pass" << endl;
	else if (cgpa < 1.5)
		cout << "Drop out" << endl;
	else
		cout << "Probation" << endl;
}

int PUCITstudent::graduatingYear()
{
	int year = 20;
	year = year * 10 + (static_cast<int>(rollNo[4]) - 48);
	year = year * 10 + (static_cast<int>(rollNo[5]) - 48);
	if ((rollNo[0] == 'B') || (rollNo[0] == 'b'))
	{
		return (year + 4);
	}
	if ((rollNo[0] == 'M') || (rollNo[0] == 'm'))
	{
		return (year + 2);
	}
}