#ifndef __STUDENT_CLASS_INCLUDED__
#define __STUDENT_CLASS_INCLUDED__

#include <vector>
#include <cstdint>
#include "Person.h"
#include "Subject.h"

class Student : public Person
{

public:
    Student (const std::string name, const int age);

public:
    void Print (std::ostream& out = std::cout) const;

private:
    int fFacNum;
    std::vector<Subject> subjects;

};

#endif //__STUDENT_CLASS_INCLUDED__