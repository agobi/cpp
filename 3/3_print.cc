#include <vector>
#include <list>
#include <iostream>

void print(std::vector<int>::const_iterator it,
           std::vector<int>::const_iterator end)
{
    for(;it != end; ++it)
        std::cout<< *it <<std::endl;
}

void print(std::list<int>::const_iterator it,
           std::list<int>::const_iterator end)
{
    for(;it != end; ++it)
        std::cout<< *it <<std::endl;
}


int main()
{
    {
        std::vector<int> a({2,3,4,2});
        print(a.begin(), a.end());
    }

    {
        std::list<int> a({2,3,4,2});
        print(a.begin(), a.end());
    }

    return 0;
}
