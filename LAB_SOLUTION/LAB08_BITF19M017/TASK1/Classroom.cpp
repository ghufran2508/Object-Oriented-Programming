#include"Classroom.h"
#include<iostream>

using namespace std;

Classroom::Classroom(int r_num, int cap)
{
	if (r_num > 0)
		this->roomNumber = r_num;
	else
		this->roomNumber = 1;

	if (cap >= 10)
		this->capacity = cap;
	else
		this->capacity = 10;
}

Classroom::Classroom(Classroom& b)
{
	this->roomNumber = b.roomNumber;
	this->capacity = b.capacity;
}

void Classroom::setRoomNumber(int r_num)
{
	if (r_num > 0)
		this->roomNumber = r_num;
	else
		this->roomNumber = 1;
}

void Classroom::setCapacity(int cap)
{
	if (cap >= 10)
		this->capacity = cap;
	else
		this->capacity = 10;
}

int Classroom::getRoomNumber() const
{
	return this->roomNumber;
}

int Classroom::getCapacity() const
{
	return this->capacity;
}

void Classroom::operator=(const Classroom& b)
{
	this->roomNumber = b.roomNumber;
	this->capacity = b.capacity;
}

void Classroom::printClassroom()
{
	cout << "ClassRoom Number: " << this->roomNumber << endl;
	cout << "ClassRoom Capacity: " << this->capacity << endl;
}