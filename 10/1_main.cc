#include <iostream>
#include "test.h"

int main()
{
    T &t = getT();
    std::cout<<f(t)<<std::endl;
    std::cout<<i<<std::endl;
}
