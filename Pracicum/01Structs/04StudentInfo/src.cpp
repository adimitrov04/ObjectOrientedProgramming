#include <iostream>
#include <cstring>
#include <new>
#include "Student.h"

const Student NO_ALLOCATION = { "ALLOC", "FAIL", 0 };

using std::endl;

int allocFail ()
{
    std::cerr << "Failed to allocate memory." << endl;
    return -69;
}

Student readStudentInfo ()
{
    Student student;

    std::cout << "Enter student first name: ";
    student.firstName = readName();
    if (!student.firstName)
        return NO_ALLOCATION;

    std::cout << "Enter student last name: ";
    student.lastName = readName();
    if (!student.lastName)
    {
        delete[] student.firstName;
        return NO_ALLOCATION;
    }
    
    std::cout << "Enter faculty number: ";
    student.facNumber = readFacNum();
    while (!student.facNumber)
    {
        std::cout << "Invalid fac. number.. try again:" << endl;
        student.facNumber = readFacNum();
    }

    return student;
}

int main ()
{
    int classSize = 0;
    std::cin >> classSize;

    Student* schClass = new (std::nothrow) Student[classSize];
    if (!schClass)
    {
        return allocFail();
    }

    std::cin.ignore();
    for (int i = 0; i < classSize; i++)
    {
        schClass[i] = readStudentInfo();
        if (schClass[i].firstName == NO_ALLOCATION.firstName && schClass[i].lastName == NO_ALLOCATION.lastName)
        {
            deleteStudents(schClass, i);
            return allocFail();
        }
        
        std::cout << endl;
    }

    for (int i = 0; i < classSize; i++)
    {
        printStudentInfo(schClass[i]);
        std::cout << endl;
    }

    deleteStudents(schClass, classSize);

    return 0;
}