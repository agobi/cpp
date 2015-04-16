#include <set>
#include <iostream>

int main()
{
    int i;
    // <
    std::set<int> data;
    while(std::cin>>i)
    {
        if(data.find(i) == data.end())
        {
            std::cout<<i<<std::endl;
            data.insert(i);
        }
    }
}
