#include<iostream>
#include"Product.h"
#include"SalesProduct.h"
#include"InventoryProduct.h"
#include"Supplier.h"

using namespace std;

int main()
{
	SalesProduct sp(124, "Power Bank", 1500);

	sp.printProductionInfo();

	InventoryProduct ip(147, "Charger", 1000, "Samsung", "Samsung", 20);

	ip.printProductInfo();
	return 0;
}