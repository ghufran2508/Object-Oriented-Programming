#pragma once
#ifndef DATACONVERTER_H
#define DATACONVERTER_H

#include"CString.h"
#include"Date.h"

class DataConverter
{
public:
	void dataConverter(CString& destination, const Date& source); //Date to CString


	void dataConverter(Date&, const CString&); //CString to Date


	void dataConverter(CString& str, const int value)
	{
		int temp = value, div = 1;
		int f, counter = 0;

		while (temp > 0)
		{
			counter++;
			temp /= 10;
		}

		for (int i = 0; i < counter - 1; i++)
		{
			div *= 10;
		}
		temp = value;
		while (div > 0)
		{
			f = temp / div;
			temp = temp % div;
			div /= 10;

			if (f == 1) str.concatEqual("1");
			else if (f == 2) str.concatEqual("2");
			else if (f == 3) str.concatEqual("3");
			else if (f == 4) str.concatEqual("4");
			else if (f == 5) str.concatEqual("5");
			else if (f == 6) str.concatEqual("6");
			else if (f == 7) str.concatEqual("7");
			else if (f == 8) str.concatEqual("8");
			else if (f == 9) str.concatEqual("9");
			else if (f == 0) str.concatEqual("0");
		}
	}

	void dataConverter(CString& str, const float value) //Float to CString
	{
		int temp = value, div = 1;
		int f, counter = 0;

		while (temp > 0)
		{
			counter++;
			temp /= 10;
		}

		for (int i = 0; i < counter - 1; i++)
		{
			div *= 10;
		}
		temp = value;
		while (div > 0)
		{
			f = temp / div;
			temp = temp % div;
			div /= 10;

			if (f == 1) str.concatEqual("1");
			else if (f == 2) str.concatEqual("2");
			else if (f == 3) str.concatEqual("3");
			else if (f == 4) str.concatEqual("4");
			else if (f == 5) str.concatEqual("5");
			else if (f == 6) str.concatEqual("6");
			else if (f == 7) str.concatEqual("7");
			else if (f == 8) str.concatEqual("8");
			else if (f == 9) str.concatEqual("9");
			else if (f == 0) str.concatEqual("0");
		}

		str += ".";

		float tempd = value - int(value);

		for (int i = 0; i < 6; i++)
		{
			tempd *= 10;
		}

		div = 1;
		counter = 0;

		while (tempd > 1)
		{
			counter++;
			tempd /= 10;
		}

		for (int i = 0; i < counter - 1; i++)
		{
			div *= 10;
		}
		tempd = value - int(value);
		for (int i = 0; i < 6; i++)
		{
			tempd *= 10;
		}
		int a = int(tempd);
		while (div > 0)
		{
			f = a / div;
			a = a % div;
			div /= 10;

			if (f == 1) str.concatEqual("1");
			else if (f == 2) str.concatEqual("2");
			else if (f == 3) str.concatEqual("3");
			else if (f == 4) str.concatEqual("4");
			else if (f == 5) str.concatEqual("5");
			else if (f == 6) str.concatEqual("6");
			else if (f == 7) str.concatEqual("7");
			else if (f == 8) str.concatEqual("8");
			else if (f == 9) str.concatEqual("9");
			else if (f == 0) str.concatEqual("0");
		}
	}

	void dataConverter(int& destination, const CString source) {
		destination = source.toInteger();
	} //CString to Int

	void dataConverter(float& destination, const CString source) //CString to Float
	{
		destination = source.toFloat();
	}
};

#endif // !DATACONVERTER_H
