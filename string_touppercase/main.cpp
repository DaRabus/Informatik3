#include <iostream>
#include <string>
#include <ctype.h>


int main()
{
    std::string str = "stuPid TiTLE oF my theSiS";

    std::cout << str << std::endl;

    bool makeUppercase = true;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ')
        {
            makeUppercase = true;
        }
        else
        {
            if (makeUppercase)
            {
                str[i] = toupper(str[i]);
                makeUppercase = false;
            }
            else
            {
                str[i] = tolower(str[i]);
            }
        }
    }

    std::cout << str << std::endl;
    return 0;
}
