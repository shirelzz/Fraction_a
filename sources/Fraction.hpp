#pragma once
#include<iostream>
#include <stdexcept>
using namespace std;
class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(int, int);
	int get_numerator() const;
	int get_denominator() const;

	friend ostream& operator<<(ostream&, const Fraction&);

	int get_gcd(int a, int b) const;
};


