#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include"CString.h"

class COMMAND
{
public:
	virtual bool canExecute(const CString& data) = 0;
	virtual void Execute( CString& data) = 0;
	virtual CString getCommandName() = 0;
};

#endif //!COMMAND_H