#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "dupker.h"

int main()
{
    std::list<int> s;
    //std::back_insert_iterator<std::list<int>> oit = std::back_inserter(s);

    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(s));

    std::vector<int> v(s.size());
    std::copy(s.begin(), s.end(), v.begin());
/*    std::list<int>::iterator iit = s.begin();
    std::vector<int>::iterator oit = v.begin();
    while(iit != s.end())
        *oit++ = *iit++;*/

    std::list<int>::iterator res = dupker(s.begin(), s.end());
    if(res != s.end())
        std::cout<<*res<<std::endl;
}
