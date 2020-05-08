#include <iostream>
#include <list>
#include <iterator> // for iterators
#include <string>

using namespace std;

void join_string(list<string> *lst, char separator_char, string *str)
{
    unsigned int counter = 0;
for(list<string>::iterator opswitch = lst->begin(); opswitch != lst->end(); opswitch++)
{

    counter++; //Increase Counter for every single word
    *str += *opswitch; //Put words together
    if(counter != lst->size()){ //Add seperator Char
        *str += separator_char;
    }
    }
}


void split_string(string *str, char separator_char, list<string> *lst)
{

//for(list<string>::iterator opswitch = lst->begin(); opswitch != check; opswitch++){
//}
    size_t current, previous = 0;
    current = str->find_first_of(separator_char);
    while(current != std::string::npos){
    lst->push_back(str->substr(previous , current - previous));
    previous = current +1;
    current = str->find_first_of(separator_char,previous);

    }
    lst->push_back(str->substr(previous,current-previous));


}

int main()
{
    list<string> in_lst = //Construction List of Strings
        { "first", "second", "third", "fourth" };

    cout << "Input is a list with " << in_lst.size() //Printing out the Size of the List
        << " entries:" << endl;


    for (list<string>::iterator it = in_lst.begin(); it != in_lst.end(); it++) //for Loop for printing out the entrys
    {
        cout << "    " << *it << "\n";
    }

    string out_str;

    join_string(&in_lst, ';', &out_str);

    cout << "Joined string: " << out_str << endl;

    cout << endl;

    string in_str = "first.second.third.fourth";

    cout << "Input string: " << in_str << endl; //Printing out the Input String

    list<string> out_lst; //Creating the List for seperated strings

    split_string(&in_str, '.', &out_lst); //Separator between words

    cout << "Output is a list with " << out_lst.size() //Count the size of the new list
        << " entries:" << endl;

    for (list<string>::iterator it = out_lst.begin();it != out_lst.end(); it++) //Print out the seperated strings
    {
        cout << "    " << *it << "\n";
    }
}
