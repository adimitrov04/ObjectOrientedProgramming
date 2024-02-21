#include <iostream>
#include <cstring>

using std::endl;

const char EXIT_CODE[] = "exit";

struct Student
{
    char* firstName;
    char* lastName;
    uint32_t facNumber;
};

bool isBetween (const int num, const int lowerLim, const int upperLim)
{
    return (num >= lowerLim && num <= upperLim);
}

void readStudentName (Student& student)
{
    const int CHAR_LIMIT = 256;
    char DEFAULT_LASTNAME[] = "?????";

    std::cout << "Enter student's first and last name: ";
    char firstName_buff[CHAR_LIMIT] = { 0, };
    std::cin.getline(firstName_buff, CHAR_LIMIT, ' ');

    student.firstName = new (std::nothrow) char[strlen(firstName_buff + 1)];
    if (!student.firstName)
        return ;

    strcpy(firstName_buff, student.firstName);

    std::cin.ignore();
    char lastName_buff[CHAR_LIMIT] = { 0, };
    std::cin.getline(lastName_buff, CHAR_LIMIT, ' ');
    
    student.lastName = new (std::nothrow) char[strlen(lastName_buff + 1)];
    if (!student.lastName)
    {
        student.lastName = DEFAULT_LASTNAME;
        return ;
    }

    strcpy(lastName_buff, student.lastName);
}

bool readFacultyNumber(Student& student)
{
    const int FAC_LENGTH = 8;
    
    char fn_buff[FAC_LENGTH] = { 0, };
    std::cin.getline(fn_buff, FAC_LENGTH, ' ');

    while (isBetween(atoi(fn_buff), 100000, 999999) == false)
    {
        if (strcmp(fn_buff, EXIT_CODE) == 0)
            return false;

        std::cerr << "Invalid faculty number. Please try again or type 'exit' to exit: " << endl;
        
        std::cin.ignore();
        std::cin.getline(fn_buff, FAC_LENGTH, ' ');
    }

    student.facNumber = atoi(fn_buff);
    return true;
}

void printInfo (const Student& student)
{
    std::cout << "Student name: " << student.firstName << ' ' << student.lastName << endl;
    std::cout << "Faculty number: 0" << student.facNumber << endl;
}

int main ()
{
    Student student;

    readStudentName(student);
    while (!student.firstName)
    {
        if (student.firstName == EXIT_CODE || student.lastName == EXIT_CODE)
            return 0;

        std::cerr << "The given name is invalid. Please try again or type 'exit' to exit: " << endl;
        readStudentName(student);
    }

    if (readFacultyNumber(student) == false)
        return 0;

    printInfo(student);

    return 0;
}