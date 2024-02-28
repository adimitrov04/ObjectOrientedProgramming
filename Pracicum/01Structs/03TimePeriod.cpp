#include <iostream>

using std::endl;

const int TIME_UNIT = 60;

struct TimePeriod
{
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
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

TimePeriod findTimeDifference (const TimePeriod& time1, const TimePeriod& time2)
{
    int secs1 = convertToSeconds(time1);
    int secs2 = convertToSeconds(time2);

    int diffInSecs = std::abs(secs1 - secs2);
    TimePeriod diff = convertToTime(diffInSecs);
    convertToValidFormat(diff);

    return diff;
}

int main ()
{
    TimePeriod time1 = {0, 76, 33};
    convertToValidFormat(time1);
    printTime(time1); std::cout << endl;

    TimePeriod time2 = {1, 66, 0};
    convertToValidFormat(time2);
    printTime(time2); std::cout << endl;

    TimePeriod diff = findTimeDifference(time1, time2);
    printTime(diff); std::cout << endl;

    return 0;
}