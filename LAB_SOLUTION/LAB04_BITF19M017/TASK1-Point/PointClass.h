#pragma once
class Point
{
private:
	int x;
	int y;
public:
	Point();
	Point(int a, int b);
	void setX(int a);
	void setY(int b);
	int getX();
	int getY();
	bool isValid();
	void printStars();
};