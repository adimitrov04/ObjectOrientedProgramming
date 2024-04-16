#ifndef __PERSON_CLASS_INCLUDED__
#define __PERSON_CLASS_INCLUDED__

#include <string>
#include <iostream>
#include <cstdint>

class Person
{

// Interface
public:
    std::string GetName() const;
    int GetAge() const;
    void Print (std::ostream& out = std::cout) const;

    void SetName ();

protected:
    std::string fName;
    uint64_t fAge;

};

#endif // __PERSON_CLASS_INCLUDED__