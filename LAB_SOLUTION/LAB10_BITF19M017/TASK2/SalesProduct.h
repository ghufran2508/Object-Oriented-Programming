#pragma once
#ifndef SALESPRODUCT_H
#define SALESPRODUCT_H
#include"Product.h"

class SalesProduct: public Product
{
private:
	double salePrice;
public:
	SalesProduct(int, CString, double);
	void setSalesPrice();
	double getSalesPrice() const;
	void printProductionInfo();
};

#endif // !SALESPRODUCT_H
