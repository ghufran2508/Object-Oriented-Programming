#pragma once
#ifndef STORE_H
#define STORE_H

#include"FossilFuel.h"

class Store
{
private:
	FossilFuel** fuels;
	int NumOfFossilFuels;
	int totalPurchase;
	int CustomersDealt;
	int* fuelCapacity;
public:
	Store(FossilFuel**, int*, int*, int = 3);
	void purchase(int, float);
	void generateRecipt();
	~Store();
};

#endif // !STORE_H
