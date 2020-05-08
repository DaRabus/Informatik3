#include <iostream>
#include <string>


std::string revert_string(std::string *str)
{
    std::string result;
    for (int i = str->size() - 1; i >= 0; i--)
    {
        result += str->at(i);
    }
    return result;
    std::cout << str << std::endl;
}



int main()
{
    std::string str = "olloH";

    std::cout << str << std::endl;
    std::cout << revert_string(&str) << std::endl;

    if (str.compare(revert_string(&str)) == 0)
    {
        std::cout << "It's a palindrome!" << std::endl;
    }
    else
    {
        std::cout << "It's not a palindrome!" << std::endl;
    }

    return 0;
}
