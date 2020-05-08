#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <stdexcept>

#include "letter_stats.h"

LetterStats::LetterStats()
{


     // tolower(it);
   //

}

void LetterStats::updateChar(char c)
{
    // TODO
}

void LetterStats::updateString(const std::string &str)
{
    // TODO
}

void LetterStats::updateFile(const std::string &filename)
{
    // Clear any input that existed previously
    letters.clear();
    std::ifstream file;
    file.open(filename , std::ios_base::in); //open input file
    if (!file.is_open()) //check if it's open
    {
        std::cout << "Unable to open input file." << std::endl;
    }

    std::string txttostring;
    while (std::getline(file, txttostring, '\n'))   //place words from dict to set Dictionary
    {
        if(!txttostring.empty()){
            //letters.emplace += txttostring;
            //std::cout << txttostring << std::endl;
            letters.emplace(txttostring);

        }
    }
    for(std::set<std::string>::iterator it = letters.begin(); it!=letters.end(); ++it){

    if((*it < 'A' || *it > 'Z') && (*it < 'a' || *it > 'z')) {
        letters.erase(*it);
        std::cout << *it << '\n';
    }
    }
}

void LetterStats::print()
{
    // TODO
}

