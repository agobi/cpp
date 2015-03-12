#include <iostream>
#include <algorithm>
#include <iterator>

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
//    dup(std::istream_iterator<int>(cin), std::istream_iterator<int>());
//    ^^^ nem jo!


    std::istream_iterator<int> it = std::find(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), 2);
    // ^^^ ez jo, mert eleg az input iterator
    std::cout<<(it != std::istream_iterator<int>() ? "Van benne" : "Nincs")<<std::endl;
}
