#include <iostream>
#include <vector>

void f(const int &x) {}
void g(int &x) {}

int main()
{
    int i;
    const int j = 2;
    f(i); // csak ez mukodne f(int&)-val
    f(i + 1);
    f(6);
    f(j);
    //j = 6;
    //g(j);
    i = j;
}
