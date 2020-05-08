#include <iostream>
#include <fstream>
#include <list>
#include <string>

int main()
{
    std::ifstream input;
    input.open("../pruefung_file_reverse_line/input.txt" , std::ios_base::in); //open input file
    if (!input.is_open()) //check if it's open
    {
        std::cout << "Unable to open input file." << std::endl;
    }

    std::ofstream output("../pruefung_file_reverse_line/output.txt");  //open/create ouput file
    if(!output.is_open()){
        std::cout << "Unable to open output file." << std::endl;
    }
    std::list<std::string> inputlist;
    std::string txttostring;
    while (std::getline(input, txttostring, '\n'))    //get lines from input file
    {

        inputlist.emplace_front(txttostring);
        //std::cout << txttostring << std::endl;

    }
    for (std::list<std::string>::iterator it = inputlist.begin();
        it != inputlist.end(); it++)
    {
        std::cout << "    " <<  *it<< "\n";
        output << *it << "\n";
    }


}
