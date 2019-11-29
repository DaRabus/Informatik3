#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <locale>

#include "dictionary.h"



Dictionary::Dictionary()
{
}



void Dictionary::loadFromFile(const std::string &filename)
{
    // Clear any input that existed previously
    words.clear();
    // Open input file and check if it exists

    // TODO

    // Read file line by line: each line contains one word

    // TODO

    std::cout << "Number of words in dictionary: " << words.size() << std::endl;
}



void Dictionary::checkFile(const std::string &inFilename, const std::string &outFilename)
{
    std::ifstream input;
    input.open(inFilename , std::ios_base::in); //open input file
    if (!input.is_open()) //check if it's open
    {
        std::cout << "Unable to open input file." << std::endl;
    }

    std::ofstream output(outFilename);
    //output.open(outFilename , std::ios::app);
    if(!output.is_open()){
        std::cout << "Unable to open output file." << std::endl;;
    }

    std::string txttostring;
    while (std::getline(input, txttostring))
    {
        std::istringstream words(txttostring);
        std::string word;
        while (getline(words, word, ' '))
        {
            normalizeWord(word);
            //std::cout << word  ;
            if(wordIsOkay(word) == true){

                output << word << ' ';
            }


        }}

}



bool Dictionary::wordIsOkay(const std::string &word)
{
    //std::cout << word << std::endl;
    // Check if normalized word is in dictionary

    // TODO

    return true;
}



std::string Dictionary::normalizeWord(std::string &word)
{
    // Remove everything from word that is not A-Z or a-z (e.g. spaces or '.' or ',')
    // and put everything in lowercase
    for (size_t i=0; i<= word.size(); i++){
        if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')) {
            //std::cout << word[i] << std::endl;
            std::locale loc;
            if(std::isupper(word[i],loc) == true){
                word[i] = word[i] + 32;
            }

        }

    }
    return word;
}



std::string Dictionary::toUppercase(const std::string &word)
{
    // Convert word into its UPPERCASE version
    std::string result;
    for (size_t i = 0; i < word.size(); i++)
    {
        result += std::toupper(word[i]);
    }
    return result;
}
