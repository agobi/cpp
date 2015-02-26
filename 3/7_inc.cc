#include <iostream>
#include <vector>

void inc(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    for(;first!=last; ++first)
        ++(*first);
}

void print(std::vector<int>::const_iterator it,
           std::vector<int>::const_iterator end)
{
    for(;it != end; ++it)
        std::cout<< *it <<std::endl;
}

int main()
{
    std::vector<int> a = {2,3,4,5,6};
    inc(a.begin()+1, a.end());
    print(a.begin(), a.end());

    return 0;
};
