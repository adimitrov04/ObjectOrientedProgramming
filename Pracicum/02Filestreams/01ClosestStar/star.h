#ifndef __STAR_STRUCT__
#define __STAR_STRUCT__

#include <iostream>
#include <fstream>

struct Star
{
    float x, y, z;
};

Star readStar (std::istream& inp);

void printStar (const Star& inStar, std::ostream& dest);

float findDistanceFromOrigin (const Star& star);

#endif //__STAR_STRUCT__