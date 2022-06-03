#include<iostream>
#include"MobilePhone.h"
#include<string>

using namespace std;

MobilePhone::MobilePhone()
{
	this->mfgID = 0;
	this->mfgDate = "";
	this->mfgName = "";
	this->state = false;
}

MobilePhone::MobilePhone(int id, CString date, CString name)
{
	this->mfgID = (id > 0) ? id : 0;
	this->mfgDate = date;
	this->mfgName = name;
	this->state = false;
}

MobilePhone::~MobilePhone()
{
	cout << "Phone Destroyed...!" << endl;
}

void MobilePhone::setMfgID(int id)
{
	this->mfgID = (id > 0) ? id : 0;
}

void MobilePhone::setMfgDate(CString date)
{
	this->mfgDate = date;
}

void MobilePhone::setMfgName(CString name)
{
	this->mfgName = name;
}

int MobilePhone::getMfgID() const
{
	return this->mfgID;
}

CString MobilePhone::getMfgDate() const
{
	return this->mfgDate;
}

CString MobilePhone::getMfgName() const
{
	return this->mfgName;
}

bool MobilePhone::getState() const
{
	return this->state;
}

bool MobilePhone::turnOn()
{
	this->state = true;
	cout << "Phone turned on." << endl;
	return this->state;
}

void MobilePhone::makeVoiceCall(int number)
{
	if (number > 0 && state == true)
	{
		cout << "Calling to " << number << "...." << endl;
	}
}

void MobilePhone::recordAudio()
{
	if (state == true)
	{
		string temp;
		cout << "Start recording." << endl;
		cout << "Speak into the microphone..." << endl;
		cout << "press any key to stop." << endl;
		cin >> temp;
		cout << "Recording have been saved." << endl;
	}
}

void MobilePhone::sendSMS(CString message, int number)
{
	if (number > 0 && state == true)
	{
		cout << "The message has been sent..." << endl;
	}
	else
	{
		cout << "INVALID NUMBER!!!" << endl;
	}
}

void MobilePhone::turnOff()
{
	this->state = false;
	cout << "Phone turned off." << endl;
}