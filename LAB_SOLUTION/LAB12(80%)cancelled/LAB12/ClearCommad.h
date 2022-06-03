#pragma once
#ifndef CLEARCOMMAND_H
#define CLEARCOMMAND_H

#include"COMMAND.h"

class ClearCommand : public virtual COMMAND
{
private:
	CString clear;
public:
	ClearCommand() {
		this->clear = "Clear";
	}
	bool canExecute(const CString& data) {
		if (data.isEmpty())
			return false;
		else return true;
	}
	void Execute( CString& data) {
		data.remove(0, data.getLength());
	}
	CString getCommandName() {
		return clear;
	}
};
#endif // !CLEARCOMMAND_H
