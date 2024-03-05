#include <iostream>
#include <cstring>
#include <new>
#include "Student.h"

const Student NO_ALLOCATION = { "ALLOC", "FAIL", 0 };
const int STUDENT_NAME_LIMIT = 256;
const int SUBJECT_NAME_LIMIT = 33;
const int NUMBER_OF_GRADES = 3;

using std::endl;

int allocFail ()
{
    std::cerr << "Failed to allocate memory." << endl;
    return -69;
}

Student readStudentInfo ()
{
    Student student;

    // Read names
    std::cin.ignore();

    std::cout << "Enter student first name: ";
    student.firstName = readName(validateName, STUDENT_NAME_LIMIT);
    if (!student.firstName)
    {
        return NO_ALLOCATION;
    }

    std::cout << "Enter student last name: ";
    student.lastName = readName(validateName, STUDENT_NAME_LIMIT);
    if (!student.lastName)
    {
        delete[] student.firstName;
        return NO_ALLOCATION;
    }
    
    // Read faculty number
    std::cout << "Enter faculty number: ";
    student.facNumber = readFacNum();
    while (!student.facNumber)
    {
        std::cout << "Invalid fac. number.. try again:" << endl;
        student.facNumber = readFacNum();
    }

    // Read grades
    std::cout << endl << "Enter " << NUMBER_OF_GRADES << " subjects and the student's grade for them: " << endl;
    for (int i = 0; i < NUMBER_OF_GRADES; i++)
    {
        std::cout << "Subject #" << i + 1 << " name: ";
        
        std::cin.ignore();
        student.gradeList[i].subject = readName(validateSubject, SUBJECT_NAME_LIMIT);
        std::clog << "validation passed" << endl;
        
        if (!student.gradeList[i].subject)
        {
            std::clog << "in allocfail scenario" << endl;
            deleteStudentName(student);
            deleteGrades(student, i);

            std::cerr << "Failed to allocate memory for grade name." << endl;
            return NO_ALLOCATION;
        }

        std::clog << "memory allocated successfully" << endl;
        
        std::cout << "Grade: ";
        std::cin >> student.gradeList[i].grade;
        while (!validateGrade(student.gradeList[i].grade))
        {
            std::cout << "Invalid grade value. Enter grade between 2 and 6: ";
            std::cin >> student.gradeList[i].grade;
            std::cin.ignore();
        }
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
        if (!strcmp(schClass[i].firstName, NO_ALLOCATION.firstName) && !strcmp(schClass[i].lastName, NO_ALLOCATION.lastName))
        {
            deleteStudents(schClass, i);
            return allocFail();
        }
        
        std::cout << endl;
    }

    float passingGrade = 0.0f;
    std::cout << "Enter passing grade: ";
    std::cin >> passingGrade;
    std::cout << endl;

    for (int i = 0; i < classSize; i++)
    {
        printPassedExams(schClass[i], passingGrade);
    }

    deleteStudents(schClass, classSize);
    return 0;
}