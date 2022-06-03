#pragma once
#ifndef CONVERTTOUPPER_H
#define CONVERTTOUPPER_H

#include"COMMAND.h"

class ConvertToUpperCommand : public virtual COMMAND
{
private:
	CString ConvertToUpper;
public:
	ConvertToUpperCommand()
	{
		this->ConvertToUpper = "Convert To Upper";
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
		data.makeUpper();
	}

	CString getCommandName()
	{
		return this->ConvertToUpper;
	}
};

#endif // !CONVERTTOUPPER_H
