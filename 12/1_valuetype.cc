#include <iostream>
#include "list.h"
#include "min.h"

int main()
{
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_back(1);
    std::cout<<minimum(l.begin(), l.end())<<std::endl;
}
