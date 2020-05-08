#include <iostream>

#include "letter_stats.h"

int main()
{
    try
    {
        LetterStats stats;
        stats.updateFile("../pruefung_letter_frequency/alice.txt");
        stats.print();

    }
    catch (std::exception &ex)
    {
        std::cout << "Something went wrong: " << ex.what() << std::endl;
    }
    return 0;
}
