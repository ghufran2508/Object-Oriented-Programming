#pragma once

#include"Teacher.h"
#include"Classroom.h"
#include"CString.h"
using namespace std;

class Course
{
private:
	CString title;
	int code;
	Teacher CT;
	Classroom classR;
public:
	Course();
	Course(CString, int, Teacher, Classroom);
	Course(Course&);

	void setTitle(CString c_title);
	void setCode(int c_code);
	void setTeacher(Teacher);
	void setClassroom(Classroom);

	CString getTitle() const;
	int getCode() const;
	Teacher getTeacher();
	Classroom getClassroom();

	void operator=(const Course&);
	void changeTeacher(Teacher&);
	void allocateCapacity(Classroom&);
	void printCourse();
};