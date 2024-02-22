#include <iostream>

using std::endl;

const int TIME_UNIT = 60;

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

void printTime (const TimePeriod& time)
{
    printLeadingZero(time.hours);
    std::cout << ':';
    printLeadingZero(time.minutes);
    std::cout << ':';
    printLeadingZero(time.seconds);
}

void convertToValidFormat (TimePeriod& time)
{
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

int convertToSeconds (const TimePeriod& time)
{
    int seconds = (time.hours * (TIME_UNIT * TIME_UNIT)) + (time.minutes * TIME_UNIT) + time.seconds;
    return seconds;
}

TimePeriod convertToTime (const int seconds)
{
    TimePeriod time;

    time.hours = 0;
    time.minutes = (seconds / TIME_UNIT);
    time.seconds = (seconds % TIME_UNIT);

    return time;
}

int main ()
{
    TimePeriod time1 = {0, 59, 2};
    TimePeriod time2 = {5, 44, 6};

    return 0;
}