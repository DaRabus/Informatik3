/*****************************
  * Rabus Dominik *
  * FHGR *
  * 23. 01 2020 *
  * Pruefung *
 ******************************/

#include <iostream>
#include <list>


int main(){
    std::list<int> values = {1,2,3,4,5};
    int sum = 0;
    for (std::list<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        sum += *it;
    }
    std::cout << "Sum is " << sum << std::endl;
    return 0;
}
