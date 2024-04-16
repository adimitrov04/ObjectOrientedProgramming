#ifndef __UNIVERSITY_CLASS_INCLUDED__
#define __UNIVERSITY_CLASS_INCLUDED__

#include <vector>
#include "Student.h"
#include "Teacher.h"

class University
{

public:
    const Student& GetStudent(const uint64_t facultyNumber) const;

    void Add (const Student& student);
    void Add (const Teacher& teacher);

private:
    std::vector<Student> students; 
    std::vector<Teacher> teachers; 

    uint64_t totalStudentsAllTime;
    
};

#endif //__UNIVERSITY_CLASS_INCLUDED__