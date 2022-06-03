#pragma once
class MixedFraction
{
private:
	int integer; // Integral part of the Mixed fraction.
	int numerator; // Numerator of the fractional part.
	int denominator; // Denominator of the fractional part. This must be non-zero

public:
	MixedFraction(int a_integer, int a_nmrator, int a_dnmnator); // Initialize data members with parameter values. A mixed number can be negative or positive. If the mixed number is to be negative, only the integer part can be negative, not numerator or denominator.
	MixedFraction(int a_integer = 0); // Constructor with only integer part, set fractional part to zero.
	MixedFraction(MixedFraction& a_mFrac); // copy constructor.
	~MixedFraction(); // Destructor should display the message “Object is destroyed”.

	void setIntegralPart(int a_intgr);
	bool setDenominator(int a_dnmnator);
	void setNumerator(int a_nmrator);
	int getIntegralPart() const;
	int getDenominator() const;
	int getNumerator()const;

	double evaluate(); // should return the decimal equivalent of the mixed number.
	void display(); // should display the fraction in proper format i.e. 3 2/5.

	MixedFraction  operator+(const MixedFraction&); // overload binary + operator.
	MixedFraction  operator-(const MixedFraction&); // overload binary – operator.
	MixedFraction  operator*(const MixedFraction&); // overload binary * operator.
	MixedFraction  operator/(const MixedFraction&); // overload binary / operator.

	bool operator==(const MixedFraction&); // overload relational == operator
	bool operator<(const MixedFraction&); // overload relational != operator.
	MixedFraction  operator-(); // overload unary – operator.
	MixedFraction  operator++(); // overload pre-increment operator.
	MixedFraction  operator++(int); // overload post-increment operator.
	MixedFraction  operator--(); // overload pre-increment operator.
	MixedFraction  operator--(int); // overload post-increment operator.
	MixedFraction& operator+=(const MixedFraction&); // overload combined operator +=
	MixedFraction& operator/=(const MixedFraction&); // overload combined operator /=
	MixedFraction& operator-=(const MixedFraction&); // overload combined operator -=
	MixedFraction& operator*=(const MixedFraction&); // overload combined operator *=
};