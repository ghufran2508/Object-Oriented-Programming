#include<iostream>
#include"Store.h"

using namespace std;

Store::Store(FossilFuel** fuels, int* fuelCapacity, int* amountAvailable, int numOfFossilFuels)
{
	this->NumOfFossilFuels = (numOfFossilFuels > 0 && numOfFossilFuels < 4) ? numOfFossilFuels : 0;
	this->fuelCapacity = fuelCapacity;
	if (fuels == NULL)
	{
		this->fuels = new FossilFuel * [NumOfFossilFuels];

		
		this->fuels[0] = new NaturalGas();
		
		this->fuels[1] = new CrudeOil();
		
		this->fuels[2] = new Coal();

		for (int i = 0; i < NumOfFossilFuels; i++)
		{
			this->fuels[i]->setID(i);
			if (fuelCapacity[i] >= amountAvailable[i])
				this->fuels[i]->setAmount(amountAvailable[i]);
			else
				this->fuels[i]->setAmount(fuelCapacity[i]);
			if(i == 0)
				this->fuels[i]->setRate(0.26);
			if(i == 1)
				this->fuels[i]->setRate(55.0);
			if(i == 2)
				this->fuels[i]->setRate(40.50);
		}
	}
	else
	{
		this->fuels = fuels;
	}
	this->CustomersDealt = 0;
	this->totalPurchase = 0;
}

void Store::purchase(int id, float amount)
{
	if ((id < NumOfFossilFuels - 1) && (id >= 0))
	{
		if (fuels[id]->getAmount() >= amount)
		{
			int leftAmount = fuels[id]->getAmount() - amount;
			fuels[id]->setAmount(leftAmount);
			totalPurchase++;
		}
		else
		{
			cout << "SOrry!!! No such Amount left" << endl;
		}
	}
	else
	{
		cout << "INVALID ID NO." << endl;
	}
	this->CustomersDealt++;
}

void Store::generateRecipt()
{
	int id;
	float amount;
	cout << "Choose the fossil fuel you want to buy..." << endl;
	cout << "1. Natural Gas." << endl;
	cout << "2. Crude Oil." << endl;
	cout << "3. Coal." << endl;
	cin >> id;
	while (id < 1 && id > 3)
	{
		cout << "INVALID CHOICE!!!" << endl;
		cin >> id;
	}
	
	cout << "Enter the Amount you want to buy: ";
	cin >> amount;

	while (amount < 0)
	{
		cout << "INVALID AMOUNT!!!" << endl;
		cin >> amount;
	}
	id--;
	float price = 0;
	float discount = 0;
	if (fuels[id]->getAmount() >= amount)
	{
		price = fuels[id]->calculatePrice(amount);
		purchase(id, amount);
		if (id == 0 && price >= 40.45)
		{
			discount = 0.1;
		}
		if (id == 1 && price > 98.99)
		{
			discount = 0.15;
		}
		if (id == 2 && price > 176.34)
		{
			discount = 0.11;
		}
	}
	else
	{
		cout << "Their's a shortage of Fossil fuel.:(" << endl;
	}

	cout << "\n\nTotal Price: " << price << endl;
	cout << "\nYour Discout: " << discount * price << endl;
	price = price - discount * price;
	cout << "\nTotal Price(After discount): " << price << endl;
}

Store::~Store()
{
	for (int i = 0; i < this->NumOfFossilFuels; i++)
	{
		delete fuels[i];
	}
	delete[] fuels;
	fuels = NULL;

	delete[] fuelCapacity;
	fuelCapacity = NULL;
}