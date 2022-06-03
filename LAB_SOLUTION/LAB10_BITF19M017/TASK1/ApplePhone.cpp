#include<iostream>
#include"ApplePhone.h"
#include<string>

using namespace std;

ApplePhone::ApplePhone()
{
	this->iOSVersion = "";
	cout << "Hello, Apple" << endl;
}

void ApplePhone::launchSiri()
{
	if(getState())
		cout << "Talking to Siri" << endl;
}

void ApplePhone::launchPaper()
{
	if(getState())
		cout << "Using Paper app" << endl;
}

CString ApplePhone::getiOSVersion() const
{
	return this->iOSVersion;
}

void ApplePhone::setiOSVersion(CString version)
{
	this->iOSVersion = version;
}

ApplePhone::~ApplePhone()
{
	cout << "Apple Phone destroyed..." << endl;
}