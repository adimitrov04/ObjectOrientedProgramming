#ifndef __STUDENT_STRUCT__
#define __STUDENT_STRUCT__

struct Student
{
    char* firstName;
    char* lastName;

    int facNumber;
};

void printStudentInfo (const Student& target);

bool validateName (const char* name);

/**
 * Read a cstring representing a name, with given validation criteria. (with exact length).
 * 
 * @param validation The validation function to be used for the name.
 * @param buff_len The length of the buffer used. Will determine the character limit.
 * 
 * @return A pointer to a dynamically set cstring with exact length. Must delete memory afterwards.
 */
char* readName (bool (*validation)(const char*), const int buff_len);

unsigned int readFacNum ();

void deleteStudentName (Student& target);

void deleteStudents (Student* studentArr, const int size);

#endif //__STUDENT_STRUCT__