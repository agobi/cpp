#include <string>
#include <iostream>

void func1(std::string q)
{
    q += "fa";
}

void func2(std::string &q)
{
    q += "fa";
}

int main()
{
    std::string s = "alma";

    func1(s);
    std::cout<<s<<std::endl;

    func2(s);
    std::cout<<s<<std::endl;
}
