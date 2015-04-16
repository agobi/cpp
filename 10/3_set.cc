#include <unordered_set>
#include <iostream>

int main()
{
    int i;
    // kell ==
    std::unordered_set<int> data;
    while(std::cin>>i)
    {
        if(data.find(i) == data.end())
        {
            std::cout<<i<<std::endl;
            data.insert(i);
        }
    }
}
