#pragma once
#ifndef CONVERTTOFLOATBUTTON_H
#define CONVERTTOFLOATBUTTON_H
#include<iostream>
#include"Button.h"
#include"COMMAND.h"
#include"ConvertToFloatCommand.h"

using namespace std;

class ConvertToFloatButton : public virtual Button
{
	COMMAND* converttofloat;
public:

	void setCommand()
	{
		converttofloat = new ConvertToFloatCommand();
	}

	void getCommand()
	{
		converttofloat->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if (converttofloat->canExecute(data))
			converttofloat->Execute(data);
		else
		{
			cout << "ERROR" << endl;
		}
	}
};

#endif // !CONVERTTOFLOATBUTTON_H
