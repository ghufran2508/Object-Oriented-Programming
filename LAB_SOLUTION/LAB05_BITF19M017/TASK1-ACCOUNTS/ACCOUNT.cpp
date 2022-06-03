#include<iostream>
#include"ACCOUNT.h"

using namespace std;

//default constructor to initialize members to speicific values
ACCOUNT::ACCOUNT():interestRate(0.045), balance(0.000), interest(0), transactions(0) 
{}
//parametrized constructor to initialize constructor by parametric values...
ACCOUNT::ACCOUNT(double b) : interestRate(0.045), balance(b), interest(0), transactions(0)
{}
//destructor to display a message and a sign that it is being destroyed
ACCOUNT::~ACCOUNT()
{
	cout << "Have a good day  ~ !!!" << endl;
}
//const mehtod to get the amount of my balance
double ACCOUNT::getBalance() const
{
	return balance; //return my current balance
}
//mehtod to calculate the interest by formula
void ACCOUNT::setInterest()
{
	//interest will be balance into(x) Rate
	this->interest = this->balance * this->interestRate;
}
//const method to get the value of interest 
double ACCOUNT::getInterest() const
{
	return interest;	//returns my current interest
}
//method to add money to my account balance
void ACCOUNT::addBalance(double deposit)
{
	//only add when deposit amount is greater than 0(positive)
	if (deposit > 0)
	{
		//add amount to my balance
		this->balance += deposit;
		//then calculate interest depends on my current balance
		setInterest();
		//increase the number of transactions...
		this->transactions++;
	}
}
//method to subtract money from my account balance
void ACCOUNT::withdrawBalance(double withdraw)
{
	//only subtract when the withdraw money is greater than 0(poisitive)
	if (withdraw > 0)
	{
		//subtract amount to my balance
		this->balance -= withdraw;
		//then calculate interest depends on my current balance
		setInterest();
		//increase the number of transactions...
		this->transactions++;
	}
}
//constant method to get the number of total transactions...
int ACCOUNT::getTransactions() const
{
	return transactions; //returning the value of total transactions being made
}
//method to add interest into my balance
void ACCOUNT::addInterest()
{
	//if interest gets to be greater than 0, then add it
	if(interest > 0)
		this->balance += this->interest;
}