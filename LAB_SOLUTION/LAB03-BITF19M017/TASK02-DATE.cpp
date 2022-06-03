#include<iostream>

using namespace std;
//declaring class of Date
class Date
{
	//its private members are day, month and year
	private:
		int month;
		int day;
		int year;
	public:
		void setDate(int m, int d, int y);
		int getMonth();
		int getDay();
		int getYear();
		void setMonth(int m);
		void setDay(int d);
		void setYear(int y);
		void printOption();
		void printNumeric();
		void printFormat1();
		void printFormat2();
		string MonthName();
};

void Date::setDate(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

void Date::setMonth(int m)
{
	month = m;
}
void Date::setDay(int d)
{
	day = d;
}
void Date::setYear(int y)
{
	year = y;
}

void Date::printOption()
{
	int format;
	
	cout << "Please choose print Date format: " << endl;
	cout << "1. MM/DD/YY (numeric). " << endl;
	cout << "2. MM/DD/YY " << endl;
	cout << "3. DD/MM/YY " << endl;
	cin >> format;
	
	while(format < 1 || format > 3)
	{
		cout << "PLEASE INPUT A VALID NUMBER!!!" << endl;
		cin >> format;
	}
	switch(format)
	{
		case 1:
			printNumeric();
			break;
		case 2:
			printFormat1();
			break;
		case 3:
			printFormat2();
			break;
	}
}

void Date::printNumeric()
{
	cout << "CURRENT DATE: " << month << "/" << day << "/" << year << endl;
}

void Date::printFormat1()
{
	string monthName;
	monthName = MonthName();
	cout << "CURRENT DATE: " << monthName << " " << day << "," << year << endl;
}

void Date::printFormat2()
{
	string monthName;
	monthName = MonthName();
	cout << "CURRENT DATE: " << day << " " << monthName << " " << year << endl;
}

string Date::MonthName()
{
	if(month == 1) return "Januray";
	else if(month == 2) 	return "February";
	else if(month == 3)		return "March";
	else if(month == 4) 	return "April";
	else if(month == 5) 	return "May";
	else if(month == 6) 	return "June";
	else if(month == 7)		return "July";
	else if(month == 8) 	return "August";
	else if(month == 9) 	return "September";
	else if(month == 10)	return "October";
	else if(month == 11) 	return "November";
	else	return "December";
}

int main()
{
	Date current;
	
	char check;
	int menu;
	
	do
	{
		cout << "Please choose from the following..." << endl;
		cout << "1. Set Month." << endl;
		cout << "2. Set Day." << endl;
		cout << "3. Set Year." << endl;
		cout << "4. Set Date. " << endl;
		cout << "5. Get Month." << endl;
		cout << "6. Get Day." << endl;
		cout << "7. Get Year." << endl;
		cout << "8. Print Date Format." << endl;
		cin >> menu;
		//check if user input valid value (1-6)
		while(menu < 1 || menu > 8)
		{
			cout << "INVALID INPUT!!!" << endl;
			cin >> menu;
		}
		
		if(menu == 1)
		{
			int m;
			cout << "Please enter MONTH(1-12): " ;
			cin >> m;
			while(m < 1 || m > 12)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter MONTH(1-12): " ;
				cin >> m;
			}
			current.setMonth(m);
		}
		else if(menu == 2)
		{
			int d;
			cout << "Please enter DAY(1-31): " ;
			cin >> d;
			while(d < 1 || d > 31)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter DAY(1-31): " ;
				cin >> d;
			}
			current.setDay(d);
		}
		else if(menu == 3)
		{
			int y;
			cout << "Please enter YEAR(>0): " ;
			cin >> y;
			while(y < 1)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter YEAR(>0): " ;
				cin >> y;
			}
			current.setYear(y);
		}
		else if(menu == 4)
		{
			int m;
			cout << "Please enter MONTH(1-12): " ;
			cin >> m;
			while(m < 1 || m > 12)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter MONTH(1-12): " ;
				cin >> m;
			}
			
			int d;
			cout << "Please enter DAY(1-31): " ;
			cin >> d;
			while(d < 1 || d > 31)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter DAY(1-31): " ;
				cin >> d;
			}
			
			int y;
			cout << "Please enter YEAR(>0): " ;
			cin >> y;
			while(y < 1)
			{
				cout << "INVALID INPUT!!!" << endl;
				cout << "Please enter YEAR(>0): " ;
				cin >> y;
			}
			
			current.setDate(m, d, y);
		}
		else if(menu == 5)
		{
			cout << "Current Month: " << current.getMonth() << "->" << current.MonthName() << endl;
		}
		else if(menu == 6)
		{
			cout << "Current Day: " << current.getDay() << endl;
		}
		else if(menu == 7)
		{
			cout << "Current Year: " << current.getYear() << endl;
		}
		else 
		{
			current.printOption();
		}
		
		//check if user again want to go through the menu...
		cout << "\nDo you want to quit(Y/n)? " ;
		cin >> check;
	}while(check != 'Y' && check != 'y');
	
	return 0;
}














