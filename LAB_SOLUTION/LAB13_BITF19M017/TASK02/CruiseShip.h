#pragma once
#ifndef CRUISESHIP_H
#define CRUISESHIP_H

#include<iostream>
#include<string>
#include"Ship.h"
using namespace std;

class CruiseShip : public Ship
{
private:
	int max_passengers;
public:
	CruiseShip(string, string, int);

	void setName(string);
	void setMax(int);

	string getName() const;
	int getMax() const;

	void print() override;
};

CruiseShip::CruiseShip(string name, string year, int capacity) : Ship(name, year)
{
	this->max_passengers = (capacity > 0) ? capacity : 1;
}

void CruiseShip::setName(string name)
{
	this->Ship::setName(name);
}

void CruiseShip::setMax(int capacity)
{
	this->max_passengers = (capacity > 0) ? capacity : 1;
}

string CruiseShip::getName() const
{
	return Ship::getName();
}

int CruiseShip::getMax() const
{
	return this->max_passengers;
}

void CruiseShip::print()
{
	cout << "Ship Name : " << Ship::getName() << endl;
	cout << "Maximum number of passengers : " << max_passengers << endl;
}

#endif // !CRUISESHIP_H
