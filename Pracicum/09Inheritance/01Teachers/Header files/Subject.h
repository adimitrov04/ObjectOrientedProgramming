#ifndef __SUBJECT_STRUCT_INCLUDED__
#define __SUBJECT_STRUCT_INCLUDED__

#include <string>

struct Subject
{
    Subject(const std::string name, const int level)
    {
        fName = name;
        fLevel = level;
    }

    std::string fName;
    int fLevel;
};

#endif //__SUBJECT_STRUCT_INCLUDED__