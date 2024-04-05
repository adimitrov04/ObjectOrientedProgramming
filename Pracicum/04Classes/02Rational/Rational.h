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
    void Sum (Rational operand);
    void Sum (const int num);

    void Subtract (Rational operand);
    void Subtract (const int num);
    
    void Multiply (Rational operand);
    void Multiply (const int num);
    
    void Divide (Rational operand);
    void Divide (const int num);
    
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