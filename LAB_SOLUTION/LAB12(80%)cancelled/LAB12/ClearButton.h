#pragma once
#ifndef CLEARBUTTON_H
#define CLEARBUTTON_H
#include"Button.h"
#include"COMMAND.h"
#include"ClearCommad.h"

class ClearButton : public virtual Button 
{
private:
	COMMAND* buttonCommand;
public:
	void setCommand()
	{
		buttonCommand = new ClearCommand();
	}
	void getCommand()
	{
		buttonCommand->getCommandName();
	}
	void buttonExecute( CString& data)
	{
		if (buttonCommand->canExecute( data))
			buttonCommand->Execute(data);
	}
};

#endif // !CLEARBUTTON_H
