#include <iostream>
#include <vector>
#include <list>
#include "dupker.h"

int main()
{
    std::list<int> s;

    int i;
    //(std::cin >> i) >> j;
    //for(std::cin >> i; std::cin.good(); std::cin >> i) {}
    while(std::cin >> i)
        s.push_back(i);

    std::list<int>::iterator res = dupker(s.begin(), s.end());
    if(res != s.end())
        std::cout<<*res<<std::endl;
}
