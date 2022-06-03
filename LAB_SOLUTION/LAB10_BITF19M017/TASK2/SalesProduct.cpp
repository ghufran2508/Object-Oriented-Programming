#include<iostream>
#include"SalesProduct.h"

using namespace std;

SalesProduct::SalesProduct(int code, CString name, double price):Product(code, name, price)
{
	this->salePrice = price + price * 0.21;
}

void SalesProduct::setSalesPrice()
{
	this->salePrice = getPrice() + getPrice() * 0.21;
}

double SalesProduct::getSalesPrice() const
{
	return this->salePrice;
}

void SalesProduct::printProductionInfo()
{
	cout << "_______________________________________" << endl;
	cout << "Product Name: ";
	display(); cout << endl;
	cout << "Product Code: " << getCode() << endl;
	cout << "Product Price: " << getPrice() << endl;
	cout << "Product Sales Product: " << getSalesPrice() << endl;
	cout << "_______________________________________" << endl;
}