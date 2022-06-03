#include<iostream>
#include"CustomerInfo.h"

using namespace std;
//main function
int main()
{
	//char array for name of max size 50.
	char *name = new char[50];
	//char array of CNIC of max size 13
	char* cnic = new char[13];
	//char array of phone number of max size 11
	char* phoneNumber = new char[11];
	//creating 5 object of customer as me[0], me[1], me[2], me[3], me[4]
	Customer me[5];
	//loop for each customer(max 5 customer)
	for (int i = 0; i < 5; i++)
	{
		//display customer number
		cout << "Customer#" << i + 1 << endl;
		cout << "Enter your name: ";
		cin >> name;	//ask for name
		me[i].setName(name);	//set the name of the customer
		cout << "Enter your CNIC(without hash):";
		cin >> cnic;	//ask for CNIC
		while (!me[i].setCNIC(cnic))	//while cnic is not perfect to be set, ask again
		{
			cout << "Please enter valid CNIC(without hash): ";
			cin >> cnic;	//again ask for cnic until entered right
		}
		cout << "Enter your Phone number: ";
		cin >> phoneNumber; //ask for phone number	
		while (!me[i].setPhone(phoneNumber))	//while phone number is not perfect to be set, ask again
		{
			cout << "Please enter valid Phone number: ";
			cin >> phoneNumber;		//again ask for phone number until entered right
		}
	}
	//display customer info on console...
	cout << "Customer Name\t\tNIC Number\t\tContact Info" << endl;
	cout << "______________________________________________________________" << endl;
	for (int i = 0; i < 5; i++)
	{
		//display info one by one on console
		me[i].displayCustomerInfo();
	}

	return 0;	//end
}
