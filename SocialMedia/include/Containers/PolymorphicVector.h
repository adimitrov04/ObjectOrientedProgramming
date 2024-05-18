#pragma once

#ifndef __POLYMORPHIC_VECTOR_H__
#define __POLYMORPHIC_VECTOR_H__

#include <iostream>

#include "Vector.h"

#include "ICloneable.h"

//template <class T>
class PolymorphicVector
{

public:
    PolymorphicVector ();
    PolymorphicVector (const PolymorphicVector& other);

    PolymorphicVector& operator= (const PolymorphicVector& other) = delete;

    ~PolymorphicVector();

public:
    const size_t size () const;
    const size_t capacity () const;
    ICloneable* at (const size_t index) const;
    
    void push_back (ICloneable* element);
    void pop_back ();
    void pop (const size_t index);
    void reserve (const size_t capacity);

    void clear ();

private:
    void copy (const PolymorphicVector& other);

private:
// This is bad because you can put cloneable objects of different base classes in here,
// template it later to restrict type of base class
    Vector<ICloneable*> vec;

};

#endif // __POLYMORPHIC_VECTOR_H__