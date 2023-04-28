#ifndef FRACTION_HPP
#define FRACTION_HPP

#include<iostream>
#include <stdexcept>

namespace ariel{}

class Fraction {

private:
	int numerator;
	int denominator;
	void advance();
	void prev();
	void reduce();
	void floatToFraction(float num);

public:

	Fraction(int numerator, int denominator);
	Fraction(float num);
	Fraction();

	int getNumerator() const;

	int getDenominator() const;

	int get_gcd(int num_a, int num_b) const;

	// The + operator to add two fractions and return their sum as another fraction in reduced form.
	Fraction operator+(Fraction const& obj) const;
	Fraction operator+(float const& obj) const;
	friend const Fraction operator+(const float& num, const Fraction& frac); //const?

	// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
	Fraction operator-(Fraction const& obj) const;
	Fraction operator-(float const& obj) const;
	friend const Fraction operator-(const float& num, const Fraction& frac);


	//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
	Fraction operator*(const Fraction& obj) const;
	Fraction operator*(const float& obj) const;
	friend const Fraction operator*(const float& num, const Fraction& frac);

	// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
	Fraction operator/(Fraction const& obj) const;
	Fraction operator/(float const& obj) const;
	friend const Fraction operator/(const float& num, const Fraction& frac);

	// The == operator to compare two fractions for equality and return true or false.
	bool operator==(Fraction const& obj) const;
	bool operator==(float const& obj) const;
	friend bool operator==(const float& num, const Fraction& frac);

	// All comparison operations (>,<,>=,<=)
	bool operator>(Fraction const& obj) const;
	bool operator>(float const& obj) const;
	friend bool operator>(const float& num, const Fraction& frac);

	bool operator<(Fraction const& obj) const;
	bool operator<(float const& obj) const;
	friend bool operator<(const float& num, const Fraction& frac);

	bool operator>=(Fraction const& obj) const;
	bool operator>=(float const& obj) const;
	friend bool operator>=(const float& num, const Fraction& frac);

	bool operator<=(Fraction const& obj) const;
	bool operator<=(float const& obj) const;
	friend bool operator<=(const float& num, const Fraction& frac);


	// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
	Fraction &operator++();  //prefix
	const Fraction operator++(int) ;  //postfix

	Fraction &operator--();  //prefix
	const Fraction operator--(int);  //postfix

	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	friend std::ostream &operator<<(std::ostream &output, const Fraction &frac);

	// The >> operator to read a fraction from an input stream by taking two integers as input. 
	friend std::istream &operator>>(std::istream &input, Fraction &frac);

};
#endif
