#include <vector>
#include <iostream>

bool dup(std::vector<int>::const_iterator it,
         std::vector<int>::const_iterator end)
{
    for(;it != end; ++it)
    {
        std::vector<int>::const_iterator it2 = it;
        if(std::find(it2, end, *it) != end)
            return true;
    }

    return false;
}

int main()
{
    std::vector<int> a = {2,4,3,1};
    std::cout<<(dup(a.begin(), a.end())?"Van":"Nincs")<<std::endl;

    return 0;
}
