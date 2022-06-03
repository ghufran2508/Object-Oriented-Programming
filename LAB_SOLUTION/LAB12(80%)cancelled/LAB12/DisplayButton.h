#pragma once
#ifndef DISPLAYBUTTON_H
#define DISPLAYBUTTON_H

#include"Button.h"
#include"COMMAND.h"
#include"DisplayCommand.h"

class DisplayButton : public virtual Button
{
private:
	COMMAND* Display;
public:
	void setCommand()
	{
		Display = new DisplayCommand();
	}

	void getCommand()
	{
		Display->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if (Display->canExecute(data))
			Display->Execute(data);
	}
};

#endif // !DISPLAYBUTTON_H
