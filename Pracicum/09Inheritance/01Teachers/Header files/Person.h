#ifndef __PERSON_CLASS_INCLUDED__
#define __PERSON_CLASS_INCLUDED__

#include <string>
#include <iostream>
#include <cstdint>

class Person
{

public:
    Person (const std::string name, const uint16_t age);

public:
    std::string GetName() const;
    int GetAge() const;
    void Print (std::ostream& out = std::cout) const;

    void SetName ();

protected:
    std::string fName;
    uint16_t fAge;

};

#endif // __PERSON_CLASS_INCLUDED__