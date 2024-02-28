#include <iostream>
#include <cstring>
#include <new>
#include "Student.h"

using std::endl;

int allocFail ()
{
    std::cerr << "Failed to allocate memory." << endl;
    return -69;
}

int main ()
{
    Student student;

    std::cout << "Enter student first name: ";
    student.firstName = readName();
    if (!student.firstName)
        return allocFail();

    std::cout << "Enter student last name: ";
    student.lastName = readName();
    if (!student.lastName)
    {
        delete[] student.firstName;
        return allocFail();
    }
    
    std::cout << "Enter faculty number: ";
    student.facNumber = readFacNum();
    while (student.facNumber == 0)
    {
        std::cout << "Invalid fac. number. Try again: " << endl;
        
        std::cin.clear();
        std::cin.ignore(500,'\n');
        student.facNumber = readFacNum();
    }

    printStudentInfo(student);

    delete[] student.firstName;
    delete[] student.lastName;

    return 0;
}