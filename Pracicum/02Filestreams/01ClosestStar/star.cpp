#include <iostream>
#include <cmath>
#include "star.h"

Star readStar (std::istream& inp)
{
    Star input;
    inp >> input.x >> input.y >> input.z;

    return input;
}

void printStar (const Star& inStar, std::ostream& dest)
{
    dest << inStar.x << ", " << inStar.y << ", " << inStar.z;
}

float findDistanceFromOrigin (const Star& star)
{
    float dist = 0.0f;
    dist = sqrtf((star.x * star.x) + (star.y * star.y) + (star.z * star.z));

    return dist;
}