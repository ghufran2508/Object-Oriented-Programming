#include<iostream>
#include"Var.h"

using namespace std;

int var::toInt(const string a) const
{
	// Implement/Use any library function to convert strings to integers.
	// If there are any non-integer characters, ignore them and convert rest
	int num = 0;
	//for every character in string...
	for (int i = 0; i < a.size(); i++)
	{
		//if any number is a number(comparing by ascii code)
		if (a[i] >= 48 && a[i] <= 57)
		{
			//then store it in the num.
			/*for example if string is "123ha" ,then after 1st loop num will store -> 0*10 + 1;.
			  after second loop -> 1*10 + 2, and after 3rd loop -> 12*10 + 3.
			  through this it will store the complete integer as 123.*/
			num = num * 10 + (a[i] - 48);
		}
		//if a decimal is found. then stop it there, because integer cannot store after decimal values
		if (a[i] == 46)
			break;
	}
	//if a[0] contains negation sign, then negate the num..
	if (a[0] == 45)
		num *= -1;
	//return integer
	return num;
}

double var::toDbl(const string a) const
{
	// Implement/Use any library function to convert double to integers.
	// If there are any non-double characters, ignore them but convert rest
	//num1 to store before becimal numbers.
	double num1 = 0;
	//num2 to store after decimal values.
	double num2 = 0;
	//divider to process the num2 as a decimal
	int divider = 1;
	//for every num in string...
	for (int i = 0; i < a.size(); i++)
	{
		//if any number is a number(comparing by ascii code)
		if (a[i] >= 48 && a[i] <= 57)
		{
			//then store it in the num.
		/*for example if string is "123ha" ,then after 1st loop num will store -> 0*10 + 1;.
		  after second loop -> 1*10 + 2, and after 3rd loop -> 12*10 + 3.
		  through this it will store the complete integer as 123.*/
			num1 = num1 * 10 + (a[i] - 48);
		}
		//if a decimal point is found, then num2 processing will start
		if (a[i] == 46)
		{
			//for every num in string after decimal point...
			for (int j = i; j < a.size(); j++)
			{
				//if string is a number then convert.
				if (a[j] >= 48 && a[j] <= 57)
				{
					num2 = num2 * 10 + (a[j] - 48);
				}
			}
			break;
		}
	}
	int check = num2;
	//a divider check to make num2 a complete decimal number.
	//for example-> if num2 is 123, then divider would become 1000.
	//and dividing num2 by divider, num2 would become 0.123
	for (int i = 0; check > 0; i++)
	{
		divider *= 10;
		check /= 10;
	}

	num2 /= divider;
	//adding decimal to num1
	num1 += num2;

	if (a[0] == 45)
		num1 *= -1;
	//return double.
	return num1;
}
//default constructor initializing datatype by 'n'(NULL)
var::var()
{
	dtype = 'n';
}
//Constructor with integer data type
var::var(const int data)
{
	//storing integer and changing data tyoe to 'i'(integer)
	i = data;
	dtype = 'i';
}
//Constructor with double data type
var::var(const double data)
{
	//storing double and changing data type to 'd'(double)
	d = data;
	dtype = 'd';
}
//Constructor with string data type
var::var(const string data)
{
	//storing string and changing data type to 's'(string)
	s = data;
	dtype = 's';
}
//Construcotr with char array datay type
var::var(const char* data)
{
	//storing char array and changing data type to 's'(string)
	s = data;
	dtype = 's';
}
//Copy Constructor 
var::var(const var& a)
{
	//storing data type of reference Object
	dtype = a.dtype;
	//and then store data as of data type
	if (dtype == 'i')
	{
		i = a.i;
	}
	else if (dtype == 'd')
	{
		d = a.d;
	}
	else if (dtype == 's')
	{
		s = a.s;
	}
}
//equal to operator to store values to reference Object
var& var::operator=(const int data)
{
	//store integer values of other object and then return this object
	i = data;
	dtype = 'i';
	return (*this);
}

var& var::operator=(const double data)
{
	//store double values of other object and then return this object
	d = data;
	dtype = 'd';
	return (*this);
}

var& var::operator=(const char* data)
{
	//store char array(string) value of other object and then return this object
	s = data;
	dtype = 's';
	return(*this);
}

var& var::operator=(const string data)
{
	//store string values of other object and then return this object
	s = data;
	dtype = 's';
	return(*this);
}

var& var::operator=(const var& data)
{
	//store values of other object and then return this object
	*this = data;
	return (*this);
}
//double equal to oprator to check if oth Object are same or not
bool var::operator==(const var& data) const
{
	/*check data type of both object and then compare the result
	return the comparison will return in true or false.*/
	if (dtype == 'i' && data.dtype == 'i')
		return (i == data.i);
	else if (dtype == 'd' && data.dtype == 'd')
		return (d == data.d);
	else if (dtype == 's' && data.dtype == 's')
		return (s == data.s);
	else if (dtype == 'i' && data.dtype == 's')
		return (convert(i) == data.s);
	else if (dtype == 's' && data.dtype == 'i')
		return (s == convert(data.i));
	else if (dtype == 'd' && data.dtype == 's')
		return (convert(d) == data.s);
	else if (dtype == 's' && data.dtype == 'd')
		return (s == convert(data.d));
	else if (dtype == 'i' && data.dtype == 'd')
		return (i == data.d);
	else if (dtype == 'd' && data.dtype == 'i')
		return (d == data.i);
	else if (dtype == 'n' && data.dtype == 'n')
		return true;
	else
		return false;
}

//bool var::var(const var& data) const
//{
//	if (dtype == 'i' && data.dtype == 'i')
//		return (i == data.i);
//	else if (dtype == 'd' && data.dtype == 'd')
//		return (d == data.d);
//	else if (dtype == 's' && data.dtype == 's')
//		return (s == data.s);
//	else if (data == 'n' && data.dtype == 'n')
//		return true;
//	else
//		return false;
//}

bool var::operator>(const var& data) const
{
	/*check data type of both object and then compare the result
	return the comparison will return in true or false.*/
	if (dtype == 'i' && data.dtype == 'i')
		return (i > data.i);
	else if (dtype == 'd' && data.dtype == 'd')
		return (d > data.d);
	else if (dtype == 's' && data.dtype == 's')
		return (s > data.s);
	else if (dtype == 'i' && data.dtype == 's')
		return (convert(i) > data.s);
	else if (dtype == 's' && data.dtype == 'i')
		return (s > convert(data.i));
	else if (dtype == 'd' && data.dtype == 's')
		return (convert(d) > data.s);
	else if (dtype == 's' && data.dtype == 'd')
		return (s > convert(data.d));
	else if (dtype == 'i' && data.dtype == 'd')
		return (i > data.d);
	else if (dtype == 'd' && data.dtype == 'i')
		return (d > data.i);
	else if (dtype == 'n' && data.dtype == 'n')
		return true;
	else
		return false;
}

bool var::operator<(const var& data) const
{
	/*check data type of both object and then compare the result
	return the comparison will return in true or false.*/
	if (dtype == 'i' && data.dtype == 'i')
		return (i < data.i);
	else if (dtype == 'd' && data.dtype == 'd')
		return (d < data.d);
	else if (dtype == 's' && data.dtype == 's')
		return (s < data.s);
	else if (dtype == 'i' && data.dtype == 's')
		return (convert(i) < data.s);
	else if (dtype == 's' && data.dtype == 'i')
		return (s < convert(data.i));
	else if (dtype == 'd' && data.dtype == 's')
		return (convert(d) < data.s);
	else if (dtype == 's' && data.dtype == 'd')
		return (s < convert(data.d));
	else if (dtype == 'i' && data.dtype == 'd')
		return (i < data.d);
	else if (dtype == 'd' && data.dtype == 'i')
		return (d < data.i);
	else if (dtype == 'n' && data.dtype == 'n')
		return true;
	else
		return false;
}

bool var::operator<=(const var& data) const
{
	return (*this) < data || (*this) == data;
}
bool var::operator>=(const var& data) const
{
	return (*this) > data || (*this) == data;
}
bool var::operator!=(const var& data) const
{
	return !((*this) == data);
}

var var::operator+(const var& data) const
{
	if (dtype == 'i' && data.dtype == 'i')
	{
		return (i + data.i);
	}
	else if (dtype == 'd' && data.dtype == 'd')
	{
		return (d + data.d);
	}
	else if (dtype == 's' && data.dtype == 's')
	{
		return (s + data.s);
	}
	else if (dtype == 'i' && data.dtype == 's')
	{
		return (convert(i) + data.s);
	}
	else if (dtype == 's' && data.dtype == 'i')
	{
		return (s + convert(data.i));
	}
	else if (dtype == 'd' && data.dtype == 's')
	{
		return (convert(d) + data.s);
	}
	else if (dtype == 's' && data.dtype == 'd')
	{
		return (s + convert(data.d));
	}
	else if (dtype == 'i' && data.dtype == 'd')
	{
		return (i + data.d);
	}
	else if (dtype == 'd' && data.dtype == 'i')
	{
		return (d + data.i);
	}
	else
	{
		return var();
	}
}

var var::operator-(const var& data) const
{
	if (dtype == 'i' && data.dtype == 'i')
	{
		return (i - data.i);
	}
	else if (dtype == 'd' && data.dtype == 'd')
	{
		return (d - data.d);
	}
	else if (dtype == 'i' && data.dtype == 'd')
	{
		return (i - data.d);
	}
	else if (dtype == 'd' && data.dtype == 'i')
	{
		return (d - data.i);
	}
	else
	{
		return var();
	}
}

var var::operator*(const var& data) const
{
	if (dtype == 'i' && data.dtype == 'i')
	{
		return (i * data.i);
	}
	else if (dtype == 'd' && data.dtype == 'd')
	{
		return (d * data.d);
	}
	else if (dtype == 'i' && data.dtype == 'd')
	{
		return (i * data.d);
	}
	else if (dtype == 'd' && data.dtype == 'i')
	{
		return (d * data.i);
	}
	else
	{
		return var();
	}
}

var var::operator/(const var& data) const
{
	if (dtype == 'i' && data.dtype == 'i')
	{
		return (i / data.i);
	}
	else if (dtype == 'd' && data.dtype == 'd')
	{
		return (d / data.d);
	}
	else if (dtype == 'i' && data.dtype == 'd')
	{
		return (i / data.d);
	}
	else if (dtype == 'd' && data.dtype == 'i')
	{
		return (d / data.i);
	}
	else
	{
		return var();
	}
}

char& var::operator[](const int a)
{
	if (dtype == 's')
	{
		return s[a];
	}
	else if (dtype == 'i')
	{
		return ((convert(i))[a]);
	}
	else if (dtype == 'd')
	{
		return ((convert(d))[a]);
	}
	else
	{
		i = 0;
		return convert(i)[0];
	}
}

var& var::operator++()
{
	if (dtype == 'i')
	{
		i++;
	}
	else if (dtype == 'd')
	{
		d++;
	}
	else if (dtype == 's')
	{
		s[s.size()-1]++;
	}

	return *this;
}

var& var::operator++(int)
{
	var newVar(*this);

	if (dtype == 'i')
	{
		i++;
	}
	else if (dtype == 'd')
	{
		d++;
	}
	else if (dtype == 's')
	{
		s[s.size()-1]++;
	}

	return newVar;
}

var& var::operator--()
{
	if (dtype == 'i')
	{
		i--;
	}
	else if (dtype == 'd')
	{
		d--;
	}
	else if (dtype == 's')
	{
		s[s.size()]--;
	}

	return *this;
}

var& var::operator--(int)
{
	var newVar(*this);

	if (dtype == 'i')
	{
		i--;
	}
	else if (dtype == 'd')
	{
		d--;
	}
	else if (dtype == 's')
	{
		s[s.size()]--;
	}

	return newVar;
}

char var::type() const
{
	return this->dtype;
}

string var::toString() const
{
	if (dtype == 's')
	{
		return s;
	}
	else if (dtype == 'i')
	{
		return (convert(i));
	}
	else if (dtype == 'd')
	{
		return (convert(d));
	}
	else
	{
		return "null";
	}
}

double var::parseDouble() const
{
	if (dtype == 'i')
	{
		return i;
	}
	else if (dtype == 'd')
	{
		return d;
	}
	else if (dtype == 's')
	{
		if (whatType(s) == 'i')
		{
			return toInt(s);
		}
		else if (whatType(s) == 'd')
		{
			return toDbl(s);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int var::parseInt() const
{
	return (int)parseDouble();
}

bool var::isInt() const
{
	if (dtype == 'i')
		return true;
	else if (dtype == 's')
	{
		if (whatType(s) == 'i')
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

bool var::isNumeric() const
{
	if (dtype == 'i' || dtype == 'd')
	{
		return true;
	}
	else if (dtype == 's')
	{
		if (whatType(s) == 'i' || whatType(s) == 'd')
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

void var::convertInt()
{
	if (dtype == 'i')
		return;
	else if (dtype == 'd')
	{
		i = (int)d;
	}
	else if (dtype == 's')
	{
		i = toInt(s);
	}
	dtype = 'i';
}

void var::convertDouble()
{
	if (dtype == 'd')
		return;
	else if (dtype == 'i')
	{
		d = (double)i;
	}
	else if (dtype == 's')
	{
		d = toDbl(s);
	}
	dtype = 'd';
}

void var::convertString()
{
	if (dtype == 's')
		return;
	else if (dtype == 'd')
	{
		s = convert(d);
	}
	else if (dtype == 'i')
	{
		s = convert(i);
	}
	dtype = 's';
}

bool var::isNull() const
{
	if (dtype == 'n')
		return true;
	else
		return false;
}

var::~var()
{
	dtype = 'n';
}

void var::clear()
{
	this->~var();
}

ostream& operator<<(ostream& s, const var& a)
{
	s << a.toString();
	return s;
}

istream& operator>>(istream& s, var& a)
{
	string temp; s >> temp;
	a = temp;
	// We stored a string, now let us fix the type…
	if (a.isInt())
		a.convertInt();
	else if (a.isNumeric())
		a.convertDouble();
	return s;
}