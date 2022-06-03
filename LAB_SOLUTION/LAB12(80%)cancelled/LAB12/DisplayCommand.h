#pragma once
#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include"COMMAND.h"

class DisplayCommand : public virtual COMMAND
{
private:
	CString display;
public:
	DisplayCommand()
	{
		this->display = "Display";
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
		data.display();
	}

	CString getCommandName()
	{
		return this->display;
	}
};

#endif // !DISPLAYCOMMAND_H
