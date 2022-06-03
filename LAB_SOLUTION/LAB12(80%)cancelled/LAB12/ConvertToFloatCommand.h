#pragma once
#ifndef CONVERTTOFLOATCOMMAND_H
#define CONVERTTOFLOATCOMMAND_H

#include"COMMAND.h"

class ConvertToFloatCommand : public virtual COMMAND
{
private:
	CString converttofloat;
public:
	ConvertToFloatCommand()
	{
		this->converttofloat = "Convert To Float";
	}

	bool canExecute(const CString& data)
	{
		if (data.isEmpty())
			return false;
		else
			return true;
	}

	void Execute(CString& data)
	{
		float value = data.toFloat();
		CString str;
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

		data = str;
	}

	CString getCommandName()
	{
		return this->converttofloat;
	}
};

#endif // !CONVERTTOFLOATCOMMAND_H
