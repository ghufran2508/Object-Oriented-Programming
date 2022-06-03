#include<iostream>
#include"MixedFraction.h"

using namespace std;

MixedFraction::MixedFraction(int a_integer, int a_numerator, int a_denominator)
{
	this->integer = a_integer;
	if (a_numerator >= 0)
	{
		this->numerator = a_numerator;
	}
	else
	{
		this->numerator = 0;
	}
	if (a_denominator > 0)
	{
		this->denominator = a_denominator;
	}
	else
	{
		this->denominator = 1;
	}
}

MixedFraction::MixedFraction(int a_integer):numerator(0), denominator(1)
{
	this->integer = a_integer;
}

MixedFraction::MixedFraction(MixedFraction& a_mFrac)
{
	this->integer = a_mFrac.integer;
	this->numerator = a_mFrac.numerator;
	this->denominator = a_mFrac.denominator;
}

MixedFraction::~MixedFraction()
{
	cout << "\n[+]***Object is Destroyed***[+]" << endl;
}

void MixedFraction::setIntegralPart(int a_integer)
{
	this->integer = a_integer;
}

void MixedFraction::setNumerator(int a_numerator)
{
	this->numerator = a_numerator;
}

bool MixedFraction::setDenominator(int a_denominator)
{
	if (a_denominator != 0)
	{
		this->denominator = a_denominator;
		return true;
	}
	else
		return false;
}

int MixedFraction::getIntegralPart() const
{
	return this->integer;
}
int MixedFraction::getDenominator() const
{
	return this->denominator;
}
int MixedFraction::getNumerator()const
{
	return this->numerator;
}

double MixedFraction::evaluate()
{
	return (static_cast<double>((denominator * integer) + numerator)/denominator);
}

void MixedFraction::display()
{
	cout << integer << " " << numerator << "/" << denominator << endl;
}

MixedFraction MixedFraction::operator+(const MixedFraction& m_frac)
{
	MixedFraction new_mfrac;

	int numrat_first = (this->denominator*this->integer)+this->numerator;
	
	int numrat_second = (m_frac.getDenominator()*m_frac.getIntegralPart())+m_frac.getNumerator();

	new_mfrac.setNumerator((numrat_first * m_frac.getDenominator()) + (getDenominator() * numrat_second));
	new_mfrac.setDenominator(this->denominator * m_frac.getDenominator());

	return new_mfrac;
}

MixedFraction MixedFraction::operator-(const MixedFraction& m_frac)
{
	MixedFraction new_mfrac;

	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	new_mfrac.setNumerator((numrat_first * m_frac.getDenominator()) - (getDenominator() * numrat_second));
	new_mfrac.setDenominator(this->denominator * m_frac.getDenominator());

	return new_mfrac;
}

MixedFraction MixedFraction::operator*(const MixedFraction& m_frac)
{
	MixedFraction new_mfrac;

	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	new_mfrac.setNumerator(numrat_first*numrat_second);
	new_mfrac.setDenominator(denominator*m_frac.getDenominator());

	return new_mfrac;
}

MixedFraction MixedFraction::operator/(const MixedFraction& m_frac)
{
	MixedFraction new_mfrac;

	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	new_mfrac.setNumerator(numrat_first * m_frac.getDenominator());
	new_mfrac.setDenominator(denominator * numrat_second);

	return new_mfrac;
}

bool MixedFraction::operator==(const MixedFraction& m_frac)
{
	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	if ((numrat_first == numrat_second) && (denominator == m_frac.denominator))
		return true;
	else
		return false;
}

bool MixedFraction::operator<(const MixedFraction& m_frac)
{
	double first = static_cast<double>(denominator * integer + numerator)/denominator;
	cout << first << endl;
	double second = static_cast<double>(m_frac.getDenominator() * m_frac.getIntegralPart() + m_frac.getNumerator()) / m_frac.getDenominator();
	cout << second << endl;

	if (first < second)
		return true;
	else
		return false;
}

MixedFraction MixedFraction::operator-()
{
	MixedFraction new_frac(-1 * integer, numerator, denominator);

	return new_frac;
}

MixedFraction MixedFraction::operator++()
{
	this->integer++;
	return *this;
}

MixedFraction MixedFraction::operator++(int)
{
	MixedFraction new_frac(integer, numerator, denominator);
	this->integer++;
	return new_frac;
}

MixedFraction MixedFraction::operator--()
{
	this->integer--;
	return *this;
}

MixedFraction MixedFraction::operator--(int)
{
	MixedFraction new_frac(integer, numerator, denominator);
	this->integer--;
	return new_frac;
}

MixedFraction& MixedFraction::operator+=(const MixedFraction& m_frac)
{
	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	this->integer = 0;
	this->numerator = ((numrat_first* m_frac.getDenominator()) + (getDenominator() * numrat_second));
	this->denominator = (this->denominator* m_frac.getDenominator());

	return *this;
}

MixedFraction& MixedFraction::operator/=(const MixedFraction& m_frac)
{
	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	this->integer = 0;
	this->numerator = (numrat_first * m_frac.getDenominator());
	this->denominator = (denominator * numrat_second);

	return *this;
}

MixedFraction& MixedFraction::operator-=(const MixedFraction& m_frac)
{
	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	this->integer = 0;
	this->numerator = ((numrat_first * m_frac.getDenominator()) - (getDenominator() * numrat_second));
	this->denominator = (this->denominator * m_frac.getDenominator());

	return *this;
}

MixedFraction& MixedFraction::operator*=(const MixedFraction& m_frac)
{
	int numrat_first = (this->denominator * this->integer) + this->numerator;

	int numrat_second = (m_frac.getDenominator() * m_frac.getIntegralPart()) + m_frac.getNumerator();

	this->integer = 0;
	this->numerator = (numrat_first * numrat_second);
	this->denominator = (denominator * m_frac.getDenominator());

	return *this;
}