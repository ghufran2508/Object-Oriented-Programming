#include<iostream>
#include"PhoneCall.h"
#include<string>

using namespace std;

bool isNumber(string num)
{
	if (num.length() == 11)
	{
		for (int i = 0; i < 11; i++)
		{
			if (num[i] < 48 && num[i] > 57)
				return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}

//defualt Constructor to set default values...
PhoneCall::PhoneCall() :callerNo(""), duration(0), rateCharged(0)
{
	cout << "Default Constructor is called!!!" << endl;
}
//destructor to know that object is detroyed...
PhoneCall::~PhoneCall()
{
	cout << "~~~Destructor is called~~~" << endl;
}
//mehtod to set Caller No.
void PhoneCall::setCallerNo(string caller)
{
	//if caller number length is equal to 11 then save it
	if (isNumber(caller))
	{
		this->callerNo = caller;
	}
}
//method to set Duration of call 
void PhoneCall::setDuration(int duration)
{
	//if duration is valid then save it..
	if (duration > 0)
	{
		this->duration = duration;
	}
	//else save default
	else
	{
		this->duration = 0;
	}
}
//method to set Rate Charged
void PhoneCall::setRateCharger(float rate)
{
	//if rates are valid then save
	if (rate > 0)
	{
		this->rateCharged = rate;
	}
	//else save default
	else
	{
		this->rateCharged = 1.45;
	}
}
//method to get Caller No.
string PhoneCall::getCallerNo()
{
	return this->callerNo;
}
//method to get Duration
int PhoneCall::getDuration()
{
	return this->duration;
}
//method to get Rate Charged
float PhoneCall::getRateCharger()
{
	return this->rateCharged;
}
//method to display PhoneCall info on console
ostream& operator<<(ostream& out, const PhoneCall& call)
{
	out << "________________________________" << endl;
	out << "Caller No: " << call.callerNo << endl;
	out << "Duration: " << call.duration << " minutes" << endl;
	out << "Rate Charged: " << call.rateCharged << " / minutes" << endl;
	out << "Total Charges: " << call.duration * call.rateCharged << " $" << endl;
	out << "________________________________" << endl;
	return out;
}
//mehtod to set the values of PhoneCall object
istream& operator>>(istream& in, PhoneCall& call)
{
	string caller;
	int dura;
	float rate;
	cout << "Please Enter Caller No.: ";
	in >> caller;
	while (!isNumber(caller))
	{
		cout << "INVALID NUMBER!!!" << endl;
		cout << "Please Enter Caller No.: ";
		in >> caller;
	}
	cout << "Please Enter Duration: ";
	in >> dura;
	cout << "Please Enter RateCharged: ";
	in >> rate;

	call.callerNo = caller;
	call.duration = dura;
	call.rateCharged = rate;

	return in;
}
//method to check if both calls are same or not
bool PhoneCall::operator==(const PhoneCall& call) const
{
	//if same then return true
	if (this->callerNo == call.callerNo)
	{
		return true;
	}
	else //else return false
	{
		return false;
	}
}
//method to check if 1 call duration is greater than other or not
bool PhoneCall::operator>(const PhoneCall& call) const
{
	if (this->duration > call.duration)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//method to add both calls duration and then return int value
int PhoneCall::operator+(const PhoneCall& call) const
{
	return (this->duration + call.duration);
}
//method to return PhoneCall int value
PhoneCall::operator int() const
{
	return this->duration;
}
//method to return PhoneCall double value
PhoneCall::operator double() const
{
	return this->rateCharged;
}