#pragma once
#ifndef BUTTON_H
#define BUTTON_H
#include"COMMAND.h"

class Button
{
public:
	virtual void setCommand() = 0;
	virtual void getCommand() = 0; //returns the commandName
	virtual void buttonExecute( CString& data) = 0;
};

#endif // !BUTTON_H
