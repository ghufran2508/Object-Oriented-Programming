#include<iostream>
#include"MixedFraction.h"

using namespace std;

const int totalFrac = 5;

int main()
{
	int integer;
	int numerator;
	int denominator;
	MixedFraction frac[totalFrac];

	for (int i = 0; i < 2; i++)
	{
		cout << "For Fraction#" << i + 1 << ": " << endl;
		cout << "Enter integer: ";
		cin >> integer;
		frac[i].setIntegralPart(integer);
		cout << "Enter numearator: ";
		cin >> numerator;
		while (numerator < 0)
		{
			cout << "[+]INVALID INPUT!!!\nPlease enter positive integer..." << endl;
			cout << "Enter numearator: ";
			cin >> numerator;
		}
		frac[i].setNumerator(numerator);
		cout << "Enter denominator: ";
		cin >> denominator;
		while (denominator <= 0)
		{
			cout << "[+]INVALID INPUT!!!\nPlease enter poisitive integer greater than than 0" << endl;
			cout << "Enter denominator: ";
			cin >> denominator;
		}
		frac[i].setDenominator(denominator);
	}

	cout << "Fraction#1: ";
	frac[0].display();
	cout << "Decimal: " << frac[0].evaluate() << endl;
	cout << "\nFraction#2: ";
	frac[1].display();
	cout << "Decimal: " << frac[1].evaluate() << endl;

	frac[2] = frac[0] + frac[1];
	cout << "Fraction#3 = Fraction#1 + Fracion#2: ";
	frac[2].display();
	cout << "Decimal: " << frac[2].evaluate() << endl;
	frac[3] = frac[0] - frac[1];
	cout << "Fraction#4 = Fraction#1 - Fracion#2: ";
	frac[3].display();
	cout << "Decimal: " << frac[3].evaluate() << endl;
	frac[4] = frac[0] * frac[1];
	cout << "Fraction#5 = Fraction#1 * Fracion#2: ";
	frac[4].display();
	cout << "Decimal: " << frac[4].evaluate() << endl;
	frac[2] = frac[4] / frac[0];
	cout << "Fraction#3 = Fraction#5 / Fracion#1: ";
	frac[2].display();
	cout << "Decimal: " << frac[2].evaluate() << endl;
	frac[3] = frac[0] + frac[2]++;
	cout << "With post increment operator" << endl;
	cout << "Fraction#4 = Fraction#1 + Fracion#3++: ";
	frac[3].display();
	cout << "Decimal: " << frac[3].evaluate() << endl;

	cout << "With pre decrement operator" << endl;
	cout << "Fraction#4 = Fraction#1 + (--Fracion#3): ";
	frac[3].display();
	cout << "Decimal: " << frac[3].evaluate() << endl;

	frac[0] = -frac[0];
	cout << "Fraction#1(negative): ";
	frac[0].display();
	cout << "Decimal: " << frac[0].evaluate() << endl;

	frac[0] += frac[1];
	cout << "fraction#1 += fratcion#2: ";
	frac[0].display();
	cout << "Decimal: " << frac[0].evaluate() << endl;
	frac[1] /= frac[2];
	cout << "fraction#2 /= fratcion#3: ";
	frac[1].display();
	cout << "Decimal: " << frac[1].evaluate() << endl;
	frac[2] *= frac[3];
	cout << "fraction#3 *= fratcion#4: ";
	frac[2].display();
	cout << "Decimal: " << frac[2].evaluate() << endl;
	frac[3] -= frac[4];
	cout << "fraction#4 -= fratcion#5: ";
	frac[3].display();
	cout << "Decimal: " << frac[3].evaluate() << endl;

	return 0;
}