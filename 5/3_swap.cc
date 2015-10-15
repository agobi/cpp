#include <iostream>
#include <vector>

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<>
void swap(std::vector<int> &a, std::vector<int> &b)
{
    a.swap(b);
}

// int f(double); f(5);
// int f(double &); int i; f(i);

int main()
{
    int i = 6, j = 42;
    swap(i, j);
    std::cout<<i<<" "<<j<<std::endl;

    double ir = 3.14, jr = 42;
    swap(ir, jr);
    std::cout<<ir<<" "<<jr<<std::endl;

    //swap(i, ir);
    return 0;
}
