#pragma once
#ifndef WINDOWPHOME_H
#define WINDOWPHONE_H
#include"MobilePhone.h"
#include"CString.h"

using namespace std;

class WindowsPhone : private MobilePhone
{
private:
	CString productName;
	CString buildNumber;
public:
	WindowsPhone(); // display message “Hello, Windows!”
	void launchFoundbite(); // display message “Checking Foundbite newsfeed”
	void launchXboxGame(); // display message “Playing Xbox game”
	CString getProductName(); // returns product name of phone
	void setProductVersion(CString); // sets product name of phone
	CString getBuildNumber(); // returns build number of phone
	void setBuildNumber(CString); // sets build number of phone
	~WindowsPhone(); // display message “Windows phone destroyed…”
};

#endif // !WINDOWPHOME_H
