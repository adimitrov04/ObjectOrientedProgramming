#include <iostream>
#include <exception>
#include "Rational.h"

using std::endl;

int main ()
{
    Rational num1(3, 5), num2(7, 8);
    Rational num3 = (num1 + num2);

    num1.Print();
    std::cout << " / ";
    num2.Print();
    std::cout << " = ";
    num3.Simplify();
    num3.Print();

    return 0;
}