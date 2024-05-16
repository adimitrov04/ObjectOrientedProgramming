#include "../include/Containers/String.h"

// -- Life cycle --

String::String()
: size(0),
  arr(nullptr)
{}

String::String (const char* str)
: String()
{
    size = strlen(str) + 1;
    arr = new char[size];

    strcpy(arr, str);
}

String::String (const String& other)
: String(other.c_str())
{}

String::~String()
{
    clear();
}

// -- Operators --



// -- Getters --

const size_t String::get_length () const
{
    return strlen(arr);
}

const char* String::c_str () const
{
    return arr;
}

void String::print (std::ostream& out) const
{
    out << arr;
}

// -- Setters --

void String::clear ()
{
    delete[] arr;
    size = 0;
}
