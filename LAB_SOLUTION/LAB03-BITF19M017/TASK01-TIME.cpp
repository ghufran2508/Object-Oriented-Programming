#include<iostream>

using namespace std;
//declaring class of time
class time
{	//privating time variable so that no one change from outside the class
	private:
		int hours;	//to store hours
		int minutes;	//to store minutes
		int seconds;	//to store seconds
	public:
		//method to set hours to specific hours
		void setHour(int h);
		//method to set minutes to specific minutes
		void setMinute(int m);
		//method to set seconds to specific seconds
		void setSecond(int s);
		//method to call other methods to set time
		void setTime(int h = 0, int m = 0, int s = 0);
		//method that get the value of hours
		int getHour();	
		//method that get the value of minutes
		int getMinutes(); 
		//method that get the value of seconds
		int getSeconds();
		//methid to display time in 24 hours format
 		void printTwentyFourHourFormat();
 		//method to display time in 12 hours format
 		void printTwelveHourFormat();
 		//method to increase seconds(increase seconds default by 1)
		void incSec(int s = 1);
 		//method to increase minutes(increase minutes default by 1)
		void incMin(int m = 1); 
		//method to increase hours(increase hours default by 1)
	 	void incHour(int h = 1);
};
//method decleration to get hours from user and return it.
int time::getHour()
{
	return hours;	//returning the variable
}
//method decleration to get hours from user and return it.
int time::getMinutes()
{
	return minutes;		//return the variable
}
//method decleration to get seconds from user and return it.
int time::getSeconds()
{
	return seconds;		//returning the variable
}
//function decleration to set time
void time::setTime(int h, int m, int s)
{
	setHour(h);	//calling function to set hours
	setMinute(m);	//calling function to set minutes
	setSecond(s);	//calling function to set seconds
}
//function decleration to store hours
void time::setHour(int h)
{
	hours = h;	//set it to input value
}
//function decleration to store minutes
void time::setMinute(int m)
{
	minutes = m;	//set it to input value
}
//function decleration to store seconds
void time::setSecond(int s)
{
	seconds = s;	//set it to input value
}
//function decleration to print time in 24 hours format
void time::printTwentyFourHourFormat()
{
	cout << "TIME FORMAT://(HOUR:MINUTE:SECOND)//" << endl;
	cout << "\t" << hours << ":" << minutes << ":" << seconds << endl;
}
//function decleration to print time in 12 hours format
void time::printTwelveHourFormat()
{	//if input hours are less than 12, then display as it is
	if(hours < 12)
	{
		cout << "TIME FORMAT://(HOUR:MINUTE:SECOND)//" << endl;
		cout << "\t" << hours << ":" << minutes << ":" << seconds << " AM" << endl;
	}
	//else subtract 12 from hours and then display it
	else
	{
		cout << "TIME FORMAT://(HOUR:MINUTE:SECOND)//" << endl;
		cout << "\t" << hours-12 << ":" << minutes << ":" << seconds << " PM" << endl;
	}
}
//function decleration to increase seconds by specific or default value
void time::incSec(int s)
{
	//if increment value is positive than do the following
	if(s > 0)
	{
		//increase time by increase value
		seconds += s;
		//if after increment seconds get greater than equal to 60, then also increase the minutes
		if(seconds >= 60)
		{
			//function calling to increase the minutes
			incMin(seconds/60);
			//decrease the seconds ...
			seconds = seconds % 60;
		}
	}
}
//function decleration to increase minutes by specific or default value
void time::incMin(int m)
{
	//if increment value is positive than do the following
	if(m > 0)
	{
		//increase time by increase value
		minutes += m;
		//if after increment, minutes get greater than equal to 60, then do the following
		if(minutes >= 60)
		{
			//increase th hours by calling function
			incHour(minutes/60);
			
			minutes = minutes % 60;
		}
	}
}

void time::incHour(int h)
{
	//if increment value is positive than do the following
	if(h > 0)
	{
		//increase time by increase value
		hours += h;
		//if hours get greater than equal to 24, then reset the day.
		if(hours >= 24)	hours = hours % 24;
	}
}
//main function
int main()
{
	time current;	//creating class name current
	//char variable to go through the loop
	char check;
	//int variable to store user menu choice
	int menu;
	
	do
	{	//displaying menu on console 
		cout << "Please choose from the followings..." << endl;
		cout << "1. Set Hours." << endl;
		cout << "2. Set Minutes. " << endl;
		cout << "3. Set Seconds. " << endl;
		cout << "4. Set time." << endl;
		cout << "5. Get Hours." << endl;
		cout << "6. Get Minutes." << endl;
		cout << "7. Get Seconds." << endl; 
		cout << "8. Print Time in 24 hours format." << endl;
		cout << "9. Print Time in twelve hours format." << endl;
		cout << "10. Increase Seconds." << endl;
		cout << "11. Increase Minutes." << endl;
		cout << "12. Increase Hours." << endl;
		cin >> menu;
		//check if user input valid value (1-6)
		while(menu < 1 || menu > 12)
		{
			cout << "INVALID INPUT!!!" << endl;
			cin >> menu;
		}
		//then do the operation as user asked to do
		if(menu == 1) 
		{
			int h;
			cout << "Please enter HOURS(0-24): " ;
			cin >> h;	//ask for input
			//if input hours are greater than 24 and less than 0 then again ask for input
			while(h < 0 || h > 24)	
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter HOURS(0-24): " ;
				cin >> h;
			}
			current.setHour(h);
		}
		else if(menu == 2) 
		{
			int m;
			cout << "Please enter MINUTES(0-59): " ;
			cin >> m;	//ask for input
			//if input minutes are greater than 59 and less than 0 then again ask for input
			while(m < 0 || m > 59)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter MINUTES: " ;
				cin >> m;
			}
			current.setMinute(m);
		}
		else if(menu == 3) 
		{
			int s;
			cout << "Please enter SECONDS(1-59): " ;
			cin >> s;	//ask for input
			//if input minutes are greater than 59 and less than 0 then again ask for input
			while(s < 0 || s > 59)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter SECONDS(1-59): " ;
				cin >> s;
			}
			current.setSecond(s);
		}
		else if(menu == 4)
		{
			int h;
			cout << "Please enter HOURS(0-24): " ;
			cin >> h;	//ask for input
			//if input hours are greater than 24 and less than 0 then again ask for input
			while(h < 0 || h > 24)	
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter HOURS(0-24): " ;
				cin >> h;
			}
			
			int m;
			cout << "Please enter MINUTES(0-59): " ;
			cin >> m;	//ask for input
			//if input minutes are greater than 59 and less than 0 then again ask for input
			while(m < 0 || m > 59)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter MINUTES: " ;
				cin >> m;
			}
			
			int s;
			cout << "Please enter SECONDS(1-59): " ;
			cin >> s;	//ask for input
			//if input minutes are greater than 59 and less than 0 then again ask for input
			while(s < 0 || s > 59)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter SECONDS(1-59): " ;
				cin >> s;
			}
			
			current.setTime(h, m , s);
		}
		else if(menu == 5)
		{
				cout << "Current Hours: " << current.getHour() << endl;
		}
		else if(menu == 6)
		{
			cout << "Current Minutes: " << current.getMinutes() << endl;
		}
		else if(menu == 7)
		{
			cout << "Current Seconds: " << current.getSeconds() << endl;
		}
		else if(menu == 8)	current.printTwentyFourHourFormat();
		else if(menu == 9)	current.printTwelveHourFormat();
		else if(menu == 10)	
		{
			int inc = 0;
			int choice;
			cout << "1. Increase default value? " << endl;
			cout << "2. Increase specific value: " ;
			cin >> choice;
			while(choice < 1 || choice > 2)
			{
				cout << "INVALID INPUT!!!" << endl;
				cin >> choice;
			}
			if(choice == 1)	current.incSec();
			else
			{
				cout << "Enter increasing seconds: " ;
				cin >> inc;
				while(inc < 0)
				{
					cout << "INVALID INPUT!!!" << endl;
					cin >> inc;
				}
				current.incSec(inc);
			}
		}
		else if(menu == 11)
		{
			int inc = 0;
			int choice;
			cout << "\n1. Increase default value? " << endl;
			cout << "2. Increase specific value: " ;
			cin >> choice;
			while(choice < 1 || choice > 2)
			{
				cout << "INVALID INPUT!!!" << endl;
				cin >> choice;
			}
			if(choice == 1)	current.incMin();
			else
			{
				cout << "Enter increasing minutes: " ;
				cin >> inc;
				while(inc < 0)
				{
					cout << "INVALID INPUT!!!" << endl;
					cin >> inc;
				}
				current.incMin(inc);
			}
		}
		else
		{
			int inc = 0;
			int choice;
			cout << "\n1. Increase default value? " << endl;
			cout << "2. Increase specific value: " ;
			cin >> choice;
			while(choice < 1 || choice > 2)
			{
				cout << "INVALID INPUT!!!" << endl;
				cin >> choice;
			}
			if(choice == 1)	current.incHour();
			else
			{
				cout << "Enter increasing hours: " ;
				cin >> inc;
				while(inc < 0)
				{
					cout << "INVALID INPUT!!!" << endl;
					cin >> inc;
				}
				current.incHour(inc);
			}
		}
		//check if user again want to go through the menu...
		cout << "\nDo you want to quit(Y/n)? " ;
		cin >> check;
	}while(check != 'Y' && check != 'y');
	
	return 0;
}
