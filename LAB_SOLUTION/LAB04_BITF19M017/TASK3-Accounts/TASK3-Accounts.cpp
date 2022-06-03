#include<iostream>
#include"MyAccounts.h"
#include<string>

using namespace std;

int main()
{
	int number;
	string title;
	double trans;
	char email_check;
	char transaction_check;
	Account mine;

	cout << "Please enter your 4digit Account No: ";
	cin >> number;

	while (number < 1000 || number > 9999)
	{
		cout << "[+]Invalid Input!!!" << endl;
		cout << "Please enter your 4digit Account No:";
		cin >> number;
	}
	mine.setAccountNo(number);

	cout << "Please enter your Account title: ";
	cin.ignore();
	getline(cin, title);
	mine.setAccountTitle(title);
	mine.setOpeningBal(5000);
	mine.setAccountBal(5000);

	cout << "Do you have an email account?(y/n)";
	cin >> email_check;
	if (email_check == 'Y' || email_check == 'y')
	{
		string email;
		cout << "Please enter your email: ";
		cin >> email;
		mine.setEmailID(email);
	}

	double withdraw;
	double deposit;

	do
	{
		mine.displayAccountInfo();
		cout << "Do you want to do any kind of transaction?(y/n):";
		cin >> transaction_check;
		if (transaction_check == 'Y' || transaction_check == 'y')
		{
			int choice;
			cout << "You can perform the following... " << endl;
			cout << "1. Withdraw\n2.Deposit ";
			cin >> choice;
			while (choice < 1 || choice > 2)
			{
				cout << "[+]Invalid Input!!!" << endl;
				cin >> choice;
			}
			if (choice == 1)
			{
				cout << "How much amount you want to withdraw. ";
				cin >> withdraw;
				while (withdraw < 0)
				{
					cout << "[+]Invalid input!!!" << endl;
					cin >> withdraw;
				}
				mine.withdrawMoney(withdraw);
			}
			if (choice == 2)
			{
				cout << "How much amount you want to withdraw. ";
				cin >> deposit;
				while (deposit < 0)
				{
					cout << "[+]Invalid input!!!" << endl;
					cin >> deposit;
				}
				mine.depositMoney(deposit);
			}
		}
	} while (transaction_check != 'n' && transaction_check != 'N');

	mine.displayAccountInfo();

	return 0;
}