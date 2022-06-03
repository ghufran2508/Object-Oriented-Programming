#pragma once
#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include<iostream>
#include<string>
#include"Ship.h"
using namespace std;

class CargoShip : public Ship
{
private:
	int cargo_capacity;
public:
	CargoShip(string, string, int);

	void setName(string);
	void setCapacity(int);

	string getName() const;
	int getCapacity() const;

	void print() override;
};

CargoShip::CargoShip(string name, string year, int capacity) : Ship(name, year)
{
	this->cargo_capacity = (capacity > 0) ? capacity : 1;
}

void CargoShip::setName(string name)
{
	this->Ship::setName(name);
}

void CargoShip::setCapacity(int capacity)
{
	this->cargo_capacity = (capacity > 0) ? capacity : 1;
}

string CargoShip::getName() const
{
	return Ship::getName();
}

int CargoShip::getCapacity() const
{
	return this->cargo_capacity;
}

void CargoShip::print()
{
	cout << "Ship Name : " << Ship::getName() << endl;
	cout << "Maximum number of passengers : " << cargo_capacity << endl;
}


#endif // !CARGOSHIP_H
