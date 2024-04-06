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
    this->copy(other);
}

void Rational::copy (const Rational& other)
{
    this->numerator = other.GetNumerator();
    this->denominator = other.GetDenominator();
}

Rational& Rational::operator=(const Rational& other)
{
    if (this != &other)
    {
        const Rational empty;

        this->copy(empty);
        this->copy(other);
    }

    return *this;
}

bool Rational::operator==(const Rational& other)
{
    return this->IsEqual(other);
}

Rational Rational::operator+(const Rational& other)
{
    return this->Sum(other);
}

Rational Rational::operator-(const Rational& other)
{
    return this->Subtract(other);
}

Rational Rational::operator*(const Rational& other)
{
    return this->Multiply(other);
}

Rational Rational::operator/(const Rational& other)
{
    return this->Divide(other);
}

const int Rational::GetDenominator () const
{
    return this->denominator;
}

const int Rational::GetNumerator () const
{
    return this->numerator;
}

Rational Rational::Sum (Rational operand) const
{
    Rational result(*this);

    if (result.GetDenominator() != operand.GetDenominator())
    {
        const int LEAST_COMMON_MULTIPLE = result.findLCM(operand);
        
        const Rational MULTIPLY_THIS(LEAST_COMMON_MULTIPLE / result.GetDenominator(), LEAST_COMMON_MULTIPLE / result.GetDenominator());
        const Rational MULTIPLY_OTHER(LEAST_COMMON_MULTIPLE / operand.GetDenominator(), LEAST_COMMON_MULTIPLE / operand.GetDenominator());

        result = result.Multiply(MULTIPLY_THIS);
        operand = operand.Multiply(MULTIPLY_OTHER);
    }

    result.numerator += operand.GetNumerator();
    return result;
}

Rational Rational::Sum (const int num) const
{
    Rational operand(num);
    return this->Sum(operand);
}

Rational Rational::Subtract (Rational operand) const
{
    operand = operand.Multiply(MINUS_ONE);
    return this->Sum(operand);
}

Rational Rational::Subtract (const int num) const
{
    Rational operand(num);
    return this->Subtract(operand);
}

Rational Rational::Multiply (const Rational& operand) const
{
    Rational result(*this);

    result.numerator *= operand.GetNumerator();
    result.denominator *= operand.GetDenominator();

    return result;
}

Rational Rational::Multiply (const int num) const
{
    Rational operand(num);
    return this->Multiply(operand);
}

Rational Rational::Divide (const Rational& operand) const
{
    Rational opReciprocal(operand.GetDenominator(), operand.GetNumerator());
    return this->Multiply(opReciprocal);
}

Rational Rational::Divide (const int num) const
{
    Rational operand(num);
    return this->Divide(operand);
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