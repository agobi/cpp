#include <iostream>

template <typename T>
const T&
min(const T &a, const T &b)
{
    return a<b?a:b;
}

template <typename T>
T&
min(T &a, T &b)
{
    return a<b?a:b;
}

int main()
{
    int i=2, j=3;
    std::cout<<min(2, j)<<std::endl;
    ++min(i, j);
    std::cout<<i<<" "<<j<<std::endl;
}
