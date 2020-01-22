#include <iostream>
#include <fstream>

int main()
{
    std::ifstream unchangenddocument;
    unchangenddocument.open("../decommend/with_comments.cpp" , std::ios_base::in); //open input file
    if (!unchangenddocument.is_open()) //check if it's open
    {
        std::cout << "Unable to open input file." << std::endl;
    }
    std::ofstream outcomment("../decommend/without_comments.cpp");  //open/create ouput file
    if(!outcomment.is_open()){
        std::cout << "Unable to open output file." << std::endl;;
    }

    std::string lines;
    std::string comment = "//";

    while (std::getline(unchangenddocument, lines, '\n'))    //get lines from input file
    {
    std::size_t found = lines.find(comment);
       if(found!=std::string::npos){ //look for the comments
           lines.replace(lines.find(comment),lines.length(), ""); // replace the Comment with a space
       }
       std::cout << lines << std::endl; // print out the outcomment stuff.

       outcomment << lines << "\n";

    }

}
/* Musterlösung
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream inFile("with_comments.cpp");
    if (!inFile.is_open())
    {
        std::cout << "Error opening input file" << std::endl;
        return -1;
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        size_t found = line.find("//");
        if (found != std::string::npos)
        {
            line = line.substr(0, found);
            if (!line.empty())
            {
                std::cout << line << std::endl;
            }
        }
        else
        {
            std::cout << line << std::endl;
        }
    }
    return 0;
}
/*
