#include <string>
#include <iostream>

int main()
{
    std::string s = "alma";
    std::string t = "korte";
    std::string &s2(s); // s2 = s; initialization

    s2 += "fa";

    std::cout<<s<<std::endl;

    s2 = t; // assignment
    std::cout<<s<<std::endl;
}
