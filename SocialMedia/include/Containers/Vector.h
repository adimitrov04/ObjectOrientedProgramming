#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <exception>

// Virutal methods in this class template are not needed right now,
// but I'm not sure if I wont change the architecture later so that
// PMVector inherits this, so I'll leave it like this for now

template <class T>
class Vector
{

public:
    Vector ()
    : f_capacity(0), f_size(0), arr(nullptr)
    {}

    Vector (const size_t startingCapacity)
    : Vector<T>()
    {
        reserve(startingCapacity);
    }

    Vector (const Vector<T> &other)
    : Vector<T>()
    {
        copy(other);
    }

    Vector<T>& operator= (const Vector& other)
    {
        if (this != &other)
            copy(other);

        return *this;
    }
    
    T& operator[] (const size_t index)
    {
        return arr[index];
    }

    const T& operator[] (const size_t index) const
    {
        return arr[index];
    }

    // Omitted for now
    /*
    friend std::ostream& operator<< (std::ostream& out, const Vector<T> &vec)
    {
        vec.print(out);

        return out;
    }

    friend std::istream& operator>> (std::istream& in, Vector<T> &vec)
    {
        size_t count = 0;
        in >> count;

        vec.read(count, in);

        return in;
    }
    */

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

    // Omitted for now for PMVector to work
    /*
    virtual void print (std::ostream& out = std::cout) const
    {
        for (int i = 0; i < size(); i++)
            out << arr[i] << ' ';

        out << '\n';
    }
    */
    
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
        if (size() > 0)
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
        if (capacity == 0)
            clear();

        if (capacity <= this->capacity())
            return;
        
        T* buffer = new T[capacity];

        for (size_t i = 0; i < size(); i++)
        {
            buffer[i] = arr[i];
        }

        if (arr)
            delete[] arr;
        
        arr = buffer;
        f_capacity = capacity;
    }

    // Omitted for now for PMVector to work
    /*
    virtual void read (const size_t count, std::istream& in = std::cin)
    {
        if (this->size() > 0)
            clear();

        if (count > capacity())
            reserve(count);

        for (size_t i = 0; i < count; i++)
        {
            T addNew;
            in >> addNew;

            push_back(addNew);
        }
    }
    */

    virtual void clear ()
    {
        delete[] arr;
        arr = nullptr;

        f_size = 0;
        f_capacity = 0;
    }

protected:
    // This method leaves vector empty if it cannot reserve the necessary memory for copy. Fix later.
    virtual void copy (const Vector<T> &other)
    {
        clear();
        reserve(other.capacity());

        for (size_t i = 0; i < other.size(); i++)
        {
            push_back(other[i]);
        }
    }

protected:
    size_t f_capacity;
    size_t f_size;

    T* arr;

private:
    static const size_t DEFAULT_STARTING_CAPACITY = 4;

};

#endif // __VECTOR_H__