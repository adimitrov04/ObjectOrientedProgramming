#pragma once

#ifndef __POLYMORPHIC_CONTAINER_H__
#define __POLYMORPHIC_CONTAINER_H__

#include <iostream>

// TODO: Remove when STD Containers are implemented
#include <vector>
#include "../Commands/Command.h"

//#include "Vector.h"

//template <class T>

//TODO: Make template later
//Right now PolymorphicContainer only works with containing Command child classes
class PolymorphicContainer
{

// TODO: Remove when STD Containers are implemented
using Vector = std::vector<Command*>;

public:
    PolymorphicContainer ();
    PolymorphicContainer (const PolymorphicContainer& other);

    PolymorphicContainer &operator= (const PolymorphicContainer& other) = delete;

    ~PolymorphicContainer();

public:
    const size_t size () const;
    const size_t capacity () const;
    Command* at (const size_t index) const;
    
    void push_back (const Command* element);
    void pop_back ();
    void pop (const size_t index);
    void ensure_capacity (const size_t capacity);

    void clear ();

private:
    void copy (const PolymorphicContainer& other);

private:
    Vector arr;

};

#endif // __POLYMORPHIC_CONTAINER_H__