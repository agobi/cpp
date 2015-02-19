#include <iostream>

void func(std::string s)
{
}

void kiir(const std::string &s)
{
    //s+="fa"; nem megy
    func(s); // s nem referencia, tehat meg lehet hivni
    std::cout<<'`'<<s<<'\''<<std::endl;
}

int main()
{
    std::string s="almafa";
    kiir(s);
}
