#pragma once
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class var
{
	double d;
	int i;
	string s;
	char dtype; // Possible values: ‘n’, ‘i’, ‘d’ and ‘s’ (null, int, double, string)
	// conversion from given Double in parameter to String (use as it is)
	string convert(const double a) const
	{
		stringstream oss;
		oss << a;
		return oss.str();
	}
	// conversion from given Integer in parameter to String (use as it is)
	string convert(const int a) const
	{
		stringstream oss;
		oss << a;
		return oss.str();
	}

	// Detect the data-type of the given string in parameter (can be i/d/s) (use as it is)
	char whatType(const string a) const
	{
		bool d = 0;
		for (unsigned int i = 0; i < a.length(); i++)
		{
			if (!(a[i] >= '0' && a[i] <= '9'))
			{
				if (a[i] == '.' && d == 0)
				{
					d = 1;
				}
				else
				{
					return 's';
				}
			}
		}
		if (d == 0)
			return 'i';
		return 'd';
	}

	int toInt(const string a) const;
	double toDbl(const string a) const;
public:
	var(); // default, just do dtype = ‘n’ (NULL value)
	var(const int data);
	var(const double data); // Store double value on same pattern
	var(const string data); // Store string value
	var(const char* data); // Character array will be converted to string (don’t do any manual work, s = data is sufficient)
	var(const var& a); // Copy constructor.

	//var& operator=(x);
	var& operator=(const int data);
	var& operator=(const double data);
	var& operator=(const char* data);
	var& operator=(const string data);
	var& operator=(const var& data);

	bool operator==(const var& data) const;
	//bool var(const var& data) const;
	bool operator>(const var& data) const;
	bool operator<(const var& data) const;
	bool operator<=(const var& data) const;
	bool operator>=(const var& data) const;
	bool operator!=(const var& data) const;

	var operator+(const var& data) const;
	var operator-(const var& data) const;
	var operator*(const var& data) const;
	var operator/(const var& data) const;

	char& operator[](const int a);

	var& operator++();
	var& operator++(int);
	var& operator--();
	var& operator--(int);

	char type() const;

	string toString() const;
	double parseDouble() const;
	int parseInt() const;
	bool isInt() const;
	bool isNumeric() const;
	void convertInt();
	void convertDouble();
	void convertString();

	bool isNull() const;
	~var();
	void clear();

	friend ostream& operator<<(ostream& s, const var& a);
	friend istream& operator>>(istream& s, var& a);
};