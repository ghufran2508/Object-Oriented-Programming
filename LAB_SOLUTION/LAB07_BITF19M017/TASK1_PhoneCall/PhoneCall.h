#pragma once
#include<string>

using namespace std;

class PhoneCall
{
private:
	//Phone Number
	string callerNo;
	//Duration of the call in minutes
	int duration;
	//rate charged per minute
	float rateCharged;
public:
	//Default Constructor
	PhoneCall();
	//Destructor
	~PhoneCall();
	//method to set Caller No.
	void setCallerNo(string);
	//,ethod to set Duration of the call
	void setDuration(int);
	//method to set rate charged per minute on the call
	void setRateCharger(float);
	//method to get Caller No.
	string getCallerNo();
	//method to get call duration
	int getDuration();
	//method to get rate charged
	float getRateCharger();
	//method to extract PhoneCall info
	friend ostream& operator<<(ostream&, const PhoneCall&);
	//method to insert PhoneCall info
	friend istream& operator>>(istream&, PhoneCall&);
	//method to check if both calls are same or not
	bool operator==(const PhoneCall&) const;
	//method to check if 1 call duration is greater than other call or not
	bool operator>(const PhoneCall&) const;
	//method to add both calls duration time
	int operator+(const PhoneCall&) const;
	//method to convert PhoneCall object to int
	//i.e return int value of the Class
	operator int() const;
	//method to convert PhoneCall object to double
	//i.e return double value of the Class
	operator double() const;
};