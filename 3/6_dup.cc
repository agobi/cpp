#include <vector>
#include <iostream>

template <typename T>
bool dup(T it, T end)
{
    for(;it != end; ++it)
    {
        T it2 = it;
        if(std::find(it2, end, *it) != end)
            return true;
    }

    return false;
}

int main()
{
    std::list<int> a = {2,4,3,1};
    std::cout<<(dup(a.begin(), a.end())?"Van":"Nincs")<<std::endl;

    return 0;
}
