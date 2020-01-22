#include <iostream>
#include <string>


int main()
{
    std::string str = "It's a trap! Really, a trap!";
    std::string search_str = "trap";
    std::string replace_str = "surprise";

    std::cout << str << std::endl;
    while (true)
    {
        size_t pos = str.find(search_str);
        if (pos == std::string::npos)
        {
            break;
        }
        str.erase(pos, search_str.size());
        str.insert(pos, replace_str);
    }
    std::cout << str << std::endl;

    return 0;
}
