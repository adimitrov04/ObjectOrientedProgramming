#include <cstring>
#include <exception>
#include "../Header files/Person.h"

Person::Person(const std::string name, const uint16_t age)
{
    this->SetName(name);
    this->fAge = age;
}

std::string Person::GetName () const
{
    return this->fName;
}

uint16_t Person::GetAge () const
{
    return this->fAge;
}

void Person::Print (std::ostream& out) const
{
    out << "Name: " << this->fName << std::endl; 
    out << "Age: " << this->fAge << std::endl; 
}

void Person::SetName (const std::string name)
{
    if (strlen(name.c_str()) == 0)
        throw std::invalid_argument("Person.SetName: Name length cannot be 0");

    if (validName(name) == false)
        throw std::invalid_argument("Person.SetName: Name cannot contain non-letter characters");

    this->fName = name;
}

bool Person::validName (const std::string name) const
{
    const char* proxy = name.c_str();

    while (*proxy)
    {
        if (isalpha(*proxy) && isspace(*proxy) == false)
            return false;
    }
}