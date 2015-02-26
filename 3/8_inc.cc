#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator it,
           std::vector<int>::const_iterator end)
{
    for(;it != end; ++it)
        std::cout<< *it <<std::endl;
}

int main()
{
    std::vector<int> a = {2,3,4,5,6};

    /*
    for(auto it=a.begin(); it != a.end(); ++it)
    {
        int &value = *it;
        ++value;
    }
    */
    for(int &value : a)
        ++value;

    print(a.begin(), a.end());

    return 0;
};
