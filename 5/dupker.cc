#include <iostream>
#include <vector>

template<typename T>
ssize_t
dupker(const std::vector<T> &s)
{
    for(size_t i = 0; i < s.size(); ++i)
        for(size_t j = i + 1; j < s.size(); ++j)
            if(s[i] == s[j])
                return i;
    return -1;
}

int main()
{
    std::vector<int> s = {2,3,4,2,6,4};

    // for(int i = 0; i < s.size(); ++i)
    // {
    // }
    //
    // {
    //   int i = 0;
    //   while (i < s.size())
    //   {
    //      ...
    //      ++i;
    //   }
    // }

    dupker(std::vector<int>({2,3,4}));
}
