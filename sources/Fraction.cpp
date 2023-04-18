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

Fraction::Fraction(int numerator = 0, int denominator = 1) {
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