#include "../../include/Containers/String.h"

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

void String::cat (const String& other)
{
    cat(other.c_str());
}

void String::cat (const char* other)
{
    size_t newSize = this->size + strlen(other);
    char* buffer = new char[newSize];

    strcpy(buffer, this->c_str());
    strcat(buffer, other);

    clear();
    arr = buffer;
    size = newSize;
}

void String::read (std::istream& in)
{

}

void String::clear ()
{
    delete[] arr;
    size = 0;
}
