#pragma once

#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

// TODO: Remove when Vector is implemented
#include <vector>

//#include "Vector.h"

class String
{

// TODO: Remove when Vector is implemented
using Vector = std::vector<String>;

public:
    String ();
    String (const String& other);
    String (const char* other);

    String& operator= (const String& other);
    String& operator= (const char* other);

    String& operator+ (const String& other);
    String& operator+ (const char* str);

    const bool operator== (const String& other) const;
    const bool operator== (const char* str) const;

    friend std::ostream& operator<< (std::ostream& out, const String& str);
    friend std::istream& operator>> (std::istream& in, String& str);

    explicit operator char*() const;

    ~String();

public:
    const size_t get_length () const;
    const char* c_str () const;
    Vector extract_words () const;
    void print (std::ostream& out = std::cout) const;

    void cat (const char* other);
    void cat (const String& other);

    void copy (const char* str);
    void copy (const String& other);
    void clear ();

    void read (std::istream& in = std::cin);

private:
/*
    const char* findNextWord (const char* currentPosition);
    String getCurrentWordInString (const char* word);
    const size_t getCurrentWordLength (const char* word);

    const bool isnewline (const char ch);
*/

private:
    static const size_t MAX_BUFFER_LENGTH = 100000;

    size_t size;
    char* arr;

};

#endif // __STRING_H__