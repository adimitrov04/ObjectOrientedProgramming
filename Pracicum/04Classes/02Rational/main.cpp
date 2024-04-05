#include <iostream>
#include "Rational.h"

using std::endl;

int main ()
{
    Rational num(8, 16), num2(2, 4);
    num.Simplify();
    num2.Simplify();
    num.Print(); std::cout << endl;
    num2.Print(); std::cout << endl;

    num.Divide(num2);
    num.Print(); std::cout << endl;
    num.Divide(2);

    num.Print(); std::cout << endl;
    num2.Print(); std::cout << endl;
    std::cout << (num == num2) << endl;

    return 0;
}