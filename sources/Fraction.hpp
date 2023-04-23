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
	void floatToFraction(float f);

public:

	Fraction(int numerator, int denominator);
	// Fraction(float num);
	// Fraction(int num);

	int get_numerator() const;

	int get_denominator() const;

	// operator float() const;

	int get_gcd(int a, int b) const;

	// The + operator to add two fractions and return their sum as another fraction in reduced form.
	Fraction operator+(Fraction const& obj) const;
	Fraction operator+(float const& obj) const;
	// Fraction operator+(int const& obj) const;
	friend const Fraction operator+(const float& f, const Fraction& frac); //const?

	// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
	Fraction operator-(Fraction const& obj) const;
	Fraction operator-(float const& obj) const;
	// Fraction operator-(int const& obj) const;
	friend const Fraction operator-(const float& f, const Fraction& frac);


	//* The * operator to multiply two fractions and return their product as another fraction in reduced form.
	Fraction operator*(const Fraction& obj) const;
	Fraction operator*(const float& obj) const;
	// Fraction operator*(int const& obj) const;
	friend const Fraction operator*(const float& f, const Fraction& frac);

	// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
	Fraction operator/(Fraction const& obj) const;
	Fraction operator/(float const& obj) const;
	// Fraction operator/(int const& obj) const;
	friend const Fraction operator/(const float& f, const Fraction& frac);

	// The == operator to compare two fractions for equality and return true or false.
	bool operator==(Fraction const& obj) const;
	bool operator==(float const& obj) const;
	friend bool operator==(const float& f, const Fraction& frac);
	// friend bool operator==(const Fraction& frac1, const Fraction& frac2);

	// All comparison operations (>,<,>=,<=)
	bool operator>(Fraction const& obj) const;
	bool operator>(float const& obj) const;
	friend bool operator>(const float& f, const Fraction& frac);
	// friend bool operator>(const Fraction& frac1, const Fraction& frac2);

	bool operator<(Fraction const& obj) const;
	bool operator<(float const& obj) const;
	friend bool operator<(const float& f, const Fraction& frac);
	// friend bool operator<(const Fraction& frac1, const Fraction& frac2);

	bool operator>=(Fraction const& obj) const;
	bool operator>=(float const& obj) const;
	// bool operator>=(int const& obj) const;
	friend bool operator>=(const float& f, const Fraction& frac);
	// friend bool operator>=(const Fraction& frac1, const Fraction& frac2);

	bool operator<=(Fraction const& obj) const;
	bool operator<=(float const& obj) const;
	friend bool operator<=(const float& f, const Fraction& frac);
	// friend bool operator<=(const Fraction& frac1, const Fraction& frac2);


	// The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
	Fraction &operator++();  //prefix
	const Fraction operator++(int) ;  //postfix

	Fraction &operator--();  //prefix
	const Fraction operator--(int);  //postfix

	// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
	friend std::ostream &operator<<(std::ostream &out, const Fraction &frac);

	// The >> operator to read a fraction from an input stream by taking two integers as input. 
	friend std::istream &operator>>(std::istream &in, Fraction &frac);

};
#endif
