#include "Fraction.hpp"
#include <sstream>
#include<iostream>
#include <stdexcept>

using namespace std;

ostream& operator << (ostream& out, const Fraction& frac)
{
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

Fraction::Fraction(int numerator , int denominator) {

	if (denominator == 0) {
		throw runtime_error("Denominator cannot be zero.");
	}

	int gcd = get_gcd(abs(numerator), abs(denominator));
	this->numerator = numerator / gcd;
	this->denominator = denominator / gcd;

	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}
}
int Fraction::get_numerator() const { return numerator; }

int Fraction::get_denominator() const { return denominator; }


int Fraction::get_gcd(int a, int b) const {
	if (b == 0) {
		return a;
	}
	return get_gcd(b, a % b);
}

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction:: operator+(Fraction const& obj) const{
	Fraction a(5,3);
	return a;
}

Fraction Fraction:: operator+(float const& obj) const{
	Fraction a(5,3);
	return a;
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
		return a;}

	Fraction Fraction::  operator/(float const& obj) const{
		Fraction a(5,3);
		return a;
	}

	// The == operator to compare two fractions for equality and return true or false.
	bool Fraction::  operator==(Fraction const& obj) const{
		bool a = true;
		return a;	
	}

	bool Fraction::  operator==(float const& obj) const{
		bool a = true;
		return a;
	}


	// All comparison operations (>,<,>=,<=)
	bool Fraction::  operator>(Fraction const& obj) const{
		bool a = true;
		return a;
	}
	bool Fraction::  operator>(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator<(Fraction const& obj) const{
		bool a = true;
		return a;
	}
	bool Fraction::  operator<(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator>=(Fraction const& obj) const{
		bool a = true;
		return a;
	}
	bool Fraction::  operator>=(float const& obj) const{
		bool a = true;
		return a;
	}

	bool Fraction::  operator<=(Fraction const& obj) const{
		bool a = true;
		return a;
	}
	bool Fraction::  operator<=(float const& obj) const{
		bool a = true;
		return a;
	}

	// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
	Fraction Fraction::  operator++() const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator--() const{
		Fraction a(5,3);
		return a;
	}

	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	Fraction Fraction::  operator<<(Fraction const& obj) const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator<<(float const& obj) const{
		Fraction a(5,3);
		return a;
	}

	// The >> operator to read a fraction from an input stream by taking two integers as input. 
	Fraction Fraction::  operator>>(Fraction const& obj) const{
		Fraction a(5,3);
		return a;
	}

	Fraction Fraction::  operator>>(float const& obj) const{
		Fraction a(5,3);
		return a;
	}