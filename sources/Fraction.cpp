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

// Fraction::Fraction(float num){
// 	if (num == 0){
// 		this->numerator = (int)(num * 1000);
// 		this->denominator = 1000;
// 	}
// 	else{
// 		this->numerator = (int)(num * 1000);
// 		this->denominator = 1000;
// 		reduce();
// 	}
// }

// Fraction::Fraction(int num){
// 	this->numerator = num;
// 	this->denominator = 1;
// }

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

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(Fraction const &obj) const
{ // a+b
	Fraction result(*this);
	result.numerator = this->numerator + obj.numerator;
	result.denominator = this->denominator + obj.denominator;
	result.reduce();
	return result;
}

Fraction Fraction::operator+(float const &obj) const
{ // a+7
	float result = (float)(this->numerator / this->denominator) + obj;
    return Fraction(1,1);
}

// Fraction Fraction::operator+(const int &obj) const{
// 	Fraction result(*this);
// 	result.numerator = this->numerator + obj * this->denominator;
// 	result.reduce();
// 	return result;
// }


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
	float result = (float)(this->numerator / this->denominator) - obj;
    return Fraction(1,1);
}

// Fraction Fraction::operator-(int const &obj) const{
//     Fraction result(*this);
//     result.numerator -= obj * result.denominator;
//     result.reduce();
//     return result;
// }

const Fraction operator-(const float &f, const Fraction &frac)
{
	return Fraction(1, 1);
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
	float result = (float)(this->numerator / this->denominator) * obj;
    return Fraction(1,1);
}

Fraction Fraction::operator*(const int &obj) const{
	Fraction result(*this);
    result.numerator = this->numerator * obj;
    result.reduce();
    return result;
}

const Fraction operator*(const float &f, const Fraction &frac)
{
	return frac * f;
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(Fraction const &obj) const
{
	Fraction a(5, 3);
	return a;
}

Fraction Fraction::operator/(float const &obj) const
{
	float result = (float)(this->numerator / this->denominator) - obj;
	return Fraction(1,1);
}

Fraction Fraction::operator/(const int &obj) const{
	if (obj == 0)
	{
		throw runtime_error("Division by zero");
	}
	
	Fraction result(*this);
    result.denominator = this->denominator * obj;
    result.reduce();
    return result;
}


const Fraction operator/(const float &f, const Fraction &frac)
{
	return Fraction(1, 1);
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(Fraction const &obj) const
{
	return (this->numerator == obj.denominator) && (this->denominator == obj.denominator);
}

bool Fraction::operator==(float const &obj) const
{
	float f = this->numerator / this->denominator;
	return f == obj;
}

bool operator==(const float &f, const Fraction &frac)
{
	float frac_ = frac.numerator / frac.denominator;
	return frac_ == f;
}

// All comparison operations (>,<,>=,<=)
bool Fraction::operator>(Fraction const &obj) const
{
	bool a;
	if (*this - obj > 0)
	{
		a = true;
	}

	return a;
}

bool Fraction::operator>(float const &obj) const
{
	float frac = this->numerator / this->denominator;
	return frac > obj;
}

bool operator>(const float &f, const Fraction &frac)
{
	float frac_ = frac.numerator / frac.denominator;
	return frac_ > f;}


bool Fraction::operator<(Fraction const &obj) const
{
	bool a;
	if ((*this - obj) < 0)
	{
		a = true;
	}
	return a;
}

bool Fraction::operator<(float const &obj) const
{
	float frac = this->numerator / this->denominator;
	return frac < obj;
}

bool operator<(const float &f, const Fraction &frac)
{
	float frac_ = frac.numerator / frac.denominator;
	return frac_ < f;
}


bool Fraction::operator>=(Fraction const &obj) const
{
	bool a;
	if ((*this - obj) >= 0)
	{
		a = true;
	}

	return a;
}

bool Fraction::operator>=(float const &obj) const
{
	float frac = this->numerator / this->denominator;
	return frac >= obj;
}

bool operator>=(const float &f, const Fraction &frac)
{
	float frac_ = frac.numerator / frac.denominator;
	return frac_ >= f;
}


bool Fraction::operator<=(Fraction const &obj) const
{
	bool a;
	if ((*this - obj) <= 0)
	{
		a = true;
	}

	return a;
}

bool Fraction::operator<=(float const &obj) const
{
	float frac = this->numerator / this->denominator;
	return frac <= obj;
	
}

bool operator<=(const float &f, const Fraction &frac)
{
	float frac_ = frac.numerator / frac.denominator;
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
	// char c;
	// in >> frac.get_numerator() >> c >> frac.get_denominator();
	// return in;

	int numerator, denominator;
	in >> numerator >> denominator;
	frac = Fraction(numerator, denominator);
	return in;
}