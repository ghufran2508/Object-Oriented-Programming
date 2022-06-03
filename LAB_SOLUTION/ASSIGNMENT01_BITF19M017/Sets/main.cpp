#include<iostream>
#include"Sets.h"

using namespace std;

int main()
{
	int a;
	Set set1;
	Set set2;

	for (int i = 0; i < 20; i++)
	{
		a = rand() % 10;
		set1.insertElement(a);
		set2.insertElement(a+1);
	}

	Set c = set2 - set1;
	Set d = set1 + set2;

	cout << "Set1: ";
	set1.displaySet();
	cout << endl;
	cout << "Set2: ";
	set2.displaySet();
	cout << endl;
	cout << "C(differenece): ";
	c.displaySet();
	cout << endl;
	cout << "D(add): ";
	d.displaySet();
	cout << endl;

	int subset = d.isSubSet(c);
	if (subset == 1)
	{
		cout << "C is a proper subset of d" << endl;
	}
	else if (subset == 0)
	{
		cout << "C is not a subset of d." << endl;
	}
	else if (subset == 2)
	{
		cout << "C is an improper subset of d." << endl;
	}

	return 0;
}