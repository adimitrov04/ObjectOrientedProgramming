#include <iostream>
#include <cstring>
#include <new>

using std::endl;

struct Student
{
    char* firstName;
    char* lastName;
    unsigned int facNumber;
};

bool isBetween (const int num, const int lowerLim, const int upperLim)
{
    return (num >= lowerLim && num <= upperLim);
}

int allocFail ()
{
    std::cerr << "Failed to allocate memory." << endl;
    return -69;
}

bool validateName (const char* str)
{
    while(*str)
    {
        if (isdigit(*str) || *str == ' ')
            return false;

        str++;
    }

    return true;
}

bool validateFacNum (const char* num)
{
    const int LIMS[] = {100000, 999999};

    if (isBetween(atoi(num), LIMS[0], LIMS[1]) == false)
        return false;

    return true;
}

char* readName ()
{
    const int CHAR_LIMIT = 256;
    char buffer[CHAR_LIMIT] = { 0, };

    std::cin.getline(buffer, CHAR_LIMIT);
    if (validateName(buffer))
    {
        char* pName = new (std::nothrow) char[strlen(buffer) + 1];
        strcpy(pName, buffer);

        return pName;
    }
    else
    {
        return nullptr;
    }
}

unsigned int readFacNum ()
{
    const int FAC_LEN = 8;
    char buffer[FAC_LEN] = { 0, };

    std::cin.getline(buffer, FAC_LEN);
    if (validateFacNum(buffer))
    {
        return atoi(buffer);
    }
    else
    {
        return 0;
    }
}

void printStudentInfo (const Student& student)
{
    std::cout << "Student name: " << student.firstName << ' ' << student.lastName << endl;
    std::cout << "Faculty number: 0" << student.facNumber << endl;
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
        student.facNumber = readFacNum();
    }

    printStudentInfo(student);

    return 0;
}