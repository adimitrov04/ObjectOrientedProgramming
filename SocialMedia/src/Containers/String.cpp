#include <exception>

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

String& String::operator= (const String& other)
{
    if (this != &other)
        copy(other);

    return *this;
}

String& String::operator= (const char* str)
{
    copy(str);

    return *this;
}

String& String::operator+ (const String& other)
{
    this->cat(other);

    return *this;
}

String& String::operator+ (const char* str)
{
    this->cat(str);

    return *this;
}

const bool String::operator== (const String& other) const
{
    return strcmp(this->c_str(), other.c_str()) ? false : true;
}

const bool String::operator== (const char* str) const
{
    return strcmp(this->c_str(), str) ? false : true;
}

// -- Casts --

String::operator char*() const
{
    char* output = new char[this->size];
    strcpy(output, this->c_str());

    return output;
}

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
    if (arr == nullptr)
        throw std::length_error("String.print: Cannot print empty string");

    out << arr;
}

// -- Setters --

void String::cat (const char* other)
{
    size_t newSize = this->size + strlen(other);
    char* buffer = new char[newSize];

    strcpy(buffer, this->c_str());
    strcat(buffer, other);

    try
    {
        copy(buffer);
    }
    catch (...)
    {
        delete[] buffer;
        throw;
    }

    delete[] buffer;
}

void String::cat (const String& other)
{
    cat(other.c_str());
}

void String::read (std::istream& in)
{
    char* buffer = new char[MAX_BUFFER_LENGTH];
    
    in.getline(buffer, MAX_BUFFER_LENGTH);
    if (in.good() == false)
    {
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        in.clear();

        delete[] buffer;

        throw std::length_error("String.read: Exceeded maximum buffer length.");
    }

    try
    {
        copy(buffer);
    }
    catch (...)
    {
        delete[] buffer;
        throw;
    }

    delete[] buffer;
}

void String::copy (const char* str)
{
    if (str == nullptr)
        throw std::invalid_argument("String.copy: Cannot copy from nullptr");

    char* buffer = new char[strlen(str) + 1];
    
    if (arr)
        clear();

    strcpy(buffer, str);

    arr = buffer;
    size = strlen(str) + 1;
}

void String::copy (const String& other)
{
    copy(other.c_str());
}

void String::clear ()
{
    delete[] arr;
    size = 0;
}
