#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H
#include"CString.h"
using namespace std;

class Product
{
private:
	int code;
	CString name;
	double cost;
public:
	Product();
	Product(int, CString, double);
	~Product();

	void setCode(int);
	int getCode() const;
	void setName(CString);
	CString getName() const;
	void setPrice(double);
	double getPrice() const;

	void display() const;
};

#endif // !PRODUCT_H
