#include <vector>
#include <list>
#include <iostream>

void printvector(const std::vector<int> &a)
{
    std::vector<int>::const_iterator it = a.begin();
    while(it != a.end())
    {
        std::cout<< *it <<std::endl;
        ++it;
    }
}

void printlist(const std::list<int> &a)
{
    std::list<int>::const_iterator it = a.begin();
    while(it != a.end())
    {
        std::cout<< *it <<std::endl;
        ++it;
    }
}


int main()
{
    printvector({2,3,4,2});
    printlist({2,3,4,2});

    return 0;
}
