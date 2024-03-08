#include <iostream>
#include <cstring>
#include "Student.h"

static int clamp (const int v, const int lo, const int hi)
{
    if (v < lo)
        return lo;

    if (v > hi)
        return hi;

    return v;
}

static float clamp (const float v, const float lo, const float hi)
{
    if (v < lo)
        return lo;

    if (v > hi)
        return hi;

    return v;
}

void printStudentInfo (const Student& target)
{
    std::cout << "Student name: " << target.firstName << ' ' << target.lastName << std::endl;
    std::cout << "Faculty number: 0" << target.facNumber << std::endl;
}

void printGrade (const Grade& target)
{
    std::cout << "Subject: " << target.subject << std::endl;
    std::cout << "Grade: " << target.grade << std::endl;
}

void printPassedExams (const Student& target, const float passingGrade)
{
    std::cout << "Passed exams for " << target.firstName << ' ' << target.lastName << ':' << std::endl;

    int printed = 0;
    for (int i = 0; i < 3; i++)
    {
        if (target.gradeList[i].grade >= passingGrade)
        {
            printGrade(target.gradeList[i]);
            std::cout << std::endl;

            printed++;
        }
    }

    if (printed == 0)
        std::cout << "N/A" << std::endl;
}

static bool v_name (const char* name)
{
    while(*name)
    {
        if (isdigit(*name) || *name == ' ')
            return false;

        name++;
    }

    return true;
}

bool validateName (const char* name)
{
    return v_name(name);
}

static bool v_subject (const char* str)
{
    while (*str)
    {
        if (ispunct(*str) && *str != '-')
            return false;

        str++;
    }

    return true;
}

bool validateSubject (const char* str)
{
    return v_subject(str);
}

bool validateGrade (const float grade)
{
    if (grade == clamp(grade, 2.0f, 6.0f))
        return true;

    return false;
}

static bool validateFacNum (const char* numStr)
{
    const int LIMS[] = {100000, 999999};

    if (atoi(numStr) != clamp(atoi(numStr), LIMS[0], LIMS[1]))
        return false;

    return true;
}

char* readName (bool (*validation)(const char*), const int buff_len)
{
    char* buffer = new (std::nothrow) char[buff_len];
    if (!buffer)
        return nullptr;

    std::cin.getline(buffer, buff_len);
    while (!validation(buffer))
    {
        std::cerr << "Invalid name. Try again: ";
        std::cin.clear();
        std::cin.ignore(buff_len, '\n');

        std::cin.getline(buffer, buff_len);
    }
    
    char* pName = new (std::nothrow) char[strlen(buffer) + 1];
    if (!pName)
    {
        delete[] buffer;
        buffer = nullptr;

        return nullptr;
    }

    strcpy(pName, buffer);

    delete[] buffer;
    buffer = nullptr;

    return pName;
}

unsigned int readFacNum ()
{
    const int FAC_LEN = 8, STREAM_LEN = 500;
    char buffer[FAC_LEN] = { 0, };

    std::cin.getline(buffer, FAC_LEN);

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(STREAM_LEN, '\n');

        std::cout << "Invalid fac. number format.. Try again: " << std::endl;
        std::cin.getline(buffer, FAC_LEN);
    }

    if (validateFacNum(buffer))
    {
        return atoi(buffer);
    }
    else
    {
        return 0;
    }
}

bool readGrade (Grade& target, const int subjectNameLim)
{
    //std::cin.ignore();
    std::cout << "Subject name: ";
    target.subject = readName(validateSubject, subjectNameLim);
    //std::clog << "validation passed" << endl;
        
    if (!target.subject)
    {
        std::cerr << "Failed to allocate memory for grade name." << std::endl;
        return false;
    }

    //std::clog << "memory allocated successfully" << endl;
    std::cout << "Grade: ";
    std::cin >> target.grade;
    while (!validateGrade(target.grade))
    {
        std::cout << "Invalid grade value. Enter grade between 2 and 6: ";
        std::cin >> target.grade;
    }
    
    std::cin.ignore();
    return true;
}

// MEMORY DELETION FUNCTIONS

void deleteStudentName (Student& target)
{
    delete[] target.firstName;
    target.firstName = nullptr;
    
    delete[] target.lastName;
    target.lastName = nullptr;
}

void deleteGrades (const Student& target, const int amount)
{
    for (int i = 0; i < amount; i++)
    {
        delete[] target.gradeList[i].subject;
        target.gradeList[i].subject = nullptr;
    }
}

void deleteStudents (Student* studentArr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        deleteStudentName(studentArr[i]);
        deleteGrades(studentArr[i], 3);
    }

    delete[] studentArr;
    studentArr = nullptr;
}