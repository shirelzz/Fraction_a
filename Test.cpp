#include "doctest.h"
#include <stdexcept>
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

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
    Fraction c(-2.25,-4);

    CHECK(a == -1/4);
    CHECK(b == -1/4);
    CHECK(c == 9/16);
    
}

TEST_CASE("Reduction")
{
    Fraction a(12,4);
    Fraction b(12,48);
    Fraction c(2.25,4);

    CHECK(a == 3/1);
    CHECK(b == 1/4);
    CHECK(c == 9/16);
    
}

TEST_CASE("Addition")
{
    Fraction a(1,4);
    Fraction b(12,36);
    Fraction c(2.25,4);
    Fraction d(-2,4);

    CHECK(a+b == 7/12);
    CHECK(a+c == 13/16);
    CHECK(b+c == 43/48);
    CHECK(a+d == -1/4);
    
}

TEST_CASE("Subtraction")
{
    Fraction a(3,4);
    Fraction b(-12,36);
    Fraction c(2.25,4);
    Fraction d(2.341,0.5);

    CHECK(a-b == 13/12);
    CHECK(a-c == 3/16);
    CHECK(b-c == -43/48);
    CHECK(a-d == -983/250);
    CHECK(b-d == -7523/1500);

}

TEST_CASE("Multiplication")
{
    Fraction a(3,14);
    Fraction b(-12,37);
    Fraction c(2.2,8);
    Fraction d(2.341,2);

    CHECK(a*b == -18/259);
    CHECK(a*c == 33/560);
    CHECK(b*c == -33/370);
    CHECK(a*d == 7023/28000);
    CHECK(b*d == -7523/1500);
    
}

TEST_CASE("Division")
{
    Fraction a(2,14);
    Fraction b(10,-37);
    Fraction c(2.2,8);
    Fraction d(2.35,2.1);

    CHECK(a/b == -37/70);
    CHECK(a/c == 40/77);
    CHECK(b/c == -200/187);
    CHECK(a/d == 6/47);
    CHECK(b/d == -210/799);
}


TEST_CASE("Comparisons")
{
    Fraction a(2,14);
    Fraction b(10,-37);
    Fraction c(2.22,8);
    Fraction d(1,6);

    CHECK_EQ(a>b, true);
    CHECK_EQ(a==1/7, true);
    CHECK_EQ(b>=0, true);
    CHECK_EQ(a<=b, false);
    CHECK_EQ(a>4, false);
    CHECK_EQ(c>d, true);
    // CHECK_EQ(d == 1.166, true);
    
}

// TEST_CASE("<<, >> operators")
// {
//     Fraction a(2,14);
//     Fraction b(10,-37);
//     Fraction c(2.2,8);
//     Fraction d(1,7);
    
// }