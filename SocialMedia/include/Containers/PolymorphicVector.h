#pragma once

#ifndef __POLYMORPHIC_VECTOR_H__
#define __POLYMORPHIC_VECTOR_H__

#include <iostream>

// TODO: Remove when STD Containers are implemented
#include <vector>

//#include "Vector.h"
#include "../Commands/Command.h"

//template <class T>

//TODO: Make template later
//Right now PolymorphicVector only works with containing Command child classes
class PolymorphicVector
{

// TODO: Remove when STD Containers are implemented
using Vector = std::vector<Command*>;

public:
    PolymorphicVector ();
    PolymorphicVector (const PolymorphicVector& other);

    PolymorphicVector& operator= (const PolymorphicVector& other) = delete;

    ~PolymorphicVector();

public:
    const size_t size () const;
    const size_t capacity () const;
    Command* at (const size_t index) const;
    
    void push_back (const Command* element);
    void pop_back ();
    void pop (const size_t index);
    //void ensure_capacity (const size_t capacity);

    void clear ();

private:
    void copy (const PolymorphicVector& other);

private:
    Vector arr;

};

#endif // __POLYMORPHIC_VECTOR_H__