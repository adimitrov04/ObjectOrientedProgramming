#pragma once

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <limits>
#include <cstring>

// TODO: Remove when Vector is implemented
#include <vector>

//#include "Vector.h"

class String
{

// TODO: Remove when Vector is implemented
using Vector = std::vector<String>;

public:
    // TODO: Implement deleted functions
    String ();
    String (const String& other);
    String (const char* other);

    String& operator= (const String& other);
    String& operator+ (const String& other) = delete;

    String& operator= (const char* other) = delete;
    String& operator+ (const char* other) = delete;

    const bool operator== (const String& other) = delete;
    std::ostream& operator<< (std::ostream& out) const = delete;
    std::ostream& operator>> (std::istream& in) = delete;

    const bool operator== (const char* other) = delete;

    ~String();

public:
    const size_t get_length () const;
    const char* c_str () const;
    //Vector &extract_words () const;
    void print (std::ostream& out = std::cout) const;

    void cat (const char* other);
    void cat (const String& other);

    void copy (const char* str);
    void copy (const String& other);
    void clear ();

    void read (std::istream& in = std::cin);

private:

private:
    static const size_t MAX_BUFFER_LENGTH = 100000;

    size_t size;
    char* arr;

};

#endif // __STRING_H__