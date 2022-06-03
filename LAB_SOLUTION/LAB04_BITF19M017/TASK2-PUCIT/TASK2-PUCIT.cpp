#include<iostream>
#include"studentPU.h"

using namespace std;

bool checkValidRollNo(string);
void toUpper(string&);

int main()
{
	string name;
	string rollNumber;
	float cgpa;

	PUCITstudent me;

	cout << "Enter name: ";
	getline(cin, name);
	toUpper(name);
	me.setName(name);
	cout << "Enter roll No: ";
	cin >> rollNumber;
	toUpper(rollNumber);
	while(!checkValidRollNo(rollNumber))
	{
		cout << "INVALID ROLL NUMBER" << endl;
		cout << "Enter roll No: ";
		cin >> rollNumber;
		toUpper(rollNumber);
	}
	me.setRollNo(rollNumber);

	cout << "Enter CGPA: ";
	cin >> cgpa;

	while (cgpa < 1 || cgpa > 4)
	{
		cout << "INVALID CGPA!!!" << endl;
		cout << "Enter CGPA: ";
		cin >> cgpa;
	}
	me.setCGPA(cgpa);

	cout << "\nName:\t\t\t" << me.getName() << endl;
	cout << "Roll Number:\t\t" << me.getRollNo() << endl;
	cout << "Degree Program:\t\t" << me.getDegreeProgram() << endl;
	cout << "Batch:\t\t\t" << me.getBatch() << endl;
	cout << "Section:\t\t" ;
	if (me.getSection() == 'A')
		cout << "AFTERNOON" << endl;
	if (me.getSection() == 'M')
		cout << "MORNING" << endl;
	cout << "Status:\t\t\t";
	me.displayStudentStatus();
	cout << "CGPA:\t\t\t" << me.getCGPA() << endl;
	cout << "Year of graduation:\t" << me.graduatingYear() << endl;

	return 0;
}

void toUpper(string& rollNumber)
{
	for (int i = 0; i < rollNumber.length(); i++)
	{
		if (rollNumber[i] >= 97 && rollNumber[i] <= 122)
			rollNumber[i] -= 32;
	}
}

bool checkValidRollNo(string rollNo)
{
	if (rollNo.length() == 10)
	{
		char character[10] = {};
		for (int i = 0; i < rollNo.length(); i++)
		{
			character[i] = rollNo[i];
		}

		if (character[0] == 'M' || character[0] == 'B')
		{
			if ((character[1] == 'I' && character[2] == 'T') || (character[1] == 'C' && character[2] == 'S') || (character[1] == 'S' && character[2] == 'E'))
			{
				if(character[0] == 'M' && (character[1] == 'S' || character[1] == 'C'))
					return false;
				if (character[3] == 'F')
				{
					if (character[4] == 48 || character[4] == 49)
					{
						if (character[5] >= 48 && character[5] <= 57)
						{
							if (character[6] == 'M' || character[6] == 'A')
							{
								if (character[7] == 48 || character[7] == 53)
								{
									if (character[8] >= 48 && character[8] <= 54)
									{
										if (character[9] >= 49 && character[9] <= 57)
										{
											return true;
										}
										else
										{
											return false;
										}
									}
									else
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}