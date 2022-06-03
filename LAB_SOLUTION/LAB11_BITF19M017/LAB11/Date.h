#pragma once
#ifndef DATE_H
#define DATE_H

enum Months {
	JANUARY = 31,
	FEBURARY = 28,
	MARCH = 31,
	APRIL = 30,
	MAY = 31,
	JUNE = 30,
	JULY = 31,
	AUGUST = 31,
	SEPTEMBER = 30,
	OCTOBER = 31,
	NOVEMBER = 30,
	DECEMBER = 31
};
class Date
{
private:
	int year;
	int month;
	int day;
	bool isLeapYear(int y);
	int getNumberOfDaysOfMonths(int m, int y);
	int getTotalNumberOfDaysOfYear();
public:
	Date();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	void setDate(int y, int m, int d);
	void display();
	int getYear();
	int getMonth();
	int getDay();
	void incDay(int d = 1);
	void incMonth(int m = 1);
	void incYear(int y = 1);
	void decDay(int d = 1);
	void decMonth(int m = 1);
	void decYear(int y = 1);
};

#endif // !DATE_H
