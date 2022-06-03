#include<iostream>
#include<string>
#include"PointClass.h"

using namespace std;

int main()
{
	int  a, b;
	string check;
	char again;
	Point pt;

	do
	{
		cout << "Enter value for X: ";
		cin >> check;
		a = stoi(check);
		cout << "Enter value for Y: ";
		cin >> check;
		b = stoi(check);
		pt = { a, b };
		pt.printStars();

		cout << "\nDo you want to check again?(y/n): ";
		cin >> again;
	} while (again != 'N' && again != 'n');

	return 0;
}