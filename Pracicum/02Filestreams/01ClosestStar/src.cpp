#include <iostream>
#include <fstream>
#include "star.h"

using std::endl;
using std::ifstream;
using std::ofstream;

const Star ORIGIN = {0.0f, 0.0f, 0.0f};

Star findClosestStar (const Star* stars, const unsigned int numberOfStars)
{
    if (!numberOfStars)
        return ORIGIN;

    Star closestStar = stars[0];
    float smallestDist = findDistanceFromOrigin(closestStar);

    for (int i = 0; i < numberOfStars; i++)
    {
        if (findDistanceFromOrigin(stars[i]) < smallestDist)
        {
            closestStar = stars[i];
            smallestDist = findDistanceFromOrigin(closestStar);
        }
    }

    return closestStar;
}

void outputMessage (const Star& starToPrint, std::ostream& dest)
{
    dest << "The closest star to us is located at (";
    printStar(starToPrint, dest);
    dest << ") that is " << findDistanceFromOrigin(starToPrint) << " light years away." << endl;
}

int main ()
{
    const int MAX_STARS = 64;
    Star stars[MAX_STARS];

    const int NAME_LEN = 32;
    char inputFileName[NAME_LEN] = { 0, };
    std::cin >> inputFileName;

    std::ifstream input;
    input.open(inputFileName);
    
    unsigned int numberOfStars = 0;
    input >> numberOfStars;
    std::cout << numberOfStars << endl;;

    for (int i = 0; i < numberOfStars; i++)
    {
        stars[i] = readStar(input);
    }

    input.close();

    Star closest = findClosestStar(stars, numberOfStars);
    float smallestDist = findDistanceFromOrigin(closest);

    ofstream out;
    out.open(inputFileName, std::ios_base::app);

    outputMessage(closest, out);
    out.close();

    return 0;
}