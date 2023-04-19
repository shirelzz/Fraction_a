#ifndef FRACTION_HPP
#define FRACTION_HPP

#include<iostream>
#include <stdexcept>
using namespace std;
namespace ariel{}

class Fraction {

private:
	int numerator;
	int denominator;

public:

	Fraction(int numerator , int denominator );

	int get_numerator() const;

	int get_denominator() const;

	friend ostream& operator<<(ostream&, const Fraction&);

	int get_gcd(int a, int b) const;

	// The + operator to add two fractions and return their sum as another fraction in reduced form.
	Fraction operator+(Fraction const& obj) const;
	Fraction operator+(float const& obj) const;

	// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
	Fraction operator-(Fraction const& obj) const;
	Fraction operator-(float const& obj) const;

	//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
	Fraction operator*(Fraction const& obj) const;
	Fraction operator*(float const& obj) const;

	// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
	Fraction operator/(Fraction const& obj) const;
	Fraction operator/(float const& obj) const;

	// The == operator to compare two fractions for equality and return true or false.
	bool operator==(Fraction const& obj) const;
	bool operator==(float const& obj) const;

	// All comparison operations (>,<,>=,<=)
	bool operator>(Fraction const& obj) const;
	bool operator>(float const& obj) const;

	bool operator<(Fraction const& obj) const;
	bool operator<(float const& obj) const;

	bool operator>=(Fraction const& obj) const;
	bool operator>=(float const& obj) const;

	bool operator<=(Fraction const& obj) const;
	bool operator<=(float const& obj) const;

	// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
	Fraction operator++() const;

	Fraction operator--() const;

	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	Fraction operator<<(Fraction const& obj) const;
	Fraction operator<<(float const& obj) const;

	// The >> operator to read a fraction from an input stream by taking two integers as input. 
	Fraction operator>>(Fraction const& obj) const;
	Fraction operator>>(float const& obj) const;


};
#endif
