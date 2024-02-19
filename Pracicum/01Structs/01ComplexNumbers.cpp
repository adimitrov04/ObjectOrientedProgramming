#include <iostream>

using std::endl;

struct ComplexNum
{
    double realPart = 0.0, imPart = 1.0;
};

void print (const ComplexNum& num)
{
    std::cout << '(' << num.realPart << " + " << num.imPart << "i)";
}

ComplexNum sumComplex (ComplexNum num1, ComplexNum num2)
{
    ComplexNum sum;
    sum.realPart = num1.realPart + num2.realPart;
    sum.imPart = num1.imPart + num2.imPart;

    return sum;
}

int main ()
{
    ComplexNum num1 = {5.0, 6.3};
    ComplexNum num2 = {4.4, 9.0};

    ComplexNum sum = sumComplex(num1, num2);
    
    print(num1); std::cout << " + ";
    print(num2); std::cout << " = ";
    print(sum);

    return 0;
}