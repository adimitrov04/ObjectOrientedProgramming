#ifndef __STUDENT_STRUCT__
#define __STUDENT_STRUCT__

struct Student
{
    char* firstName;
    char* lastName;

    int facNumber;
};

void printStudentInfo (const Student& target);

static bool validateName (const char* name);

static bool validateFacNum (const char* numStr);

char* readName ();

unsigned int readFacNum ();

#endif //__STUDENT_STRUCT__