#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>     /* strtod */
#include <string>
#include <algorithm>

using namespace std;

int parse_numbers_no_error_handling(const char *str, double *values, size_t n)
{
    char *ptr = (char *)str;
    for (size_t i = 0; i < n; i++)
    {
        values[i] = strtod(ptr, &ptr);
        ptr++;
    }
    return 1;
}

int parse_numbers(const char *str, double *values, size_t n)
{
    const char *start = str;
        char *end = NULL;
        for (size_t i = 0; i < n; i++)
        {
            values[i] = strtod(start, &end);
            // Next block could not be parsed
            if (start == end)
            {
                return 0;
            }
            // Separator char between numbers should be ','
            if ((i < (n - 1)) && (*end != ','))
            {
                return 0;
            }
            // Unexpected end of string
            if ((i == (n - 1)) && (*end != '\0'))
            {
                return 0;
            }
            start = end + 1;
        }
        return 1;
}

int main()
{
    char *string = "-12.2,45.6,23.2";
    size_t n = 3;
    double values[n];
//	if (parse_numbers_no_error_handling(string, values, n))
    if (parse_numbers(string, values, n))
    {
        for (size_t i = 0; i < n; i++)
        {
            printf("%f\n", values[i]);
        }
    }
    else
    {
        printf("Parse error.\n");
    }
    return 0;
}
