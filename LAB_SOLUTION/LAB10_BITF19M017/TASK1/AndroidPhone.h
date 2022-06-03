#pragma once
#ifndef ANDROIDPHONE_H
#define ANDROIDPHONE_H
#include"MobilePhone.h"
#include"CString.h"

class AndroidPhone: protected MobilePhone
{
private:
	CString KernelVersion;
	CString androidVersion;
public:
	AndroidPhone(); // display message “Hello, Android!”
	void launchSubwaySurfers(); // display message “Playing Subway Surfers”
	void launchFlynx(); // display message “Using Flynx browser”
	CString getKernelVersion() const; // returns kernel version of phone
	void setKernelVersion(CString); // sets kernel version of phone
	CString getiOSVersion() const; // returns android version of phone
	void setiOSVersion(CString); // sets android version of phone
	~AndroidPhone(); // display message “Android phone destroyed…”
};

#endif // !ANDROIDPHONE_H
