#include<iostream>
#include"CarpetCost.h"

using namespace std;

int main()
{
	FeetInches l(9, 12);
	FeetInches w(11, 12);
	//Carpet will be 10 feet long and 12 feet long
	RoomDimension R(l, w);

	RoomCarpet my(R);

	cout << "Total Cost of Carpet: " << my.calculateTotalCost() << endl;

	return 0;
}