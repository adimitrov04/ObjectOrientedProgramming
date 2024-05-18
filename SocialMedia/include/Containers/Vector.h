#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <exception>

template <class T>
class Vector
{

public:
    Vector ()
    : f_capacity(0), f_size(0), arr(nullptr)
    {}

    Vector (const Vector& other) = delete;

    Vector<T>& operator= (const Vector& other) = delete;
    T& operator[] (const size_t index) = delete;
    const bool operator== (const Vector& other) const = delete;

    std::ostream& operator<< (std::ostream& out) const = delete;
    std::istream& operator>> (std::istream& in) const = delete;

    virtual ~Vector ()
    {
        clear();
    }

public:
    const size_t size () const
    {
        return f_size;
    }

    const size_t capacity () const
    {
        return f_capacity;
    }

    T& at (const size_t index) const
    {
        if (index >= size() || index < 0)
            throw std::range_error("Vector.at: given index outside of vector");

        return arr[index];
    }

    virtual void print (std::ostream& out = std::cout) const
    {
        for (int i = 0; i < size(); i++)
            out << arr[i] << ' ';
    }
    
    virtual void push_back (const T& element)
    {
        if (capacity() == 0)
            reserve(DEFAULT_STARTING_CAPACITY);
        
        if (size() == capacity())
            reserve(capacity() * 2);

        arr[size()] = element;
        f_size++;
    }

    virtual void pop_back ()
    {
        if (size())
            f_size--;
    }

    virtual void pop (const size_t index)
    {
        for (int i = index; i < (size() - 1); i++)
        {
            at(i) = arr[i + 1];
        }
    }

    void reserve (const size_t capacity)
    {
        T* buffer = new T[capacity];

        for (int i = 0; i < size(); i++)
        {
            buffer[i] = arr[i];
        }

        if (arr)
            delete[] arr;
        
        arr = buffer;
        f_capacity = capacity;
    }

    virtual void read (const size_t size, std::istream& in = std::cin)
    {
        if (this->size() > 0)
            clear();

        if (size > capacity())
            reserve(size);

        for (int i = 0; i < size; i++)
        {
            T addNew;
            in >> addNew;

            push_back(addNew);
        }
    }

    virtual void clear ()
    {
        delete[] arr;
        arr = nullptr;

        f_size = 0;
        f_capacity = 0;
    }

protected:
    void copy (const Vector<T> &other);

protected:
    size_t f_capacity;
    size_t f_size;

    T* arr;

private:
    static const size_t DEFAULT_STARTING_CAPACITY = 4;

};

#endif // __VECTOR_H__