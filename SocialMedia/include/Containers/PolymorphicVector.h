#pragma once

#ifndef __POLYMORPHIC_VECTOR_H__
#define __POLYMORPHIC_VECTOR_H__

#include <iostream>

// TODO: Remove when Vector is implemented
#include <vector>

//#include "Vector.h"
#include "ICloneable.h"

class PolymorphicVector
{

// TODO: Remove when STD Containers are implemented
// This is kind of dumb because you can put many cloneable objects of different base classes in here,
// template it later to restrict type of base class
using Vector = std::vector<ICloneable*>;

public:
    PolymorphicVector ();
    PolymorphicVector (const PolymorphicVector& other);

    PolymorphicVector& operator= (const PolymorphicVector& other) = delete;

    ~PolymorphicVector();

public:
    const size_t size () const;
    const size_t capacity () const;
    ICloneable* at (const size_t index) const;
    
    void push_back (const ICloneable* element);
    void pop_back ();
    void pop (const size_t index);
    void reserve (const size_t capacity);

    void clear ();

private:
    void copy (const PolymorphicVector& other);

private:
    Vector vec;

};

#endif // __POLYMORPHIC_VECTOR_H__