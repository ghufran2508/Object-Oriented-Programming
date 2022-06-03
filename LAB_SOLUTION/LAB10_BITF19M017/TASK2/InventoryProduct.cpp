#include<iostream>
#include "InventoryProduct.h"

using namespace std;

InventoryProduct::InventoryProduct(int code, CString name, double cost, CString s_name, CString comp, int quan):Product(code, name, cost)
{
	this->supplier.setName(s_name);
	this->supplier.setCompany(comp);
	this->quantity = quan;
}

void InventoryProduct::setProductInfo(CString name, CString company)
{
	this->supplier.setName(name);
	this->supplier.setCompany(company);
}

void InventoryProduct::printProductInfo()
{
	cout << "_______________________________________" << endl;
	cout << "Product Name: ";
	display();
	cout << endl;
	cout << "Product Code: " << getCode() << endl;
	cout << "Product Price: " << getPrice() << endl;
	supplier.printSuplierInfo();
	cout << "Quantity: " << quantity << endl;
	cout << "_______________________________________" << endl;
}

void InventoryProduct::setQuantity(int quantity)
{
	this->quantity = (quantity > 0) ? quantity : 0;
}

int InventoryProduct::getQuantity() const
{
	return this->quantity;
}