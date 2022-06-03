#include<iostream>
#include"MyAccounts.h"

using namespace std;

Account::Account()
{
	accountNo = 0;
	accountTitle = "";
	openingBal = 5000;
	emailID = "Email ID Not Available";
	accountBal = 0;
}

void Account::setAccountNo(int number)
{
	//4 digit account number
	if(number >= 1000 && number <= 9999)
		accountNo = number;
}

void Account::setAccountTitle(string title)
{
	accountTitle = title;
}

void Account::setEmailID(string email)
{
	emailID = email;
}

void Account::setAccountBal(double balance)
{
	if (balance >= 5000)
		accountBal = balance;
	else
		accountBal = 5000;
}

void Account::setOpeningBal(double opening)
{
	if (opening > 0)
		openingBal = opening;
}

int Account::getAccountNo()
{
	return accountNo;
}

string Account::getAccountTitle()
{
	return accountTitle;
}

string Account::getEmailID()
{
	return emailID;
}

double Account::getAccountBal()
{
	return accountBal;
}

double Account::getOpeningBal()
{
	return openingBal;
}

void Account::displayAccountInfo()
{
	cout << "\n\nYour Account:\t\t\t" << getAccountTitle() << endl;
	cout << "Your Account No:\t\t" << getAccountNo() << endl;
	cout << "Your Email:\t\t" << getEmailID() << endl;
	cout << "Your Account current balance: " << getAccountBal() << "\n" << endl;
}

void Account::withdrawMoney(double withdraw)
{
	if (accountBal - withdraw >= openingBal)
		accountBal -= withdraw;
	else
		cout << "You cannot withdraw that amount!!!\nPlease try again" << endl;
}

void Account::depositMoney(double deposit)
{
	accountBal += deposit;
}

Account::~Account()
{
	cout << "\nHAVE A GOOD DAY" << endl;
}
