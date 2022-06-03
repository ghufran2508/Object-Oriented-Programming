#include<iostream>

using namespace std;

struct Date
{
	short day; 
	short month; 
	short year;
};

struct Student
{
	string name;
	string rollNo;
	Date dob;
	short coursesCount;
	string* courses;
	int* marks;
	float CGPA;	
};

void DateofBirth(Date &dob)
{
	cout << "DATE OF BIRTH: " << endl;
	cout << "ENTER DATE(1-31): " ;
	cin >> dob.day;
	while(dob.day < 0 || dob.day > 31)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "ENTER DATE(1-31): " ;
		cin >> dob.day;
	}
	cout <<"ENTER MONTH(1-12): " ;
	cin >> dob.month;
	while(dob.month < 0 || dob.month > 12)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout <<"ENTER MONTH(1-12): " ;
		cin >> dob.month;
	}
	cout << "ENTER YEAR: " ;
	cin >> dob.year;
	while(dob.year < 0)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "ENTER YEAR: " ;
		cin >> dob.year;
	}
}

void infoOfStudent(Student &s)
{
	cout << "Please enter your name: " ;
	getline(cin, s.name);
	cout << "Please enter your roll number: " ;
	cin >> s.rollNo;
	cout << "In how many courses you are involved in?: " ;
	cin >> s.coursesCount;
	while(s.coursesCount < 1)
	{
		cout << "INVALID INPUT!!!" << endl;
		cout << "In how many courses you are involved in?: " ;
		cin >> s.coursesCount;
	}
	s.marks = new int[s.coursesCount];
	s.courses = new string[s.coursesCount];
	for(int i = 0; i < s.coursesCount; i++)
	{
		cin.ignore();
		cout << "Please enter course name: " ;
		getline(cin, s.courses[i]);
		cout << "Please enter " << s.courses[i] << " marks: " ;
		cin >> s.marks[i];
		while(s.marks[i] < 0 || s.marks[i] > 100)
		{
			cout << "INVALID INPUT!!!" << endl;
			cout << "Please enter course #" << i+1 << " marks: " ;
			cin >> s.marks[i];
		}
	}
}

void calculateCGPA(Student &s)
{
	int sum;
	float grade;
	for(int i = 0; i < s.coursesCount; i++)
	{
		if(s.marks[i] >= 85)	grade = 4.00;
		else if(s.marks[i] >= 80)	grade = 3.70;
		else if(s.marks[i] >= 75)	grade = 3.30;
		else if(s.marks[i] >= 70)	grade = 3.00;
		else if(s.marks[i] >= 65)	grade = 2.70;
		else if(s.marks[i] >= 71)	grade = 2.30;
		else if(s.marks[i] >= 58)	grade = 2.00;
		else if(s.marks[i] >= 55)	grade = 1.70;
		else if(s.marks[i] >= 50)	grade = 1.00;
		else grade = 0.00;
		sum += grade*4;
	}
	s.CGPA = (static_cast<float>(sum)/(s.coursesCount*4));
}

void checkFail(Student s)
{	
	if(s.CGPA < 2.5)
	{
		cout << "Your CGPA is less than 2.54. IT WILL BE DROPOUT!!!" << endl;
	}
	else
	{
		cout << "Your CGPA is " << s.CGPA << endl;
	}

	for(int i = 0; i < s.coursesCount; i++)
	{
		if(s.marks[i] < 50)
		{
			cout << "You are fail in " << s.courses[i]  << ". So cannot continue" << endl;
		}
	}
}

int main()
{
	Student s1, s2, s3;
	cout << "FOR STUDENT 1: " << endl;
	DateofBirth(s1.dob);
	cin.ignore();
	infoOfStudent(s1);
	calculateCGPA(s1);
	
	cout << "FOR STUDENT 2: " << endl;
	DateofBirth(s2.dob);
	cin.ignore();
	infoOfStudent(s2);
	calculateCGPA(s2);
	
	cout << "FOR STUDENT 3: " << endl;
	DateofBirth(s3.dob);
	cin.ignore();
	infoOfStudent(s3);
	calculateCGPA(s3);
	
	cout << "STUDENT 1: " << endl;
	checkFail(s1);
	cout << "STUDENT 2: " << endl;
	checkFail(s2);
	cout << "STUDENT 3: " << endl;
	checkFail(s3);
	
	return 0;
}










