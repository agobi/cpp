#include <iostream>

int main()
{
    int x[][2] = { {1,2}, {3,4}, {5,6} };
    //int * xx[];
    int (*xx)[2] = x+1;
    int * p = *xx;
    std::cout<<"4="<<(*xx)[1]<<" "<<p[1]<<std::endl;
}
