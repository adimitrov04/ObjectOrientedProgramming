#include <iostream>

using std::endl;

struct TimePeriod
{
    unsigned int hours, minutes, seconds;
};

void printLeadingZero (const unsigned int num)
{
    if (num < 10)
    {
        std::cout << '0' << num;
    }
    else
    {
        std::cout << num;
    }
}

void printTime (TimePeriod& time)
{
    printLeadingZero(time.hours);
    std::cout << ':';
    printLeadingZero(time.minutes);
    std::cout << ':';
    printLeadingZero(time.seconds);
}

void convertToValidFormat (TimePeriod& time)
{
    const int TIME_UNIT = 60;

    if (time.seconds >= TIME_UNIT)
    {
        time.minutes += (time.seconds / TIME_UNIT);
        time.seconds = time.seconds % TIME_UNIT;
    }

    if (time.minutes >= TIME_UNIT)
    {
        time.hours += (time.minutes / TIME_UNIT);
        time.minutes = time.minutes % TIME_UNIT;
    }
}

int main ()
{
    TimePeriod lapTime = {0, 59, 78};

    convertToValidFormat(lapTime);
    printTime(lapTime);

    return 0;
}