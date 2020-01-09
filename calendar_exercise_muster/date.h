#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>

class Date
{
public:
    Date();
    Date(unsigned int y, unsigned int m, unsigned int d);

    void print();

    unsigned int getYear();
    unsigned int getMonth();
    unsigned int getDay();

    void setYear(unsigned int y);
    void setMonth(unsigned int m);
    void setDay(unsigned int d);

    unsigned int daysSince2000();
    int daysUntil(Date *d);

private:
    static bool isLeapYear(int year);
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

#endif	// _DATE_H_
