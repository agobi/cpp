#include <iostream>
#include <vector>
#include <list>

template<typename IT>
IT
dupker(IT begin, IT end)
{
    for(IT i = begin; i != end; ++i)
    {
        IT j = i;
        for(++j; j != end; ++j)
        {
            if(*i == *j)
                return i;
        }
    }
    return end;
}

int main()
{
    std::vector<int> v({2,3,4,2});
    std::cout<<*dupker(v.begin(), v.end())<<std::endl;

    std::list<int> s({2,3,4,2});
    std::cout<<*dupker(s.begin(), s.end())<<std::endl;
}
