#pragma once
#ifndef MAGAZINE_H
#define MAGAZINE_H

#include"Media.h"
#include<iostream>
#include<string>

using namespace std;

class Magazine : public Media
{
private:
	string MonthName;
	int yearOfPublication;
public:
	Magazine();
	Magazine(string, string, int);

	void display();
};

Magazine::Magazine()
{
	this->title = " ";
	this->MonthName = " ";
	this->yearOfPublication = 0;
}

Magazine::Magazine(string title, string monthname, int yop)
{
	this->title = title;
	this->MonthName = monthname;
	this->yearOfPublication = (yop > 0) ? yop : 0;
}

void Magazine::display()
{
	cout << "*****************************" << endl;
	cout << "Magazine : " << endl;
	cout << "Magazine title : " << title << endl;
	cout << "Month released: " << MonthName << endl;
	cout << "Year of Publication : " << yearOfPublication << endl;
	cout << "*****************************" << endl;
}

#endif // !MAGAZINE_H
