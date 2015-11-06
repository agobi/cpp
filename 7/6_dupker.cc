#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "dupker.h"

int main()
{
    std::list<int> s;

    // Nem mukodik!!!!
    // Forward vs. Input iterator
    std::istream_iterator<int> res =
        dupker(std::istream_iterator<int>(std::cin),
               std::istream_iterator<int>());

    if(res != std::istream_iterator<int>())
        std::cout<<*res<<std::endl;

}
