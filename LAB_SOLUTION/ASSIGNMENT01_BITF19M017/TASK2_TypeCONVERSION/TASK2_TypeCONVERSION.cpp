// TASK2_TypeCONVERSION.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include"Var.h"

using namespace std;

int main()
{
	var a = 10;
	var b = "10";
	if (a == b) {
		// They are equal by regular comparison
		cout << "10 == 10" << endl;
	}
	//if (a.equals(b)) {
	//	// They are not equal by strict comparison
	//	cout << "10 is 10 with matching datatype" << endl;
	//}
	// a is internally integer, a+1 = 11
	cout << "10 + 1 = " << a + 1 << " (" << a.type() << ")" << endl;
	// b is internally string, b+1= 101
	cout << "10 + 1 = " << b + 1 << " (" << b.type() << ")" << endl;
	// b is now internally an integer, b+1= 11
	b.convertInt();
	cout << "10 + 1 = " << b + 1 << " (" << b.type() << ")" << endl;
	// Automatic input type
	var c;
	cin >> c;
	cout << c.type();

	return 0;
}