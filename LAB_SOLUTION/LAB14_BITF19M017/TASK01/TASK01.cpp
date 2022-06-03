#include<iostream>
#include"Functions.h"

using namespace std;

int main()
{
	int choice, dt_choice;
	menu(choice);
	DataType(dt_choice);

	switch (dt_choice)
	{
	case 1:
		int first ;
		int second ;

		cout << "Enter the first value: ";
		cin >> first;
		cout << "Enter second number: ";
		cin >> second;
		switch (choice)
		{
		case 1:
			cout << "Minimum Number: " << minimum(first, second) << endl;
			break;
		case 2:
			cout << "Maxmum Number: " << maximum(first, second) << endl;
			break;
		case 3:
			cout << "Absolute Value: " << absolute(first) << endl;
			break;
		}
		break;
	case 2:
		float f_first ;
		float f_second;

		cout << "Enter the first value: ";
		cin >> f_first;
		cout << "Enter second number: ";
		cin >> f_second;
		switch (choice)
		{
		case 1:
			cout << "Minimum Number: " << minimum(f_first, f_second) << endl;
			break;
		case 2:
			cout << "Maxmum Number: " << maximum(f_first, f_second) << endl;
			break;
		case 3:
			cout << "Absolute Value: " << absolute(f_first) << endl;
			break;
		}
		break;
	case 3:
		double d_first ;
		double d_second ;

		cout << "Enter the first value: ";
		cin >> d_first;
		cout << "Enter second number: ";
		cin >> d_second;
		switch (choice)
		{
		case 1:
			cout << "Minimum Number: " << minimum(d_first, d_second) << endl;
			break;
		case 2:
			cout << "Maxmum Number: " << maximum(d_first, d_second) << endl;
			break;
		case 3:
			cout << "Absolute Value: " << absolute(d_first) << endl;
			break;
		}
		break;
	}

	return 0;
}

