#ifndef __TEACHER_CLASS_INCLUDED__
#define __TEACHER_CLASS_INCLUDED__

#include <vector>
#include "Person.h"
#include "Subject.h"
#include "Student.h"

class Teacher : public Person
{

public:
    Teacher (const std::string name, const int age, const Subject& subject);

    void Teach (Student& student);
    void Teach (const uint64_t studentFacNum);
    void Print (std::ostream& out = std::cout) const;

private:
    Subject fSubject;
    
};

#endif //__TEACHER_CLASS_INCLUDED__