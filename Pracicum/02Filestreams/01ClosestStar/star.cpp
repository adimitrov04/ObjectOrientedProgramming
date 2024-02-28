#include <iostream>
#include <cmath>
#include "star.h"

Star readStar (std::istream& inp)
{
    Star input;
    inp >> input.x >> input.y >> input.z;

    return input;
}

float roundf (const float num, int places)
{
    int converter = 0;
    float factor = (powf(10.0f, static_cast<float>(places)));
    
    converter = num * factor;

    return static_cast<float>(converter / factor);
}

void printStar (const Star& inStar, std::ostream& dest, const int precision = 2)
{
    dest << roundf(inStar.x, precision) << ", " << roundf(inStar.y, precision) << ", " << roundf(inStar.z, precision);
}

float findDistanceFromOrigin (const Star& star)
{
    float dist = 0.0f;
    dist = sqrtf((star.x * star.x) + (star.y * star.y) + (star.z * star.z));

    return dist;
}