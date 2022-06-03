#include<iostream>
#include"ACCOUNT.h"

using namespace std;
//function to display a menu on console and take input
void displayMenu(char & choice);
//main function
int main()
{
	char choice;	//variable to store user choice
	int checkTransaction = 0;	//check for interest and transaction
	//creating an object of ACCOUNT and name it mine
	ACCOUNT mine;
	//do-while loop -> only terminate when user enter 'G' or 'g'
	do {
		displayMenu(choice);	//calling funtion to display a menu and ask for input
		//switch statement for choice...
		switch (choice)
		{
		case 'A':	//if user enter A or a, then do the following
		case 'a':
			//display current balance on console and the break;
			cout << "The current balance is PKR." << mine.getBalance() << endl;
			break;
		case 'B':	//if user enter B or b, then do the following
		case 'b':
			//display the total number of transaction a user made and then break;
			cout << "Number of transactions: " << mine.getTransactions() << endl;
			break;
		case 'C':	//if user enter C or c, then do the following
		case 'c':
			//first calculate the interest and then display it
			mine.setInterest();	//calling method to calculate interest
			//display interest on console
			cout << "Interest Earned for this period is PKR." << mine.getInterest() << endl;
			break;
		case 'D':	//if user enter D or d, then do the following
		case 'd':
			double deposit;
			//ask for the amount of money to deposit...
			cout << "Enter the amount of the deposit: ";	
			cin >> deposit;
			while (deposit <= 0)
			{
				cout << "[+]INVALID INPUT!!!" << endl;
				//ask for the amount of money to deposit...
				cout << "Enter the amount of the deposit: ";
				cin >> deposit;
			}
			//calling method to deposit amount on my account balance
			mine.addBalance(deposit);
			break;
		case 'E':	//if user enter E or e, then do the following
		case 'e':
			double withdraw;
			//ask for the amount of money to withdraw...
			cout << "Enter the amount of the withdrawal: ";
			cin >> withdraw;
			while (withdraw <= 0)
			{
				cout << "[+]INVALID INPUT!!!" << endl;
				//ask for the amount of money to withdraw...
				cout << "Enter the amount of the deposit: ";
				cin >> withdraw;
			}
			//if withdraw amount is greater than my current balance then display error
			if(mine.getBalance() - withdraw < 0)
			{
				cout << "ERROR! Withdrawal amount too large." << endl;
			}
			//otherwise withdraw money from my account
			else
			{
				mine.withdrawBalance(withdraw);
			}
			break;
		case 'F':	//if user enetr F or f, then do the following
		case 'f':
			//check for add intererst
			/*when we run the program, we can add unlimited times interest even
			without doing any transaction. causing the user to get rich even without depositing any money.
			to overcome this i put this bound check! if user add interst to his balance,
			then checkTransaction varaible will store the number of current transaction. 
			and then the user will only add interest when the transaction value change...*/
			if (mine.getTransactions() != 0 && checkTransaction != mine.getTransactions())
			{
				//calling method to add interest in my balance...
				mine.addInterest();
				//display that interest successfully added
				cout << "Interest Added!" << endl;
				//storing the transaction number as history
				checkTransaction = mine.getTransactions();
			}
			//else display interest not added because it was already added once.
			else
			{
				cout << "Interest Not Added!" << endl;
			}
			break;
		}
		//terminate the lopp when user enter G or g
	} while (choice != 'G' && choice != 'g');
	

	return 0;
}
//function to display a menu and ask user for input...
void displayMenu(char & choice)
{
	//displaying the menu//
	cout << "\t\tMENU\t\t" << endl;
	cout << "_______________________________________" << endl;
	cout << "A) Display the account balance" << endl;
	cout << "B) Display the number of transactions" << endl;
	cout << "C) Display interest earned for this period" << endl;
	cout << "D) Make a deposit" << endl;
	cout << "E) Make a withdrawal" << endl;
	cout << "F) Add interest for this period" << endl;
	cout << "G) Exit the program\n" << endl;
	cout << "Enter your choice: ";
	cin >> choice;	//ask choice from the user
	//check if user enter invalid value like q or t...
	while ((choice < 65 || choice > 71) && (choice < 97 || choice > 103))
	{
		cout << "[+]INVALID CHOICE!!!" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
	}
}