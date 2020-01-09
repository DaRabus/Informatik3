#include "date.h"

Date::Date() :
    year(2000),
    month(1),
    day(1)
{
}

Date::Date(unsigned int y, unsigned int m, unsigned int d):
    year(y),
    month(m),
    day(d)
{
}

void Date::print()
{
    std::cout << year << "-" << month << "-" << day;
}

unsigned int Date::getYear()
{
    return year;
}

unsigned int Date::getMonth()
{
    return month;
}

unsigned int Date::getDay()
{
    return day;
}

void Date::setYear(unsigned int y)
{
    year = y;
}

void Date::setMonth(unsigned int m)
{
    month = m;
}

void Date::setDay(unsigned int d)
{
    day = d;
}

unsigned int Date::daysSince2000()
{
    unsigned int result = 0;
    // Handle years
    for (unsigned int y = 2000; y < year; y++)
    {
        result += 365;
        if (isLeapYear(y))
        {
            result++;
        }
    }
    // Handle months
    unsigned int daysPerMonth[] =
        {
//			Jan Feb Mar Apr May Jun
            31, 28, 31, 30, 31, 30,
//			Jul Aug Sep Oct Nov Dec
            31, 31, 30, 31, 30, 31
        };
    for (unsigned int m = 1; m < month; m++)
    {
        result += daysPerMonth[m - 1];
    }
    if ((month > 2) && isLeapYear(year))	// Leap year
    {
        result++;
    }
    // Handle days
    result+= day - 1;
    return result;
}

int Date::daysUntil(Date *d)
{
    return d->daysSince2000() - daysSince2000();
}

bool Date::isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
