#include <iostream>

void
swap2(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void
swap2(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
int
min(int a, int b)
{
    return a<b?a:b;
}
*/

template <typename T>
const T&
min(const T &a, const T &b)
{
    return a<b?a:b;
}



int main()
{
    int i=2, j=3;
    swap2(i, j);

    std::cout<<min(i, 0)<<std::endl;
}
