#pragma once

class Classroom
{
private:
	int roomNumber;
	int capacity;
public:
	Classroom(int r_num = 1, int cap = 10);
	Classroom(Classroom&);
	void setRoomNumber(int number);
	void setCapacity(int capacity);
	int getRoomNumber() const;
	int getCapacity() const;
	void operator=(const Classroom&);
	void printClassroom();
};