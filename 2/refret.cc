#include <iostream>
#include <string>

std::string &fun()
{
    std::string s = "almafa";
    return s;
    // nem definialt, s valtozo megszunik
    // dangling pointer
}

int main()
{
    std::cout<<fun()<<std::endl;
}
