#include <iostream>
#include <string>

void string_reverse(std::string &str)
{
    std::string result;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        result += str.at(i);
    }
    str = result;

    //std::cout << result << std::endl;
}

int main()
{
    std::string str = "!dlroW olleH";
    string_reverse(str);
    std::cout << str << std::endl;


}

