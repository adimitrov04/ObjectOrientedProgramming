#include <iostream>
#include <fstream>
#include <iomanip>
#include "star.h"

using std::endl;
using std::ifstream;
using std::ofstream;

const Star ORIGIN = {0.0f, 0.0f, 0.0f};
const int GLOBAL_PRECISION = 2;
const int NO_OPEN = -257;

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
    dest << std::fixed;
    dest << "The closest star to us is located at (";
    printStar(starToPrint, dest, GLOBAL_PRECISION);
    dest << std::setprecision(GLOBAL_PRECISION) << ") that is " << findDistanceFromOrigin(starToPrint) << " light years away." << endl;
}

int main ()
{
    const int MAX_STARS = 64;
    Star stars[MAX_STARS];

    const int NAME_LEN = 32;
    char inputFileName[NAME_LEN] = { 0, };
    std::cin >> inputFileName;

    // Read input from file
    std::ifstream input;
    input.open(inputFileName);
    if (!input)
    {
        std::cerr << "Failed to open file for reading. Terminating..." << endl;
        return NO_OPEN;
    }
    
    unsigned int numberOfStars = 0;
    input >> numberOfStars;

    for (int i = 0; i < numberOfStars; i++)
    {
        stars[i] = readStar(input);
    }

    input.close();

    // Write output in file
    Star closest = findClosestStar(stars, numberOfStars);
    float smallestDist = findDistanceFromOrigin(closest);

    ofstream out;
    out.open(inputFileName, std::ios_base::app);

    outputMessage(closest, out);
    out.close();

    return 0;
}