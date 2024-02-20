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

void makeValidFormat (Distance& invalid)
{
    const int INCHES_IN_FEET = 12;

    invalid.feet += (invalid.inches / INCHES_IN_FEET);
    invalid.inches -= (invalid.inches - (invalid.inches % INCHES_IN_FEET));
}

Distance adds (Distance const& dist1, Distance const& dist2)
{
    Distance totalDist;
    totalDist.feet = dist1.feet + dist2.feet;
    totalDist.inches = dist1.inches + dist2.inches;

    makeValidFormat(totalDist);

    return totalDist;
}

int main ()
{
    Distance throwDist = {0, 49};
    Distance rollDist = {0, 11};

    Distance totalDist = adds(throwDist, rollDist);
    prints(totalDist);

    return 0;
}