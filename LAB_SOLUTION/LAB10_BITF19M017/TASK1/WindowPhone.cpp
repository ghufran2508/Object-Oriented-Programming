#include<iostream>
#include"WindowPhone.h"

using namespace std;

WindowsPhone::WindowsPhone()
{
	this->productName = "";
	this->buildNumber = "";
	cout << "Hello, Windows!" << endl;
}

void WindowsPhone::launchFoundbite()
{
	if (getState())
	{
		cout << "Checking Foundbite newsfeed" << endl;
	}
}

void WindowsPhone::launchXboxGame()
{
	if (getState())
	{
		cout << "Playing Xbox game" << endl;
	}
}

CString WindowsPhone::getProductName()
{
	return this->productName;
}

void WindowsPhone::setProductVersion(CString name)
{
	this->productName = name;
}

CString WindowsPhone::getBuildNumber()
{
	return this->buildNumber;
}

void WindowsPhone::setBuildNumber(CString number)
{
	this->buildNumber = number;
}

WindowsPhone::~WindowsPhone()
{
	cout << "Windows phone destroyed..." << endl;
}