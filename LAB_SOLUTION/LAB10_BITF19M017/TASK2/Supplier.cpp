#include<iostream>
#include"Supplier.h"

using namespace std;

void Supplier::setName(CString name)
{
	this->name = name;
}

void Supplier::setCompany(CString company)
{
	this->company = company;
}

CString Supplier::getName() const
{
	return this->name;
}

CString Supplier::getCompany() const
{
	return this->company;
}

void Supplier::printSuplierInfo()
{
	cout << "Supplier Name: ";
	sdisplayn();
	cout << endl;
	cout << "Supplier Company: ";
	sdisplayc();
	cout << endl;
}

void Supplier::sdisplayn() const
{
	this->name.display();
}

void Supplier::sdisplayc() const
{
	this->company.display();
}