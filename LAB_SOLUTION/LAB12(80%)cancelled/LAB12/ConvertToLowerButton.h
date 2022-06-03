#pragma once
#ifndef CONVERTTOLOWERBUTTON_H
#define CONVERTTOLOWERBUTTON_H

#include"Button.h"
#include"COMMAND.h"
#include"CommandToLowerCommand.h"

class ConvertToLowerButton : public virtual Button
{
private:
	COMMAND* convertToLower;
public:
	void setCommand()
	{
		convertToLower = new ConvertToLowerCommand();
	}

	void getCommand()
	{
		convertToLower->getCommandName();
	}

	void buttonExecute(CString& data)
	{
		if(convertToLower->canExecute(data))
			convertToLower->Execute(data);
	}
};

#endif // !CONVERTTOLOWERBUTTON_H
