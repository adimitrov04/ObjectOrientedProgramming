#ifndef __STUDENT_CLASS_INCLUDED__
#define __STUDENT_CLASS_INCLUDED__

#include <vector>
#include <cstdint>
#include "Person.h"
#include "Subject.h"

class Student : public Person
{

public:
    Student (const std::string name, const uint16_t age);

public:
    void Print (std::ostream& out = std::cout) const;

private:
    uint64_t fFacNum;
    std::string fSpecialty;
    std::vector<Subject> subjects;

};

#endif //__STUDENT_CLASS_INCLUDED__