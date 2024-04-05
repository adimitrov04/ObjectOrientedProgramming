#include <iostream>
#include "Rational.h"

using std::endl;

int main ()
{
    Rational num1(-8, 12), num2(2, 7), num3(8, 3);
    Rational result;
    
    num1.Print();
    std::cout << " - ";
    num2.Print();
    result = (num1 - num2);
    // (-56 - 24 / 84) = -(80 / 84)
    std::cout << " = ";
    result.Print();
    result.Simplify();
    // -(4 * 20 / 4 * 21) = -(20 / 21)
    std::cout << " = ";
    result.Print();
    std::cout << endl;
    
    result.Print();
    std::cout << " + ";
    num3.Print();
    result = result + num3;
    // -(20 / 21) + (8 / 3)
    // -(20 / 21) + (56 / 21) = (36 / 21)
    std::cout << " = ";
    result.Print();
    result.Simplify();
    // (3 * 12 / 3 * 7) = (12 / 7)
    std::cout << " = ";
    result.Print();
    std::cout << endl;

    result.Print();
    std::cout << " / ";
    num2.Print();
    result = result / num2;
    std::cout << " = ";
    result.Print();
    // (12 / 7) * (7 / 2) = (84 / 14)
    result.Simplify();
    // (42 * 2 / 7 * 2) = (42 / 7) = 6
    std::cout << " = ";
    result.Print();
    std::cout << endl;

    return 0;
}