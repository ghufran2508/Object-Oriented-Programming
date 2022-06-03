#pragma once
#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include"COMMAND.h"
#include<iostream>
using namespace std;

class AddCommand : public virtual COMMAND
{
private:
	CString add;
public:
	AddCommand()
	{
		this->add = "Add";
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
		CString adding = " ";
		cout << "Enter the string you want to add: ";
		adding.input();
		data.concatEqual(adding);
	}

	CString getCommandName()
	{
		return this->add;
	}
};

#endif // !ADDCOMMAND_H
