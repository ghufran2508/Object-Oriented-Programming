#include<iostream>
#include"PointClass.h"

using namespace std;

Point::Point()
{
	x = 0; 
	y = 0;
}

Point::Point(int a, int b)
{
	x = a;
	y = b;
}

void Point::setX(int a)
{
	x = a;
}

void Point::setY(int b)
{
	y = b;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

bool Point::isValid()
{
	if (x > 0 && y > 0)
		return true;
	else
		return false;
}

void Point::printStars()
{
	if (isValid())
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
				cout << "*";
			cout << endl;
		}
	}
	else
	{
		cout << "[+]Points not valid!!!" << endl;
	}
}