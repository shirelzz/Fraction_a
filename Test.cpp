#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Initialization"){

    CHECK_NOTHROW(Fraction(40,7));
    CHECK_NOTHROW(Fraction(0,4));

}

TEST_CASE("Division by zero")
{
    CHECK_THROWS(Fraction(2,0));
    CHECK_THROWS(Fraction(-3,0));
    CHECK_THROWS(Fraction(0,-0));

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
    
}

TEST_CASE("Subtraction")
{
    Fraction a(3,4);
    Fraction b(-12,36);
    Fraction c(0,2);

    CHECK(a-b == Fraction(13,12));
    CHECK(a-c == a);
    CHECK(b-a == (float)(-13)/(float)12);

}

TEST_CASE("Multiplication")
{
    Fraction a(3,14);
    Fraction b(-12,37);
    // Fraction c(2.2,8);
    Fraction d(2,2);

    CHECK(a*b == Fraction(-18,259));
    // CHECK(a*c == 33/560);
    // CHECK(b*c == -33/370);
    CHECK(a*d == Fraction(3,14));
    
}

TEST_CASE("Division")
{
    Fraction a(2,14);
    Fraction b(10,-37);
    // Fraction c(2.2,8);
    // Fraction d(2.35,2.1);

    CHECK_THROWS(a/0);
    CHECK_NOTHROW(0/b);
    CHECK(a/b == Fraction(-37,70));
    // CHECK(a/c == 40/77);
    // CHECK(b/c == -200/187);
    // CHECK(a/d == 6/47);
    // CHECK(b/d == -210/799);
}


TEST_CASE("Comparisons")
{
    Fraction a(2,14);
    Fraction b(10,-37);

    CHECK(a>b);
    CHECK(a== Fraction(1,7));
    CHECK(b<=0);
    CHECK(a<4);
    
}

// TEST_CASE("<<, >> operators")
// {
//     Fraction a(2,14);
//     Fraction b(10,-37);
//     Fraction d(1,7);
    
// }