#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>

template <class T>
class Vector
{

public:
    Vector ();
    Vector (const Vector& other) = delete;

    Vector& operator= (const Vector& other) = delete;
    T& operator[] (const size_t index) = delete;
    const bool operator== (const Vector& other) const = delete;

    std::ostream& operator<< (std::ostream& out) const = delete;
    std::istream& operator>> (std::istream& in) const = delete;

    ~Vector ();

public:
    const size_t size () const;
    const size_t capacity () const;
    T& at (const size_t index) const;
    void print (std::ostream& out = std::cout) const;
    
    void push_back (const T element);
    void pop_back ();
    void pop (const size_t index);
    void ensure_capacity (const size_t capacity);

    void read (std::istream& in = std::cin);
    void clear ();


private:
    size_t capacity;
    size_t f_size;

    T* arr;

};

#endif // __VECTOR_H__