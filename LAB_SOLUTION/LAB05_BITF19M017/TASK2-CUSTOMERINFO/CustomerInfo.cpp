#include<iostream>
#include"CustomerInfo.h"

using namespace std;
//fucntion to add hashes in CNIC.
void includeHash(char*&);
//function to return the length of the char pointer
int charLength(char* s)
{
	int z = 0; //declaring variable that will give size//
	while (1)
	{
		//compare through ascii code->if any strange character appears then break the loop and return size already read...
		if ((s[z] >= 65 && s[z] <= 90) || (s[z] >= 97 && s[z] <= 122) || (s[z] >= 48 && s[z] <= 57) || s[z] == 45)
		{
			z++; //increasing the size by 1 every time it runs
		}
		else
		{
			break; //if strange character found then break the loop
		}
	}
	return z;	//returning size//
}
//default constructor to initialize arrays
Customer::Customer()
{
	name = new char[50];	//max length of name is 50
	CNIC = new char[15];	//max length of CNIC is 13. adding 2 hases makes it of 15
	phone = new char[11];	//max length of phone number is 11
}
//parametrized constructor to initailize array and store values
Customer::Customer(char* a_name, char* a_CNIC, char* ph)
{
	name = new char[50];	//max length of name is 50
	CNIC = new char[15];	//max length of CNIC is 13. adding 2 hases makes it of 15
	phone = new char[11];	//max length of phone number is 11
	//storing name of customer index by index
	for (int i = 0; i < charLength(a_name); i++)
	{
		name[i] = a_name[i];
	}
	//storing name of CNIC index by index
	for (int i = 0; i < charLength(a_CNIC); i++)
	{
		CNIC[i] = a_CNIC[i];
	}
	includeHash(CNIC); //calling funtion to add hashes in th CNIC
	//storing name of phone number index by index
	for (int i = 0; i < charLength(ph); i++)
	{
		phone[i] = ph[i];
	}
}
//destructor displaying that it is going out of scope
Customer::~Customer()
{
	cout << "Object Destroyed!!!" << endl;
}
//method to store name of the customer
void Customer::setName(char* a_name)
{
	//storing name of customer index by index
	for (int i = 0; i < charLength(a_name); i++)
	{
		name[i] = a_name[i];
	}
}
//method to return pointer of name of customer
char* Customer::getName() const
{
	return name;	//returning name pointer
}
//method to store CNIC of the customer
bool Customer::setCNIC(char* a_cnic)
{
	//check if entered cnic is of 13 length
	if (charLength(a_cnic) == 13)
	{
		//check if 13 letters are only numbers
		for (int i = 0; i < 13; i++)
		{
			if (a_cnic[i] < 48 && a_cnic[i] > 57)
				return false;	//if not return false
		}
		//and 13th index is escape sequence, telling that size if 13 characters
		if (a_cnic[13] == '\0')
		{
			//storing name of CNIC index by index
			for (int i = 0; i < charLength(a_cnic); i++)
			{
				CNIC[i] = a_cnic[i];
			}
			includeHash(CNIC); //calling function to add hashes to CNIC
			return true;	//return true after storing
		}
		//else return false
		else
			return false;
	}
	else
		return false;	//return false;
}
//function to add hashes to CNIC
void includeHash(char*& cnic)
{
	//move CNIC to right from index 6 to 14
	for (int i = 14; i > 5; i--)
	{
		cnic[i] = cnic[i - 1];
	}
	//add hash to the 6th place
	cnic[5] = '-';
	char temp = cnic[13];	//store last character
	cnic[13] = '-';	//store has there
	cnic[14] = temp;	//store that character to last index
	cnic[15] = '\0';	//put escape sequence in last makes it length of 15
}
//method to store phone number of the customer
bool Customer::setPhone(char* number)
{
	//check if entered phone number is of 11 length
	if (charLength(number) == 11)
	{
		//check if 11 letters are only numbers
		for (int i = 0; i < 11; i++)
		{
			if (number[i] < 48 && number[i] > 57)
				return false;	//if not return false
		}
		//if number does not start from 03, then retiurn false
		if (number[0] != 48 || number[1] != 51)
			return false;
		if (number[11] == '\0')
		{
			//storing name of phone number index by index
			for (int i = 0; i < charLength(number); i++)
			{
				phone[i] = number[i];
			}
			return true;	//return true after storing
		}
		else
			return false;
	}
	else
		return false;
}
//method to get CNIC of the customer
char* Customer::getCNIC() const
{
	return CNIC;	//returning CNIC
}
//method to get phone number of customer
char* Customer::getPhone() const
{
	return phone;	//returning the phone number
}
//method to display customer info on console
void Customer::displayCustomerInfo()
{
	//display name
	for (int i = 0; i < charLength(name); i++)
		cout << name[i];
	cout << "\t\t\t";
	//display CNIC
	for (int i = 0; i < charLength(CNIC); i++)
		cout << CNIC[i];
	cout << "\t\t";
	//display phone number
	for (int i = 0; i < charLength(phone); i++)
		cout << phone[i];
	cout << endl;
}