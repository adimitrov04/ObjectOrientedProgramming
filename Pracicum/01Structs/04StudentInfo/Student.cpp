#include <iostream>
#include "Student.h"

static int clamp (const int v, const int lo, const int hi)
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

bool validateName (const char* name)
{
    while(*name)
    {
        if (isdigit(*name) || *name == ' ')
            return false;

        name++;
    }

    return true;
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
        return nullptr;

    strcpy(pName, buffer);

    delete[] buffer;
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

void deleteStudentName (Student& target)
{
    delete[] target.firstName;
    delete[] target.lastName;
}

void deleteStudents (Student* studentArr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        deleteStudentName(studentArr[i]);
    }

    delete[] studentArr;
}