#pragma once

#ifndef __STACK_H__
#define __STACK_H__

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Stack
{

public:
    Stack() : arr(nullptr), size(0)
    {}
    
    Stack (const Stack<T> &other) = delete;

    Stack<T>& operator= (const Stack<T> &other) = delete;

    ~Stack() { clear(); }

public:
    const T& peek () const noexcept;
    bool isEmpty () const noexcept;
    void print (std::ostream& out = std::cout) const noexcept;

    void push (const T& element);
    void pop ();

private:
    //void resize ();
    void clear () noexcept;

private:
    T* arr;
    size_t size;

};

#include "Stack.ipp"

#endif // __STACK_H__