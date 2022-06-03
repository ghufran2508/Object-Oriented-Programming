#pragma once
#ifndef SUPPLIER_H
#define SUPPLIER_H
#include "CString.h"

using namespace std;

class Supplier
{
private:
	CString name;
	CString company;
public:
	void setName(CString);
	void setCompany(CString);
	CString getName() const;
	CString getCompany() const;
	void printSuplierInfo();
	void sdisplayn() const;
	void sdisplayc() const;
};

#endif // !SUPPLIER_H
