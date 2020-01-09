#include <iostream>
#include <list>
#include <string>

void join_string(std::list<std::string> *lst, char separator_char, std::string *str)
{
    str->clear();
    std::string separator_str = "";
    // Iterate over list of strings
    for (std::list<std::string>::iterator it = lst->begin(); it != lst->end(); it++)
    {
        // We want to prepend the separator every time except the first time;
        // Here it is handled by initializing separator_str after using it the first time
        *str += separator_str;
        separator_str = separator_char;
        *str += *it;
    }
}

void split_string(std::string *str, char separator_char, std::list<std::string> *lst)
{
    lst->clear();
    std::string currentWord = "";
    // Process input string char by char
    for (size_t i = 0; i < str->size(); i++)
    {
        if (str->at(i) != separator_char)
        {
            // No separator: Just add to current line
            currentWord += str->at(i);
        }
        else
        {
            // Separator: Put current line to result list ...
            lst->push_back(currentWord);
            // ... and reset current line
            currentWord.clear();
        }
    }
    // If there is something left in the current line ...
    if (!currentWord.empty())
    {
        // ... flush it to the result list
        lst->push_back(currentWord);
    }
}

int main()
{
    std::list<std::string> in_lst =
        { "first", "second", "third", "fourth" };
    std::cout << "Input is a list with " << in_lst.size()
        << " entries:" << std::endl;
    for (std::list<std::string>::iterator it = in_lst.begin();
        it != in_lst.end(); it++)
    {
        std::cout << "    " << *it << "\n";
    }
    std::string out_str;
    join_string(&in_lst, ';', &out_str);
    std::cout << "Joined string: " << out_str << std::endl;

    std::cout << std::endl;

    std::string in_str = "first.second.third.fourth";
    std::cout << "Input string: " << in_str << std::endl;
    std::list<std::string> out_lst;
    split_string(&in_str, '.', &out_lst);
    std::cout << "Output is a list with " << out_lst.size()
        << " entries:" << std::endl;
    for (std::list<std::string>::iterator it = out_lst.begin();
        it != out_lst.end(); it++)
    {
        std::cout << "    " << *it << "\n";
    }
}
