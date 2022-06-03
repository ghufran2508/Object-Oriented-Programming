#pragma once
#include<string>

using namespace std;

class PUCITstudent
{
private:
	string name; // to store name of the student
	string rollNo; // to store roll number of the student
	float cgpa; // to store cgpa of the student
public:
	PUCITstudent();
	// A constructor that should act as default as well as parametrized constructor.
	void setName(string); // set name of the student
	void setRollNo(string); // set roll number. It should be of exactly 10 characters
	void setCGPA(float); // set CGPA. It should be strictly between 1–4.00
	string getName(); // return name
	string getRollNo(); // return roll number
	float getCGPA(); // return CGPA
	string getDegreeProgram(); // return degree program in which student is enrolled
	string getBatch(); // return batch of the student
	char getSection(); // return section (M for morning and A for Afternoon)
	void displayStudentStatus(); // student status i.e pass, drop out, probation
	int graduatingYear(); // return year of graduation
};