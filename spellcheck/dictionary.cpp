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
    std::ifstream dict;
    dict.open(filename , std::ios_base::in); //open input file
    if (!dict.is_open()) //check if it's open
    {
        std::cout << "Unable to open dict file." << std::endl;
    }

    std::string txttostring;
    while (std::getline(dict, txttostring, '\n'))   //place words from dict to set Dictionary
    {
        if(!txttostring.empty()){
            words.emplace(txttostring);
            //std::cout << txttostring << std::endl;
        }
    }

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

    std::ofstream output(outFilename);  //open/create ouput file
    //output.open(outFilename , std::ios::app);
    if(!output.is_open()){
        std::cout << "Unable to open output file." << std::endl;;
    }

    std::string txttostring;
    while (std::getline(input, txttostring, ' '))    //get lines from input file
    {
        std::istringstream words(txttostring);
        std::string word;
        while (getline(words, word, ' '))       //get words from input file
        {

            std::string perfectwords = word;    //backup formated words
            //std::cout << perfectwords << std::endl ;
            normalizeWord(word);                //change words into format for check
            //std::cout << word  ;
            if(wordIsOkay(word) == true){       //check if words are in dictionary
                output << perfectwords << ' ';
            }
            else if(wordIsOkay(word) != true){  //if not change them to uppercase and write them in output file
                std::string perfectupper = toUppercase(word);
                //std::cout << word << std::endl ;
                output << perfectupper << ' ';
            }


        }}

}



bool Dictionary::wordIsOkay(const std::string &word)    //checks if string is in dict
{
    std::set<std::string>::iterator it;
    it = words.find((word));
    //bool search = words.find((word));
    if (it != words.end()){
        return true;
    }


    //std::cout << test << std::endl;
    return false;
    // Check if normalized word is in dictionary

}



std::string Dictionary::normalizeWord(std::string &word)
{
    // Remove everything from word that is not A-Z or a-z (e.g. spaces or '.' or ',')
    // and put everything in lowercase
    for (size_t i=0; i<= word.size(); i++){         //erase all the non letters
        if((word[i] < 'A' || word[i] > 'Z') && (word[i] < 'a' || word[i] > 'z')) {
            word.erase(i,1);
        }
    }

    for (size_t i=0; i<= word.size(); i++){ //check for capitals and stuff
        std::locale loc;
        if(std::isupper(word[i],loc) == true){
            //std::cout << word << std::endl;
            word[i] = word[i] + 32;
        }
    }

    //std::cout << word << std::endl;
    return word;
}



std::string Dictionary::toUppercase(const std::string &word)
{
    // Convert word into its UPPERCASE version
    std::string result;
    for (size_t i = 0; i < word.size(); i++)
    {
        result += word[i] - 32;

    }
    //std::cout << result << std::endl;
    return result;
}
