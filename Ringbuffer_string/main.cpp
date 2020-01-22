#include <iostream>
#include <list>
#include <string>



class RingBuffer
{
public:
    RingBuffer(size_t maxSize) : maxSize(maxSize)
    {
    }
    void add(const std::string &str)
    {
        data.push_back(str);
        while (data.size() > maxSize)
        {
            data.pop_front();
        }
    }
    void print()
    {
        std::string sep = "";
        for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++)
        {
            std::cout << sep << *it;
            sep = ",";
        }
    }
private:
    size_t maxSize;
    std::list<std::string> data;
};



int main()
{
    RingBuffer rb(5);
    rb.add("first");
    rb.add("second");
    rb.add("third");
    rb.add("forth");
    rb.add("fifth");
    rb.print();
    std::cout << std::endl;
}
