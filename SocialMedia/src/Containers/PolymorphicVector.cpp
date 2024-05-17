#include "../../include/Containers/PolymorphicVector.h"

// -- Life cycle --

PolymorphicVector::PolymorphicVector()
: vec()
{}

PolymorphicVector::PolymorphicVector (const PolymorphicVector& other)
{
    copy(other);
}

//PolymorphicVector::PolymorphicVector& operator= (const PolymorphicVector& other);

PolymorphicVector::~PolymorphicVector()
{
    clear();
}

// -- Getters --

const size_t PolymorphicVector::size () const
{
    return vec.size();
}

const size_t PolymorphicVector::capacity () const
{
    return vec.capacity();
}

ICloneable* PolymorphicVector::at (const size_t index) const
{
    return vec.at(index);
}

// -- Setters --

void PolymorphicVector::push_back (ICloneable* element)
{
    vec.push_back(element);
}

void PolymorphicVector::pop_back ()
{
    vec.pop_back();
}

void PolymorphicVector::reserve (const size_t capacity)
{
    vec.reserve(capacity);
}

void PolymorphicVector::copy (const PolymorphicVector& other)
{
    try
    {
        reserve(other.size());

        for (int i = 0; i < other.size(); i++)
            push_back(other.at(i)->clone());
    }
    catch (...)
    {
        clear();
        throw;
    }
}

void PolymorphicVector::clear ()
{
    for (int i = 0; i < vec.size(); i++)
        delete vec[i];

    vec.clear();
}