#pragma once
#ifndef REVERSEBUTTON_H
#define REVERSEBUTTON_H

#include"Button.h"
#include"COMMAND.h"
#include"ReverseCommand.h"

class ReverseButton : public virtual Button
{
private:
	COMMAND* reverse;
public:

	void setCommand()
	{
		reverse = new ReverseCommand();
	}

	void getCommand()
	{
		reverse->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if (reverse->canExecute(data))
			reverse->Execute(data);
	}
};

#endif // !REVERSEBUTTON_H
