#include "Fraction.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;
using namespace ariel;

Fraction::Fraction(int numerator, int denominator) : // List initialization so that the variables won't have garbage values
	numerator(numerator), denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator is zero. What a loser");
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

float Fraction::roundToThree(){
	float res = (float)(this->numerator) / (float)(this->denominator);
	res = res * 1000;
	int bfr = res;
	int aftr = (int)(res * 10 - (int)(res)*10);
	if (aftr > 5)
	{
		bfr += 1;
	}
	res = (float)(bfr) / 1000;
	return res;
}

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(Fraction const &obj) const
{ 
	int64_t numer1 = static_cast<int64_t>(this->numerator * obj.denominator);
	int64_t numer2 = static_cast<int64_t>(obj.numerator * this->denominator);
	int64_t denom = static_cast<int64_t>(this->denominator * obj.denominator);
	int64_t numer = numer1 + numer2;

	if (numer > std::numeric_limits<int>::max() ||
		numer < std::numeric_limits<int>::min() ||
		denom > std::numeric_limits<int>::max() ||
		denom < std::numeric_limits<int>::min()) {
        
		throw std::overflow_error("Overflow error");
    }

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
	int64_t numer1 = static_cast<int64_t>(this->numerator) * static_cast<int64_t>(obj.denominator);
	int64_t numer2 = static_cast<int64_t>(obj.numerator) * static_cast<int64_t>(this->denominator);
	int64_t denom = static_cast<int64_t>(this->denominator) * static_cast<int64_t>(obj.denominator);
	int64_t numer = numer1 - numer2;

	if (numer > std::numeric_limits<int>::max() ||
		numer < std::numeric_limits<int>::min() ||
		denom > std::numeric_limits<int>::max() ||
		denom < std::numeric_limits<int>::min()) {
        
		throw std::overflow_error("Overflow error");
    }

	Fraction result(*this);
    result.numerator = this->numerator * obj.denominator - obj.numerator * this->denominator;
	result.denominator = this->denominator * obj.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::operator-(float const &obj) const
{
	Fraction other(obj);
	Fraction result = *this - other;
    return result;
}

const Fraction operator-(const float &num, const Fraction &frac)
{
	Fraction other(num);
	Fraction result = other - frac;
	float res = result.roundToThree();
	Fraction fnl(res);
	return fnl;
}

//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(Fraction const &obj) const
{
	int64_t numer = static_cast<int64_t>(this->numerator) * static_cast<int64_t>(obj.numerator);
	int64_t denom = static_cast<int64_t>(this->denominator) * static_cast<int64_t>(obj.denominator);

	if (numer > std::numeric_limits<int>::max() ||
		numer < std::numeric_limits<int>::min() ||
		denom > std::numeric_limits<int>::max() ||
		denom < std::numeric_limits<int>::min()) {
        
		throw std::overflow_error("Overflow error");
    }

	int nmr = static_cast<int>(numer);
    int dnm = static_cast<int>(denom);
    Fraction result(nmr, dnm);
    result.reduce();
    return result;
}

Fraction Fraction::operator*(float const &num) const
{
	Fraction result(*this);
	if(num == 1){
		return result;
	}

	Fraction other(num);
	result = result * other;
    return result;
}

const Fraction operator*(const float &num, const Fraction &frac)
{
	return frac * num;
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(Fraction const &obj) const
{
	if (obj == 0)
	{
		throw std::runtime_error("Division by zero");
	}

	Fraction inverse(obj.denominator, obj.numerator);
	Fraction result = *this * inverse;

	return result;
}

Fraction Fraction::operator/(float const &num) const
{
	if (num == 0)
	{
		throw runtime_error("Division by zero");
	}

	Fraction other(num);

	if (other == 0)
	{
		throw runtime_error("Division by zero");
	}

	Fraction result = *this / other;
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