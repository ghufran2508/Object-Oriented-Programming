#pragma once
#ifndef CONVERTTOUPPERBUTTON_H
#define CONVERTTOUPPERBUTTON_H
#include"Button.h"
#include"COMMAND.h"
#include"ConvertToUpperCommand.h"

class ConvertToUpperButton : public virtual Button
{
private:
	COMMAND* ConvertToUpper;
public:
	void setCommand()
	{
		ConvertToUpper = new ConvertToUpperCommand();
	}

	void getCommand()
	{
		ConvertToUpper->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if (ConvertToUpper->canExecute(data))
			ConvertToUpper->Execute(data);
	}
};

#endif // !CONVERTTOUPPERBUTTON_H
