#ifndef __STUDENT_STRUCT__
#define __STUDENT_STRUCT__

struct Grade
{
    char* subject;
    float grade;
};

struct Student
{
    char* firstName;
    char* lastName;

    int facNumber;
    Grade* gradeList;
};

void printStudentInfo (const Student& target);

void printGrade (const Grade& target);

void printPassedExams (const Student& target, const float passingGrade);

bool validateName (const char* name);

bool validateSubject (const char* str);

bool validateGrade (const float grade);

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

bool readGrade (Grade& target, const int subjectNameLim);

void deleteStudentName (Student& target);

void deleteGrades (const Student& target, const int amount);

void deleteStudents (Student* studentArr, const int size);

#endif //__STUDENT_STRUCT__