#include <cassert>
#include <iostream>
#include <string>

std::string break_lines(const std::string &str, size_t max_len)
{

assert(max_len > 0);
std::string input(str);
std::string output;
while (true)
{
if (input.size() <= max_len)
{
output += input;
return output;
}
else
{
int pos = max_len;
while ((pos >= 0) && (input.at(pos) != ' '))
{
pos--;
}
// This is the case that there is one word in str that is longer
// than max_len; we do not handle this case but stop the program
assert(pos >= 0);
// Append new line to output
output = output + input.substr(0, pos) + "\n";
// Remove this from input (including space)
input.erase(0, pos + 1);
}
}
}


void print_example(const std::string &str, size_t max_len)
{
    // Show marker indicating maximum line length
    for (size_t i = 0; i < max_len; i++)
        std::cout << " ";
    std::cout << "V" << std::endl;
    // Show result
    std::string result = break_lines(str, max_len);
    std::cout << result << std::endl;
}

void run_test_suite()
{
    assert(break_lines("", 1).compare("") == 0);
    assert(break_lines("0", 1).compare("0") == 0);
    assert(break_lines("01", 2).compare("01") == 0);
    assert(break_lines("0 23", 2).compare("0\n23") == 0);
    assert(break_lines("01 3", 2).compare("01\n3") == 0);
    assert(break_lines("1 3", 2).compare("1\n3") == 0);
    assert(break_lines("01 23", 2).compare("01\n23") == 0);
    assert(break_lines("01 23 45", 2).compare("01\n23\n45") == 0);
    assert(break_lines("01 23 45 67",  2).compare("01\n23\n45\n67") == 0);
    assert(break_lines("01 23 45 67",  3).compare("01\n23\n45\n67") == 0);
    assert(break_lines("01 23 45 67",  5).compare("01 23\n45 67") == 0);
    assert(break_lines("01 23 45 67",  6).compare("01 23\n45 67") == 0);
    assert(break_lines("01 23 45 67",  7).compare("01 23\n45 67") == 0);
    assert(break_lines("01 23 45 67",  8).compare("01 23 45\n67") == 0);
    assert(break_lines("01 23 45 67",  9).compare("01 23 45\n67") == 0);
    assert(break_lines("01 23 45 67", 10).compare("01 23 45\n67") == 0);
    assert(break_lines("01 23 45 67", 11).compare("01 23 45 67") == 0);
}

int main()
{
    print_example("Hello World! we love you so much", 7);

    //run_test_suite();
}
