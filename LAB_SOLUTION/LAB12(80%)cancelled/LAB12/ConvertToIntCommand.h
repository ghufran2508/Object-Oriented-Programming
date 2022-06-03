#pragma once
#ifndef CONVERTTOINTCOMMAND_H
#define CONVERTTOINTCOMMAND_H

#include"COMMAND.h"

class ConvertToIntCommand : public virtual COMMAND
{
private:
	CString ConvertToInt;
public:
	ConvertToIntCommand()
	{
		this->ConvertToInt = "Convert to Int";
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
		int number = data.toInteger();
		CString toInt;
		int temp = number, div = 1;
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
		temp = number;
		while (div > 0)
		{
			f = temp / div;
			temp = temp % div;
			div /= 10;

			if (f == 1) toInt.concatEqual("1");
			else if (f == 2) toInt.concatEqual("2");
			else if (f == 3) toInt.concatEqual("3");
			else if (f == 4) toInt.concatEqual("4");
			else if (f == 5) toInt.concatEqual("5");
			else if (f == 6) toInt.concatEqual("6");
			else if (f == 7) toInt.concatEqual("7");
			else if (f == 8) toInt.concatEqual("8");
			else if (f == 9) toInt.concatEqual("9");
			else if (f == 0) toInt.concatEqual("0");
		}
		data = toInt;
	}

	CString getCommandName()
	{
		return this->ConvertToInt;
	}
};

#endif // !CONVERTTOINTCOMMAND_H
