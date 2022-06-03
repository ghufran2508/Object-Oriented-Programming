#pragma once
#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include"COMMAND.h"
#include<iostream>
using namespace std;

class RemoveCommand : public virtual COMMAND
{
private:
	CString remove;
public:
	RemoveCommand()
	{
		this->remove = "Remove";
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
		CString toremove = " ";
		cout << "Enter the string you want to remove: ";
		toremove.input();
		data.replace(toremove, "");
	}

	CString getCommandName()
	{
		return this->remove;
	}
};

#endif // !REMOVECOMMAND_H
