#include <iostream>

int main()
{
    char c = 0;
    for(char i=0; i<126; ++i)
        std::cout<<i<<" "<<i+c<<std::endl;
}
