#pragma once

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{

public:
    Vector()
    : f_capacity(0), f_size(0), arr(nullptr)
    {}

    Vector(const size_t starting_capacity)
    : Vector<T>()
    {
        reserve(starting_capacity);
    }

    Vector(const Vector<T> &other)
    : Vector<T>()
    {
        copy(other);
    }

    ~Vector()
    {
        delete[] arr;
    }

public:
    Vector<T> &operator=(const Vector& other)
    {
        if (this != other)
            copy(other);

        return *this;
    }

    Vector<T> &operator=(const Vector&& other)
    {
        if (this != &other)
        {
            if (this->arr)
                clear();

            this->arr = other.arr();
            other.arr = nullptr;

            f_capacity = other.capacity();
            f_size = other.size();
        }

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

    friend std::ostream& operator<< (std::ostream& out, const Vector<T> &vec)
    {
        vec.print(out);

        return out;
    }

    friend std::istream& operator>> (std::istream& in, Vector<T> &vec)
    {
        size_t count(0);
        in >> count;
        vec.read(count, in);

        return in;
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

    T& at (const size_t index)
    {
        if (index < 0 || index >= size())
            throw std::invalid_argument("Vector.at: Given index outside of vector.");

        return arr[index];
    }

    const T& at (const size_t index) const
    {
        if (index < 0 || index >= size())
            throw std::invalid_argument("Vector.at: Given index outside of vector.");

        return arr[index];
    }
    
    void print (std::ostream& out = std::cout) const
    {
        for (size_t i = 0; i < size(); i++)
        {
            out << arr[i] << ' ';
        }
    }
    
    void push_back (const T& element)
    {
        if (capacity() == 0)
            reserve(DEFAULT_STARTING_CAPACITY);

        if (size() == capacity())
            reserve(f_capacity * 2);
        
        arr[f_size] = element;
        f_size++;
    }

    void pop_back ()
    {
        f_size--;
    }

    void reserve (const size_t capacity)
    {
        if (capacity <= this->capacity())
            return;

        T* buffer = new T[capacity];
        try
        {
            for (size_t i = 0; i < size(); i++)
                buffer[i] = arr[i];
        }
        catch (...)
        {
            delete[] buffer;
            throw;
        }

        delete[] arr;
        arr = buffer;
        f_capacity = capacity;
    }

    void read (const size_t count, std::istream& in = std::cin)
    {
        for (size_t i = 0; i < count; i++)
        {
            T temp;
            in >> temp;

            push_back(temp);
        }
    }

    void clear () noexcept
    {
        delete[] arr;
        f_capacity = 0;
        f_size = 0;
    }

private:
    void copy (const Vector<T> &other)
    {
        Vector<T> buffer;
        buffer.reserve(other.capacity());
        
        for (size_t i = 0; i < other.f_size; i++)
            buffer.push_back(other[i]);

        this->clear();
        this->arr = buffer.arr;
        f_capacity = buffer.capacity();
        f_size = buffer.size();
    }

private:
    static const size_t DEFAULT_STARTING_CAPACITY = 4;
    
    size_t f_capacity;
    size_t f_size;

    T* arr;

};

#endif // __VECTOR_H__