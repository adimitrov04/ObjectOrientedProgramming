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
    uint16_t GetAge() const;
    void Print (std::ostream& out = std::cout) const;

    void SetName (const std::string name);

protected:
    std::string fName;
    uint16_t fAge;

private:
    bool validName (const std::string name) const;

};

#endif // __PERSON_CLASS_INCLUDED__