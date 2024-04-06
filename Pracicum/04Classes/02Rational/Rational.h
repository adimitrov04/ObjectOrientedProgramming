#ifndef __RATIONAL_NUM__
#define __RATIONAL_NUM__

#include <iostream>

class Rational
{
public:
    // Constructors
    Rational ();
    Rational (const int num);
    Rational (const int num, const int denom);
    Rational (const Rational& other);
    ~Rational () = default;

    // Overloaded operators
    Rational& operator=(const Rational& other);
    bool operator==(const Rational& other);

    Rational operator+(const Rational& other);
    Rational operator-(const Rational& other);
    Rational operator*(const Rational& other);
    Rational operator/(const Rational& other);

    // Getters
    const int GetDenominator () const;
    const int GetNumerator () const;

    // Modifiers
    Rational Sum (Rational operand) const;
    Rational Sum (const int num) const;

    Rational Subtract (Rational operand) const;
    Rational Subtract (const int num) const;
    
    Rational Multiply (const Rational& operand) const;
    Rational Multiply (const int num) const;
    
    Rational Divide (const Rational& operand) const;
    Rational Divide (const int num) const;
    
    void Simplify ();

    // Analysis
    const bool IsPositive () const = delete;
    void Print (std::ostream& dest = std::cout) const;

private:
    int numerator;
    int denominator;

    void clear ();
    int findGCF (const int other) const;
    int findLCM (const Rational& other) const;
    bool IsEqual (Rational comparee) const;
};

#endif // __RATIONAL_NUM__