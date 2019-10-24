#include <iostream>
#include <list>
#include <iterator> // for iterators
#include <string>

using namespace std;

void join_string(list<string> *lst, char separator_char, string *str)
{
    list<string>::const_iterator opswitch;

for(opswitch = lst->begin(); opswitch != lst->end(); opswitch++)
{

    *str->insert(*str->begin(),*lst)
       if (lst != lst->end() - 1){
         *str + separator_char;
    }

}
}


void split_string(string *str, char separator_char, list<string> *lst)
{
    // TODO
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

    for (list<string>::iterator it = out_lst.begin(); //Print out the seperated strings
        it != out_lst.end(); it++)
    {
        cout << "    " << *it << "\n";
    }
}
