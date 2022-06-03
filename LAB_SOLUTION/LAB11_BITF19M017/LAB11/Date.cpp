#include<iostream>
#include<iomanip>
#include"Date.h"
using namespace std;
Date::Date()
{
	month = 1;
	year = 1600;
	day = 1;
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
}
void Date::setYear(int y)
{
	if (y >= 1000)
		year = y;
}
void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		if (d <= 31 && month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12)
			day = d;
		else if (d <= 30 && month == 4 || month == 6 || month == 9 || month ==
			11)
			day = d;
		else if (isLeapYear(year) && d <= 29 && month == 2)
			day = d;
		else if (!isLeapYear(year) && d <= 28 && month == 2)
			day = d;
	}
}
void Date::setDate(int d, int m, int y)
{
	setYear(y);
	setMonth(m);
	setDay(d);
}
void Date::display()
{
	int day = getDay(), m = getMonth(), y = getYear();
	cout << setfill('0') << right << setw(2) << day << " / " << setfill('0') << right << setw(2) << m << " / " << setfill('0') << right << setw(4) << y;
}
bool Date::isLeapYear(int y)
{
	if (y % 4 == 0)
		return true;
	return false;
}
int Date::getYear()
{
	return year;
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}
int Date::getNumberOfDaysOfMonths(int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	else if (isLeapYear(y) && m == 2)
		return 29;
	else if (!isLeapYear(y) && m == 2)
		return 28;
}
int Date::getTotalNumberOfDaysOfYear()
{
	int totalDays = 0;
	for (int i = 1; i < month; i++)
	{
		totalDays = totalDays + getNumberOfDaysOfMonths(i, year);
	}
	totalDays = totalDays + day;
	return totalDays;
}
void Date::incDay(int d)
{
	if (d >= 0)
	{
		if (day + d > 0 && day + d <= getNumberOfDaysOfMonths(month, year))
			day = day + d;
		else
		{
			long long tDays = getTotalNumberOfDaysOfYear();
			tDays = tDays + d;
			while (isLeapYear(year) && tDays > 366 || !isLeapYear(year) && tDays > 365)
			{
				if (isLeapYear(year))
				{
					tDays = tDays - 366;
					incYear();
				}
				else
				{
					tDays = tDays - 365;
					incYear();
				}
			}
			month = 1;
			while (tDays > getNumberOfDaysOfMonths(month, year))
			{
				tDays = tDays - getNumberOfDaysOfMonths(month, year);
				incMonth();
			}
			day = (int)tDays;
		}
	}
}
void Date::incMonth(int m)
{
	if (m >= 0)
	{
		int oldDay = getNumberOfDaysOfMonths(month, year);
		if (m % 12 == 0)
			incYear(m / 12);
		else if ((month + m) % 12 == 0)
		{
			incYear((month + m) / 12);
			month = 1;
		}
		else if (month + m > 12)
		{
			incYear((month + m) / 12);
			month = month + m;
			if (month % 12 == 0)
				month = 1;
			else
				month = month % 12;
		}
		else
			month = month + m;
		if (day == oldDay && day > getNumberOfDaysOfMonths(month, year))
			day = getNumberOfDaysOfMonths(month, year);
	}
	else
		return;
}
void Date::incYear(int y)
{
	if (y >= 0)
	{
		if (day == getNumberOfDaysOfMonths(month, year))
		{
			if (day > getNumberOfDaysOfMonths(month, year + y))
				day = getNumberOfDaysOfMonths(month, year + y);
		}
		year = year + y;
	}
	else
		return;
}
void Date::decDay(int d)
{
	if (d >= 0)
	{
		if (day - d > 0)
			day = day - d;
		else
		{
			long long tDays = getTotalNumberOfDaysOfYear();
			if (tDays - d > 0)
			{
				tDays = tDays - d;
				month = 1;
				while (tDays > getNumberOfDaysOfMonths(month, year))
				{
					tDays = tDays - getNumberOfDaysOfMonths(month, year);
					incMonth();
				}
				day = (int)tDays;
			}
			else if (tDays - d == 0)
			{
				month = 12;
				day = 31;
				decYear();
			}
			else if (tDays - d < 0)
			{
				while (d > tDays)
				{
					d = d - tDays;
					decYear();
					month = 12;
					tDays = getTotalNumberOfDaysOfYear();
				}
				month = 12;
				int mDays = getNumberOfDaysOfMonths(month, year);
				while (d >= mDays)
				{
					d = d - mDays;
					decMonth();
					mDays = getNumberOfDaysOfMonths(month, year);
				}
				if (day == 0)
					day = getNumberOfDaysOfMonths(month, year);
				else
					day = getNumberOfDaysOfMonths(month, year) - d;
			}
		}
	}
}
void Date::decMonth(int m)
{
	if (m >= 0)
	{
		int oldDay = getNumberOfDaysOfMonths(month, year);
		if (m % 12 == 0)
			decYear(m / 12);
		else if (abs(month - m) % 12 == 0)
		{
			decYear(abs(month - m) / 12 + 1);
			month = 12;
		}
		else if (month - m < 0)
		{
			decYear(abs(month - m) / 12 + 1);
			month = month - m;
			month = 12 - abs(month) % 12;
		}
		else
			month = month - m;
		if (day == oldDay && day > getNumberOfDaysOfMonths(month, year))
			day = getNumberOfDaysOfMonths(month, year);
	}
	else
		return;
}
void Date::decYear(int y)
{
	if (y >= 0 && year - y >= 1000)
	{
		if (day == getNumberOfDaysOfMonths(month, year))
		{
			if (day > getNumberOfDaysOfMonths(month, year - y))
				day = getNumberOfDaysOfMonths(month, year - y);
		}
		year = year - y;
	}
	else
		return;
}