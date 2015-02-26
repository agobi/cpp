#include <vector>
#include <iostream>

bool dup(const std::vector<int> &a)
{
    for(size_t i = 0; i < a.size(); ++i)
        for(size_t j = i+1; j < a.size(); ++j)
            if(a[i] == a[j])
                return true;

    return false;
}

int main()
{
    std::vector<int> a = {2,4,3,1};
    std::cout<<(dup(a)?"Van":"Nincs")<<std::endl;

    /*
    if(dup(a))
        std::cout<<"Van"<<std::endl;
    else
        std::cout<<"Nincs"<<std::endl;
    */

    return 0;
}
