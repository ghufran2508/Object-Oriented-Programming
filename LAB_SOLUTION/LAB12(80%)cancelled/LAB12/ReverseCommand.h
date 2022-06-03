#pragma once
#ifndef REVERSECOMMAND_H
#define REVERSECOMMAND_H

#include"COMMAND.h"

class ReverseCommand : public virtual COMMAND
{
private:
	CString reverse;
public:
	ReverseCommand()
	{
		this->reverse = "Reverse";
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
		data.reverse();
	}

	CString getCommandName()
	{
		return this->reverse;
	}
};

#endif // !REVERSECOMMAND_H
