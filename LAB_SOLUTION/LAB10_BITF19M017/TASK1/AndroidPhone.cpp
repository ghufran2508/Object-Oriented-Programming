#include<iostream>
#include"AndroidPhone.h"

using namespace std;

AndroidPhone::AndroidPhone():MobilePhone()
{
	this->KernelVersion = "";
	this->androidVersion = "";
	cout << "Hello, Android!" << endl;
}

void AndroidPhone::launchSubwaySurfers()
{
	if(getState())
		cout << "Playing Subway Surfers" << endl;
}

void AndroidPhone::launchFlynx()
{
	if(getState())
		cout << "Using Flynx browser" << endl;
}

void AndroidPhone::setKernelVersion(CString version)
{
	this->KernelVersion = version;
}

CString AndroidPhone::getKernelVersion() const
{
	return this->KernelVersion;
}

void AndroidPhone::setiOSVersion(CString version)
{
	this->androidVersion = version;
}

CString AndroidPhone::getiOSVersion() const
{
	return this->androidVersion;
}

AndroidPhone::~AndroidPhone()
{
	cout << "Android phone destroyed..." << endl;
}