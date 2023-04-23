#include "Fraction.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace ariel;

Fraction::Fraction(int numerator, int denominator) : // List initialization so that the variables won't have garbage values
	numerator(numerator), denominator(denominator)
{
	if (denominator == 0)
	{
		throw runtime_error("Denominator is zero. What a loser");
	}
	reduce();
}

// Fraction::operator float() const{
// 	return (float)this->numerator / (float)this->denominator;
// }


void Fraction:: reduce(){
	int gcd = get_gcd(abs(this->numerator), abs(this->denominator));
	this->numerator = numerator / gcd;
	this->denominator = denominator / gcd;

	if (this->denominator < 0)
	{
		this->numerator *= -1;
		this->denominator *= -1;
	}
}

int Fraction::get_numerator() const { return numerator; }

int Fraction::get_denominator() const { return denominator; }

int Fraction::get_gcd(int a, int b) const
{
	if (b == 0)
	{
		return a;
	}
	return get_gcd(b, a % b);
}

void Fraction::advance()
{
	this->numerator += this->denominator;
	int gcd = get_gcd(abs(this->numerator), abs(this->denominator));
	this->numerator /= gcd;
	this->denominator /= gcd;
}

void Fraction::prev()
{
	this->numerator -= this->denominator;
	int gcd = get_gcd(abs(this->numerator), abs(this->denominator));
	this->numerator /= gcd;
	this->denominator /= gcd;
}

void Fraction::floatToFraction(float f){
	if(f == 0){
		this->numerator = 0;
		this->denominator = 1;
	}
	else{
		this->numerator = (int)(f * 1000);
		this->denominator = 1000;
		reduce();
	}
}


// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(Fraction const &obj) const
{ // a+b
	Fraction result(*this);
	result.numerator = this->numerator * obj.denominator + obj.numerator * this->denominator;
	result.denominator = this->denominator * obj.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator+(float const &obj) const
{ // a+7
	Fraction result(0,1);
	float sub = (float)this->numerator / (float)this->denominator + obj;
	result.floatToFraction(sub);
    return result;
}

const Fraction operator+(const float &f, const Fraction &frac)
{ // 7+a - friend method
	return frac + f;
}

// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(Fraction const &obj) const
{
	Fraction result(*this);
    result.numerator = this->numerator * obj.denominator - obj.numerator * this->denominator;
	result.denominator = this->denominator * obj.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator-(float const &obj) const
{
	Fraction result(0,1);
	float sub = (float)this->numerator / (float)this->denominator - obj;
	result.floatToFraction(sub);
    return result;
}

const Fraction operator-(const float &f, const Fraction &frac)
{
	return frac - f;
}

//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(Fraction const &obj) const
{
	int numer = this->numerator * obj.numerator;
    int denom = this->denominator * obj.denominator;
    Fraction result(numer, denom);
    result.reduce();
    return result;
}

Fraction Fraction::operator*(float const &obj) const
{
	Fraction result(0,1);
	float sub = (float)this->numerator / (float)this->denominator * obj;
	result.floatToFraction(sub);
    return result;
}

const Fraction operator*(const float &f, const Fraction &frac)
{
	return frac * f;
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(Fraction const &obj) const
{
	Fraction result(*this);
	result.numerator = this->numerator * obj.denominator;
	result.denominator = this->denominator * obj.numerator;
	result.reduce();
	return result;
}

Fraction Fraction::operator/(float const &f) const
{
	if (f == 0)
	{
		throw runtime_error("Division by zero");
	}
	Fraction result(0,1);
	float div = ((float)this->numerator / (float)this->denominator) / f;
	result.floatToFraction(div);
    return result;
}


const Fraction operator/(const float &f, const Fraction &frac)
{
	if(frac == 0){
		throw runtime_error("Division by zero");
	}
	Fraction result(frac);
	float div = ((float) frac.numerator / (float) frac.denominator) / f;
	result.floatToFraction(div);
	return result;
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(Fraction const &obj) const
{
	return (this->numerator == obj.numerator) && (this->denominator == obj.denominator);
}

bool Fraction::operator==(float const &obj) const
{
	float f = (float)this->numerator / (float)this->denominator;
	return f == obj;
}

bool operator==(const float &f, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ == f;
}

// All comparison operations (>,<,>=,<=)
bool Fraction::operator>(Fraction const &obj) const
{
	Fraction sub = *this - obj;
	float sub_ = (float)sub.numerator / (float)sub.denominator;
	if (sub_ > 0)
	{
		return true;
	}
	return false;
}

bool Fraction::operator>(float const &f) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac > f;
}

bool operator>(const float &f, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ > f;}


bool Fraction::operator<(Fraction const &obj) const
{
	Fraction sub = *this - obj;
	float sub_ = (float)sub.numerator / (float)sub.denominator;
	if (sub_ < 0)
	{
		return true;
	}
	return false;
}

bool Fraction::operator<(float const &f) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac < f;
}

bool operator<(const float &f, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ < f;
}


bool Fraction::operator>=(Fraction const &obj) const
{
	Fraction sub = *this - obj;
	float sub_ = (float)sub.numerator / (float)sub.denominator;
	if (sub_ >= 0)
	{
		return true;
	}
	return false;
}

bool Fraction::operator>=(float const &f) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac >= f;
}

bool operator>=(const float &f, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ >= f;
}


bool Fraction::operator<=(Fraction const &obj) const
{
	Fraction sub = *this - obj;
	float sub_ = (float)sub.numerator / (float)sub.denominator;
	if (sub_ <= 0)
	{
		return true;
	}
	return false;
}

bool Fraction::operator<=(float const &f) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac <= f;
	
}

bool operator<=(const float &f, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ <= f;
}


// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
Fraction &Fraction::operator++()
{
	advance();
	return *this;

} // prefix

const Fraction Fraction::operator++(int)
{
	Fraction res(*this);
	advance();
	return res;

} // postfix

Fraction &Fraction::operator--()
{
	prev();
	return *this;

} // prefix

const Fraction Fraction::operator--(int)
{
	Fraction res(*this);
	prev();
	return res;

} // postfix

// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
ostream &operator<<(ostream &out, const Fraction &frac)
{
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

// The >> operator to read a fraction from an input stream by taking two integers as input.
istream &operator>>(istream &in, Fraction &frac)
{
	int numerator, denominator;
	in >> numerator >> denominator;
	frac = Fraction(numerator, denominator);
	return in;
}