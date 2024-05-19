#pragma once

#ifndef __POLYMORPHIC_VECTOR_H__
#define __POLYMORPHIC_VECTOR_H__

#include <iostream>
#include <type_traits> // Used to enforce class T being derived from ICloneable

#include "Vector.h"

#include "ICloneable.h"

template <class T>
class PMVector
{

static_assert(std::is_base_of<ICloneable, T>::value, "Type must be cloneable in order to create polymorphic vector."); // Not sure if this is needed

public:
    PMVector () = default;

    PMVector (const PMVector<T> &other)
    : PMVector()
    {
        copy(other);
    }

    PMVector<T> &operator= (const PMVector<T> &other)
    {
        if (this != &other)
            copy(other);

        return *this;
    }

    T* operator[] (const size_t index)
    {
        return vec[index];
    }

    const T* operator[] (const size_t index) const
    {
        return vec[index];
    }

    ~PMVector()
    {
        clear();
    }

public:
    const size_t size() const
    {
        return vec.size();
    }

    const size_t capacity() const
    {
        return vec.capacity();
    }

    T* at (const size_t index) const
    {
        return vec.at(index);
    }

    void push_back (T* element)
    {
        vec.push_back(element);
    }

    void pop_back ()
    {
        if (size() == 0)
            return;
        
        delete vec[size()];
        vec.pop_back();
    }
    
    void pop (const size_t index)
    {
        std::swap(vec[index], vec[size()]);
        pop_back();
    }

    void reserve (const size_t capacity)
    {
        vec.reserve(capacity);
    }
    
    void clear ()
    {
        for (size_t i = 0; i < size(); i++)
            delete vec[i];

        vec.clear();
    }

private:
    void copy (const PMVector<T> &other)
    {
        try
        {
            clear();
            reserve(other.capacity());

            for (size_t i = 0; i < other.size(); i++)
            {
                push_back(other[i]->clone());
            }
        }
        catch (...)
        {
            clear();
            throw;
        }
    }

private:
    Vector<T*> vec;


};

#endif // __POLYMORPHIC_VECTOR_H__