#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Initialization"){

    CHECK_NOTHROW(Fraction(40,7));
    CHECK_NOTHROW(Fraction(0,4));
    CHECK_THROWS(Fraction(1,0));

}

TEST_CASE("Negative fractions")
{
    Fraction a(-1,4);
    Fraction b(12,-48);
    Fraction c(-2,-40);

    CHECK(a == Fraction(-1,4));
    CHECK(b == (float)(-1)/(float)4);
    CHECK(Fraction(1,20) == c);
    
}

TEST_CASE("Reduction")
{
    Fraction a(12,4);
    Fraction b(12,48);

    CHECK(a == Fraction(3,1));
    CHECK(3 == a);
    CHECK(b == Fraction(1,4));
    
}

TEST_CASE("Addition")
{
    Fraction a(1,4);
    Fraction b(12,36);
    Fraction c(451,200);
    Fraction d(-2,4);

    CHECK(a+b == Fraction(7,12));
    CHECK(a+c == Fraction(501,200));
    CHECK(b+c == Fraction(1553,600));
    CHECK(a+d == Fraction(-1,4));
    CHECK(a+(-0.25) == 0);
    CHECK(b + 0.123  == Fraction(57,125)); //more accurate Fraction(1369,3000)
    d++;
    CHECK(d == 0.5);
    CHECK(++a == 1.25);

}

TEST_CASE("Subtraction")
{
    Fraction a(3,4);
    Fraction b(-12,36);
    Fraction c(0,2);

    CHECK(a-b == Fraction(13,12));
    CHECK(a-0 == a);
    CHECK(b-a == (float)(-13)/(float)12);
    CHECK(0.9 - b == 1.233);
    c--;
    CHECK(c == -1);
    CHECK(--a == -0.25);
   
}

TEST_CASE("Multiplication")
{
    Fraction a(3,14);
    Fraction b(-12,37);
    Fraction c(2,2);

    CHECK(a*b == Fraction(-18,259));
    CHECK(a*1 == a);
    CHECK(9.875*c == 9.875);
    
}

TEST_CASE("Division")
{
    Fraction a(2,14);
    Fraction b(10,-37);

    CHECK_THROWS(a/0);
    CHECK_NOTHROW(0/b);

    CHECK(a/b == Fraction(-37,70));
    CHECK(a/2.1 == 0.068);
    CHECK(4/a == 28);
    CHECK(-2/a == -14);
    
}


TEST_CASE("Comparisons")
{
    Fraction a(2,14);
    Fraction b(10,-37);

    CHECK(a>b);
    CHECK(4>a);
    CHECK(b>-1.5);

    CHECK(b<a);
    CHECK(0.1<a);
    CHECK(Fraction(7,10)<2);

    CHECK(a>=a);
    CHECK(1>=b);
    CHECK(a>=0);

    CHECK(b<=0);
    CHECK(b<=a);
    CHECK(0.111<=a);

    CHECK(b == Fraction(-10,37));
    CHECK(0.5 == Fraction(1,2));
    CHECK(Fraction(8,1) == 8);

}