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

Fraction::Fraction(float num){
	if(num == 0){
		this->numerator = 0;
		this->denominator = 1;
	}
	else{
		this->numerator = (int)(num * 1000);
		this->denominator = 1000;
		reduce();
	}
}

Fraction::Fraction(){
	this->numerator = 0;
	this->denominator = 1;
}

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

int Fraction::getNumerator() const { return this->numerator; }

int Fraction::getDenominator() const { return this->denominator; }

int Fraction::get_gcd(int num_a, int num_b) const
{
	if (num_b == 0)
	{
		return num_a;
	}
	return get_gcd(num_b, num_a % num_b);
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

void Fraction::floatToFraction(float num){
	if(num == 0){
		this->numerator = 0;
		this->denominator = 1;
	}
	else{
		this->numerator = (int)(num * 1000);
		this->denominator = 1000;
		reduce();
	}
}


// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(Fraction const &obj) const
{ 
	Fraction result(*this);
	result.numerator = this->numerator * obj.denominator + obj.numerator * this->denominator;
	result.denominator = this->denominator * obj.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator+(float const &num) const
{ 
	Fraction result(0,1);
	float add = (float)this->numerator / (float)this->denominator + num;
	result.floatToFraction(add);
    return result;
}

const Fraction operator+(const float &num, const Fraction &frac)
{ 
	return frac + num;
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
	Fraction result;
	// float sub = (float)this->numerator / (float)this->denominator - obj;
	// result.floatToFraction(sub);

	Fraction other(obj);
	result = *this - other;
	
    return result;
}

const Fraction operator-(const float &num, const Fraction &frac)
{
	Fraction result = frac - num;
	result.numerator = (-1) * result.numerator;
	return result;
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

Fraction Fraction::operator*(float const &num) const
{
	Fraction result(*this);
	if(num == 1){
		return result;
	}
	float mul = (float)this->numerator * num / (float)this->denominator;
	// float sub = (float)this->numerator / (float)this->denominator * f;
	result.floatToFraction(mul);
    return result;
}

const Fraction operator*(const float &num, const Fraction &frac)
{
	return frac * num;
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

Fraction Fraction::operator/(float const &num) const
{
	if (num == 0)
	{
		throw runtime_error("Division by zero");
	}
	Fraction result;
	// float div = ((float)this->numerator / (float)this->denominator) / num;
	// result.floatToFraction(div);

	Fraction other(num);
	if (other == 0)
	{
		throw runtime_error("Division by zero");
	}
	result = *this / other;
    return result;
}


const Fraction operator/(const float &num, const Fraction &frac)
{
	if(frac == 0){
		throw runtime_error("Division by zero");
	}
	
	Fraction result(frac);
	int temp = result.numerator;
	result.numerator = result.denominator;
	result.denominator = temp;
	return result * num;
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(Fraction const &obj) const
{
	return (this->numerator == obj.numerator) && (this->denominator == obj.denominator);
}

bool Fraction::operator==(float const &obj) const
{
	float num = (float)this->numerator / (float)this->denominator;
	return num == obj;
}

bool operator==(const float &num, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return frac_ == num;
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

bool Fraction::operator>(float const &num) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac > num;
}

bool operator>(const float &num, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return num > frac_;}


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

bool Fraction::operator<(float const &num) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac < num;
}

bool operator<(const float &num, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return num < frac_;
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

bool Fraction::operator>=(float const &num) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac >= num;
}

bool operator>=(const float &num, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return num >= frac_;
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

bool Fraction::operator<=(float const &num) const
{
	float frac = (float)this->numerator / (float)this->denominator;
	return frac <= num;
	
}

bool operator<=(const float &num, const Fraction &frac)
{
	float frac_ = (float)frac.numerator / (float)frac.denominator;
	return num <= frac_;
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
ostream &operator<<(ostream &output, const Fraction &frac)
{
	output << frac.numerator << "/" << frac.denominator;
	return output;
}

// The >> operator to read a fraction from an input stream by taking two integers as input.
istream &operator>>(istream &input, Fraction &frac)
{
	int numerator, denominator;
	input >> numerator >> denominator;

	if (input.fail())
	{
		throw std::runtime_error("You need to insert 2 integers.");
	}
	
	frac = Fraction(numerator, denominator);
	return input;
}