#include "Fraction.hpp"
#include <sstream>
#include<iostream>
#include <stdexcept>

using namespace std;

Fraction::Fraction(int numerator, int denominator):
//List initialization so that the variables won't have garbage values
numerator(numerator), denominator(denominator)
{
	if (denominator == 0) {
		throw runtime_error("Denominator is zero. What a loser");
	}

	int gcd = get_gcd(abs(numerator), abs(denominator));
	this->numerator = numerator / gcd;
	this->denominator = denominator / gcd;

	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}
	
}

// Fraction::Fraction(int numerator , int denominator) {

// 	if (denominator == 0) {
// 		throw runtime_error("Denominator cannot be zero.");
// 	}

// 	int gcd = get_gcd(abs(numerator), abs(denominator));
// 	this->numerator = numerator / gcd;
// 	this->denominator = denominator / gcd;

// 	if (this->denominator < 0) {
// 		this->numerator *= -1;
// 		this->denominator *= -1;
// 	}
// }

int Fraction::get_numerator() const { return numerator; }

int Fraction::get_denominator() const { return denominator; }


int Fraction::get_gcd(int a, int b) const {
	if (b == 0) {
		return a;
	}
	return get_gcd(b, a % b);
}

float Fraction::fractionToFloat() const{
	return (float) this->numerator / (float) this->denominator;
}

// Fraction Fraction::floatToFraction(float f){

// }

void Fraction:: advance(){
	this->numerator += this->denominator;
	int gcd = get_gcd(abs(this->numerator), abs(this->denominator));
	this->numerator /= gcd;
	this->denominator /= gcd;
}

void Fraction::prev(){
	this->numerator -= this->denominator;
	int gcd = get_gcd(abs(this->numerator), abs(this->denominator));
	this->numerator /= gcd;
	this->denominator /= gcd;
}


// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction:: operator+(Fraction const& obj) const{ // a+b
	Fraction a(5,3);
	return a;
}

Fraction Fraction:: operator+(float const& obj) const{ // a+7
	Fraction a(5,3);
	return a;
}

const Fraction operator+(const float& f, const Fraction& frac){ //7+a - friend method
	return frac + f;
}


// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
	Fraction Fraction::  operator-(Fraction const& obj) const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator-(float const& obj) const{
		Fraction a(5,3);
		return a;
	}

	//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
	Fraction Fraction::  operator*(Fraction const& obj) const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator*(float const& obj) const{
		Fraction a(5,3);
		return a;
	}

	// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
	Fraction Fraction::  operator/(Fraction const& obj) const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator/(float const& obj) const{
		Fraction a(5,3);
		return a;
	}

	// The == operator to compare two fractions for equality and return true or false.
	bool Fraction::  operator==(Fraction const& obj) const{
		return (this->numerator == obj.denominator) && (this->denominator == obj.denominator);	
	}

	bool Fraction::  operator==(float const &obj) const{
		bool a = true;
		return a;
	}


	// All comparison operations (>,<,>=,<=)
	bool Fraction::  operator>(Fraction const &obj) const{
		bool a;
		if (*this - obj > 0)
		{
			a = true;
		}
		
		return a;
	}

	bool Fraction::  operator>(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator<(Fraction const& obj) const{
		bool a;
		if (*this - obj < 0)
		{
			a = true;
		}
		
		return a;
	}
	bool Fraction::  operator<(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator>=(Fraction const& obj) const{
		bool a;
		if (*this - obj >= 0)
		{
			a = true;
		}
		
		return a;
	}

	bool Fraction::  operator>=(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator<=(Fraction const& obj) const{
		bool a;
		if (*this - obj <= 0)
		{
			a = true;
		}
		
		return a;
	}

	bool Fraction::  operator<=(float const& obj) const{
		bool a = true;
		return a;
	}

	// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
	Fraction &Fraction::operator++(){
		advance();
		return *this;

	}  //prefix

	const Fraction Fraction:: operator++(int){
		Fraction res(*this);
		advance();
		return res;

	} //postfix


	Fraction &Fraction::operator--(){
		prev();
		return *this;

	}  //prefix

	const Fraction Fraction:: operator--(int){
		Fraction res(*this);
		prev();
		return res;

	} //postfix

	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	ostream& operator << (ostream& out, const Fraction& frac)
	{
		out << frac.numerator << "/" << frac.denominator;
		return out;
	}

	// The >> operator to read a fraction from an input stream by taking two integers as input. 
	istream& operator>>(istream& in, Fraction& frac)
	{
		// char c;
		// in >> frac.get_numerator() >> c >> frac.get_denominator();
    	// return in;

		int numerator, denominator;
		in >> numerator >> denominator;
		frac = Fraction(numerator, denominator);
		return in;
	}