#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "dupker.h"

int main()
{
    std::list<int> s;

    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(s));

    std::copy(s.begin(),
              s.end(),
              std::ostream_iterator<int>(std::cout, "\n"));


}
