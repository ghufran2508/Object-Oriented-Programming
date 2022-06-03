#pragma once
class ACCOUNT
{
private:
	//to store the current account balance.
	double balance; 
	//to store the interest earned for the current period.
	double interest; 
	//to store the current number of transactions. 
	int transactions; 
public:
	//to store the interest rate for the period.
	const double interestRate;
	//default constructor for account class to initialize members by specific values...
	ACCOUNT();
	//parametrized constructor for account class to initialize members by parametric values...
	ACCOUNT(double d);
	//destructor to display that object is destroyed!!!
	~ACCOUNT();
	//a constant method to get the amount of my balance..
	double getBalance() const;
	//method to set the interest earned after every transaction!
	void setInterest();
	//a constant method to get the amount of interest that will be obtained by the formula...
	double getInterest() const;
	//method to add amount on my balance(deposit)
	void addBalance(double add);
	//method to ake money from my account(withdraw)
	void withdrawBalance(double withdraw);
	//method to get the total number of transactions i have done...
	int getTransactions() const;
	//method to add the amount of interest in my balance
	void addInterest();
};