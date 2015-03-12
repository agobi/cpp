#include <iostream>
#include <vector>

std::vector<int>::iterator
logker(std::vector<int>::iterator first, std::vector<int>::iterator end, int needle)
{
    std::vector<int>::iterator last = end;
    while(first != last)
    {
        std::vector<int>::iterator it = first + (last - first)/2;
        if(*it < needle)
            first = it+1;
        else if(*it > needle)
            last = it;
        else return it;
    }
    return end;
}

int main()
{
    std::vector<int> x = {1,2,3,6,7,8};
    std::cout<<logker(x.begin(), x.end(), 6)-x.begin()<<std::endl;
}
