#pragma once
#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include"Button.h"
#include"COMMAND.h"
#include"AddCommand.h"

class AddButton : public virtual Button
{
private:
	COMMAND* add;
public:
	void setCommand()
	{
		add = new AddCommand();
	}
	void getCommand()
	{
		add->getCommandName();
	}
	void buttonExecute(CString& data)
	{
		if (add->canExecute(data))
			add->Execute(data);
	}
};

#endif // !ADDBUTTON_H
