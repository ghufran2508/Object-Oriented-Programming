#pragma once
#include<string>
using namespace std;

class Account
{
private:
	int accountNo;
	string accountTitle;
	double openingBal;
	string emailID;
	double accountBal;
public:
	Account();
	~Account();
	void setAccountNo(int);
	void setAccountTitle(string);
	void setOpeningBal(double);
	void setEmailID(string);
	void setAccountBal(double);
	int getAccountNo();
	string getAccountTitle();
	double getAccountBal();
	string getEmailID();
	double getOpeningBal();
	void displayAccountInfo();
	void withdrawMoney(double);
	void depositMoney(double);
};
