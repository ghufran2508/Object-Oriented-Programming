#pragma once
#ifndef CONVERTTOINTBUTTON_H
#define CONVERTTOINTBUTTON_H

#include<iostream>
#include"Button.h"
#include"COMMAND.h"
#include"ConvertToIntCommand.h"
using namespace std;

class ConvertToIntButton : public virtual Button
{
private:
	COMMAND* converttoint;
public:

	void setCommand()
	{
		this->converttoint = new ConvertToIntCommand();
	}

	void getCommand()
	{
		converttoint->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if (converttoint->canExecute(data))
			converttoint->Execute(data);
		else
			cout << "ERROR!!!" << endl;
	}
};

#endif // !CONVERTTOINTBUTTON_H
