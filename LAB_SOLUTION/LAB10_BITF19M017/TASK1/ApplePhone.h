#pragma once
#ifndef APPLEPHONE_H
#define APPLEPHONE_H
#include"MobilePhone.h"
#include"CString.h"

using namespace std;

class ApplePhone: public MobilePhone
{
private:
	CString iOSVersion;
public:
	ApplePhone(); // display message “Hello, Apple!”
	void launchSiri(); // display message “Talking to Siri”
	void launchPaper(); // display message “Using Paper app”
	CString getiOSVersion() const; // returns iOS Version of phone
	void setiOSVersion(CString); // sets iOS Version of phone
	~ApplePhone(); // display message “Apple phone destroyed…”
};

#endif // !APPLEPHONE_H
