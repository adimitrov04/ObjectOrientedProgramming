#include <iostream>

using std::endl;

struct Distance
{
    int feet = 0.0f;
    int inches = 0.0f;
};

void prints (Distance dist)
{
    std::cout << dist.feet << '\'' << dist.inches << '\"' << endl;;
}

Distance adds (Distance const& dist1, Distance const& dist2)
{
    const int inchesInFeet = 12;
    
    Distance totalDist;
    totalDist.feet = dist1.feet + dist2.feet;
    totalDist.inches = dist1.inches + dist2.inches;

    while (totalDist.inches >= inchesInFeet)
    {
        totalDist.feet++;
        totalDist.inches -= inchesInFeet;
    }

    return totalDist;
}

int main ()
{
    Distance throwDist = {10, 5};
    Distance rollDist = {1, 7};

    Distance totalDist = adds(throwDist, rollDist);
    prints(totalDist);

    return 0;
}