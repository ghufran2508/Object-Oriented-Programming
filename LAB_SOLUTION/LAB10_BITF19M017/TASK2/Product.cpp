#include<iostream>
#include"CString.h"
#include"Product.h"

using namespace std;

Product::Product()
{
	this->code = 0;
	this->cost = 0.0;
	this->name = "";
}

Product::Product(int code, CString name, double price)
{
	this->code = (code > 0) ? code : 0;
	this->name = name;
	this->cost = (price > 0) ? price : 0;
}

Product::~Product()
{
	cout << "Item Discarded!!!" << endl;
}

void Product::setCode(int code)
{
	this->code = (code > 0) ? code : 0;
}

int Product::getCode() const
{
	return this->code;
}

void Product::setName(CString name)
{
	this->name = name;
}

CString Product::getName() const
{
	return this->name;
}

void Product::display() const
{
	this->name.display();
}

void Product::setPrice(double price)
{
	this->cost = (price > 0) ? price : 0;
}

double Product::getPrice() const
{
	return this->cost;
}