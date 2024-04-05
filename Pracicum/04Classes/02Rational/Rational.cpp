#include <iostream>
#include <cmath>
#include "Rational.h"

const Rational MINUS_ONE(-1, 1);

Rational::Rational ()
{
    this->numerator = 0;
    this->denominator = 1;
}

Rational::Rational(const int num)
: Rational()
{
    this->numerator = num;
}

Rational::Rational (const int num, const int denom)
: Rational()
{
    if (denom == 0)
        throw "ZeroDenominatorException";

    this->numerator = num;
    this->denominator = denom;

    if (this->denominator < 0)
    {
        this->numerator *= -1;
        this->denominator *= -1;
    }
}

Rational::Rational (const Rational& other)
: Rational()
{
    if (other.GetDenominator() == 0)
        throw "ZeroDenominatorException";

    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

Rational& Rational::operator=(const Rational& other)
{
    if (this != &other)
    {
        this->clear();

        this->numerator = other.GetNumerator();
        this->denominator = other.GetDenominator();
    }

    return *this;
}

bool Rational::operator==(const Rational& other)
{
    return this->IsEqual(other);
}

Rational Rational::operator+(const Rational& other)
{
    Rational result(*this);
    result.Sum(other);

    return result;
}

Rational Rational::operator-(const Rational& other)
{
    Rational result(*this);
    result.Subtract(other);

    return result;
}

Rational Rational::operator*(const Rational& other)
{
    Rational result(*this);
    result.Multiply(other);

    return result;
}

Rational Rational::operator/(const Rational& other)
{
    Rational result(*this);
    result.Divide(other);

    return result;
}

void Rational::clear ()
{
    this->numerator = 0;
    this->denominator = 1;
}

const int Rational::GetDenominator () const
{
    return this->denominator;
}

const int Rational::GetNumerator () const
{
    return this->numerator;
}

void Rational::Sum (Rational operand)
{
    if (this->GetDenominator() != operand.GetDenominator())
    {
        const int LARGEST_COMMON_MULTIPLE = this->findLCM(operand);
        
        const Rational MULTIPLY_THIS(LARGEST_COMMON_MULTIPLE / this->denominator, LARGEST_COMMON_MULTIPLE / this->denominator);
        const Rational MULTIPLY_OTHER(LARGEST_COMMON_MULTIPLE / operand.GetDenominator(), LARGEST_COMMON_MULTIPLE / operand.GetDenominator());

        this->Multiply(MULTIPLY_THIS);
        operand.Multiply(MULTIPLY_OTHER);
        
        this->numerator += operand.GetNumerator();
    }

}

void Rational::Sum (const int num)
{
    Rational operand(num);
    this->Sum(operand);
}

void Rational::Subtract (Rational operand)
{
    operand.Multiply(MINUS_ONE);
    this->Sum(operand);
}

void Rational::Subtract (const int num)
{
    Rational operand(num);
    this->Subtract(operand);
}

void Rational::Multiply (Rational operand)
{
    if (this->GetDenominator() == operand.GetNumerator())
    {
        this->denominator = operand.GetDenominator();
        return;
    }

    if (this->GetNumerator() == operand.GetDenominator())
    {
        this->numerator = operand.GetNumerator();
        return ;
    }

    this->denominator *= operand.GetDenominator();
    this->numerator *= operand.GetNumerator();
}

void Rational::Multiply (const int num)
{
    Rational operand(num);
    this->Multiply(operand);
}

void Rational::Divide (Rational operand)
{
    try
    {
        Rational opReciprocal(operand.GetDenominator(), operand.GetNumerator());
        this->Multiply(opReciprocal);
    }
    catch (const char* exc)
    {
        std::cout << exc << std::endl;
    }
}

void Rational::Divide (const int num)
{
    Rational operand(num);
    this->Divide(operand);
}

void Rational::Simplify ()
{
    int GCF = this->findGCF(this->GetNumerator());
    
    while (GCF > 1)
    {
        this->numerator /= GCF;
        this->denominator /= GCF;
        GCF = this->findGCF(this->GetNumerator());
    }
}

bool Rational::IsEqual (Rational comparee) const
{
    Rational thisProxy(this->GetNumerator(), this->GetDenominator());
    thisProxy.Simplify();
    comparee.Simplify();

    if (thisProxy.GetNumerator() == comparee.GetNumerator() && thisProxy.GetDenominator() == comparee.GetDenominator())
        return true;

    return false;
}

/*
const bool Rational::IsPositive () const
{
    bool isPositive = true;

    if (this->numerator < 0)
        isPositive ^= true;

    if (this->denominator < 0)
        isPositive ^= true;

    return isPositive;
}
*/

void Rational::Print (std::ostream& dest) const
{
    if (this->GetDenominator() == 1)
    {
        dest << this->GetNumerator();
        return ;
    }

    if (this->GetNumerator() < 0)
        dest << '-';

    dest << '(' << std::abs(this->numerator) << "/" << std::abs(this->denominator) << ')';
}

int Rational::findGCF (const int other) const
{   
    int i = 0;
    for (i = std::min(std::abs(this->GetDenominator()), std::abs(other)); i > 1; i--)
    {
        if ((this->GetDenominator() % i == 0) && (other % i == 0))
            break;
    }

    return i;
}

int Rational::findLCM (const Rational& other) const
{
    return std::abs(this->GetDenominator() * other.GetDenominator()) / this->findGCF(other.GetDenominator());
}