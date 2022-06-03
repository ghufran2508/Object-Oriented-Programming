#include<iostream>
#include<string>
#include"CruiseShip.h"
#include"CargoShip.h"

using namespace std;

int main()
{
	Ship** newship = new Ship*[4];
	string name;
	string year;
	
	int i = 0;
	for ( i ; i < 2; i++)
	{
		int pessangers;

		cout << "Enter Name of the Ship : ";
		cin >> name;

		cout << "Enter the year of build : ";
		cin >> year;

		cout << "Enter the maximum number of pessangers : ";
		cin >> pessangers;

		while (pessangers < 0)
		{
			cout << "INVALID INPUT!!!" << endl;
			cin >> pessangers;
		}

		newship[i] = new CruiseShip(name, year, pessangers);
	}

	for (; i < 4; i++)
	{
		int capacity;;

		cout << "Enter Name of the Ship : ";
		cin >> name;

		cout << "Enter the year of build : ";
		cin >> year;

		cout << "Enter the Cargo Capacity : ";
		cin >> capacity;

		while (capacity < 0)
		{
			cout << "INVALID INPUT!!!" << endl;
			cin >> capacity;
		}

		newship[i] = new CargoShip(name, year, capacity);
	}

	system("cls");

	for (int k = 0; k < i; k++)
	{
		if (k < 2)
		{
			cout << "\nCruise Ship#" << k + 1 << " : \n" << endl;
 		}
		else
		{
			cout << "\nCargo Ship#" << k + 1 << " : \n" << endl;
		}
		newship[k]->print();
	}

	for (int j = 0; j < i; j++)
	{
		delete newship[j];
	}

	delete[] newship;
	newship = nullptr;
	return 0;
}