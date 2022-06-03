#pragma once
#ifndef SHIP_H
#define SHIP_H

#include<iostream>
#include<string>
using namespace std;

class Ship
{
private:
	string name;
	string year;
public:
	Ship();
	Ship(string, string);

	void setName(string);
	void setYear(string);

	string getName() const;
	string getYear() const;

	virtual void print();
};

Ship::Ship() : name(" "), year(" ")
{}

Ship::Ship(string name, string year)
{
	this->name = name;
	this->year = year;
}

void Ship::setName(string name)
{
	this->name = name;
}

void Ship::setYear(string year)
{
	this->year = year;
}

string Ship::getName() const
{
	return this->name;
}

string Ship::getYear() const
{
	return this->year;
}

void Ship::print()
{
	cout << "Ship Name : " << name << endl;
	cout << "Year Built : " << year << endl;
}

#endif // !SHIP_H
