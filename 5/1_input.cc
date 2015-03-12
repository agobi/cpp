#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template <typename T>
bool dup(T it, T end)
{
    for(;it != end; ++it)
    {
        T it2 = it;
        ++it2;
        if(std::find(it2, end, *it) != end)
            return true;
    }

    return false;
}

int main()
{
    /*
    std::istream_iterator<int> b(std::cin);
    std::istream_iterator<int> e;
    std::istream_iterator<int> b2 = b;
    while(b != e)
    {
        std::cout<< *b << " " << *b2 <<std::endl;
        ++b;
        ++b2;
    }
    */

    /*
    std::vector<int> v;
    std::istream_iterator<int> b(std::cin);
    std::istream_iterator<int> e;
    std::back_insert_iterator<std::vector<int>> output = std::back_inserter<int>(v);
    while(b != e)
    {
        *output = *b;
        ++b;
        ++output;
    }
    */

    std::vector<int> v;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter<std::vector<int>>(v));
    std::cout<<(dup(v.begin(), v.end())? "Van benne" : "Nincs")<<std::endl;
}
