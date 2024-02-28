#ifndef __STAR_STRUCT__
#define __STAR_STRUCT__

#include <iostream>
#include <fstream>

struct Star
{
    float x, y, z;
};

Star readStar (std::istream& inp);

float roundf (const float num, int places);

void printStar (const Star& inStar, std::ostream& dest, const int precision);

float findDistanceFromOrigin (const Star& star);

#endif //__STAR_STRUCT__