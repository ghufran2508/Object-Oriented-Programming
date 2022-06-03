#pragma once
#ifndef INVENTORYPRODUCT_H
#define INVENTORYPRODUCT_H
#include "Product.h"
#include "Supplier.h"
#include"CString.h"

class InventoryProduct : public Product
{
private:
	int quantity;
	Supplier supplier;
public:
	InventoryProduct(int, CString, double, CString, CString, int);
	void setProductInfo(CString, CString);
	void printProductInfo();
	void setQuantity(int);
	int getQuantity() const;
};

#endif // !INVENTORYPRODUCT_H
