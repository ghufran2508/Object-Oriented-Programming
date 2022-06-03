#include<iostream>
#include"Store.h"

using namespace std;

const string Fossils[3] = { "NaturalGas", "CrudeOil", "Coal" };

int main()
{
	FossilFuel** fuel = NULL;
	int totalNoOfFossils = 3;
	int* capacity = new int[totalNoOfFossils];
	int* amount = new int[totalNoOfFossils];

	for (int i = 0; i < totalNoOfFossils; i++)
	{
		cout << "Enter the capacity of the Fossil fuel " << Fossils[i] << ": ";
		cin >> capacity[i];
		cout << "Enter the amount available in the store: ";
		cin >> amount[i];
	}

	Store mystore(fuel, capacity, amount, totalNoOfFossils);

	char check;

	do
	{
		mystore.generateRecipt();
		cout << "\nDo you want to check again(y/n)? ";
		cin >> check;
	} while (check != 'N' && check != 'n');

	return 0;
}