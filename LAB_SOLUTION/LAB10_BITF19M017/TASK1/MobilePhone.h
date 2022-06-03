#pragma once
#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H
#include"CString.h"

using namespace std;

class MobilePhone
{
private:
	int mfgID;
	CString mfgDate;
	CString mfgName;
	bool state;
public:
	MobilePhone();
	~MobilePhone();
	MobilePhone(int, CString, CString);

	void setMfgID(int);
	void setMfgDate(CString);
	void setMfgName(CString);

	int getMfgID() const;
	CString getMfgDate() const;
	CString getMfgName() const;
	bool getState() const;

	bool turnOn();

	void makeVoiceCall(int);

	void recordAudio();

	void sendSMS(CString, int);

	void turnOff();
};

#endif //	!MOBILEPHONE_H