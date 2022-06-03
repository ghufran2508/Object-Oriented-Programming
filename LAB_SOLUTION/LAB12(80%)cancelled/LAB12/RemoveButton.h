#pragma once
#ifndef REMOVEBUTTON_H
#define REMOVEBUTTON_H

#include"Button.h"
#include"COMMAND.h"
#include"RemoveCommand.h"

class RemoveButton : public virtual Button
{
private:
	COMMAND* remove;
public:
	void setCommand()
	{
		remove = new RemoveCommand();
	}
	void getCommand()
	{
		remove->getCommandName();
	}
	void buttonExecute(CString& data)
	{
		if (remove->canExecute(data))
			remove->Execute(data);
	}
};

#endif // !REMOVEBUTTON_H
