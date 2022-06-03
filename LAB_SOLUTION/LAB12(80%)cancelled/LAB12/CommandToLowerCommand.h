#pragma once
#ifndef CONVERTTOLOWERCOMMAND_H
#define CONVERTTOLOWERCOMMAND_H

#include"COMMAND.h"

class ConvertToLowerCommand : public virtual COMMAND
{
private:
	CString ConvertToLower;
public:
	ConvertToLowerCommand()
	{
		this->ConvertToLower = "Convert To Lower";
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
		data.makeLower();
	}

	CString getCommandName()
	{
		return this->ConvertToLower;
	}
};

#endif // !CONVERTTOLOWERCOMMAND_H
