#pragma once
#include<iostream>
using namespace std;


template <class Min>
Min minimum(Min a, Min b)
{
	return (a < b) ? a : b;
}

template <class Max>
Max maximum(Max a, Max b)
{
	return (a > b) ? a : b;
}

template <class abs>
abs absolute(abs a)
{
	return (a >= 0) ? a : a * -1;
}

void menu(int& choice)
{
	cout << "Choose from the following..." << endl;
	cout << "1. Minimum." << endl;
	cout << "2. Maximum." << endl;
	cout << "3. Absolute." << endl;
	cin >> choice;

	while (choice > 3 && choice < 1)
	{
		cout << "INVALID OPTION!!!!" << endl;
		cin >> choice;
	}
}

void DataType(int& choice)
{
	cout << "Please choose the datatype..." << endl;
	cout << "1. Integer." << endl;
	cout << "2. Float." << endl;
	cout << "3. Double." << endl;
	cin >> choice;

	while (choice > 3 && choice < 1)
	{
		cout << "Invalid Input!!!" << endl;
		cin >> choice;
	}
}