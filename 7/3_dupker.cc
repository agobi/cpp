#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "dupker.h"

int main()
{
    std::list<int> s;

    for(std::istream_iterator<int> it(std::cin);
            it != std::istream_iterator<int>();
            ++it)
    {
        s.push_back(*it);
    }

    std::list<int>::iterator res = dupker(s.begin(), s.end());
    if(res != s.end())
        std::cout<<*res<<std::endl;
}
