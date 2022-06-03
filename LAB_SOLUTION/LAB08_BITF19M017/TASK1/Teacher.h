#pragma once
#include"CString.h"

using namespace std;

class Teacher
{
private:
	CString name;
	int ex_number;
public:
	Teacher(CString a_name = " ", int aex_num = 1);
	Teacher(Teacher&);
	void setName(CString a_name);
	void setEx_number(int a_number);
	CString getName() const;
	int getEx_number() const;
	void operator=(const Teacher&);
	void printTeacher();
};