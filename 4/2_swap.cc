#include <iostream>

void swap(int &a, int &b)
{
    // a ^= b
    // b ^= a;
    // a ^= b;
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a=5, b=9;
    swap(a, b);
    std::cout<<a<<" "<<b<<std::endl;

    int j = a;
    j = 42;
    int &r = a;
    r = 137;


}
