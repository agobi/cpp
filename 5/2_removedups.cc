#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>

void
removedups(std::list<int> &v)
{
    std::list<int>::iterator a=v.begin();
    while(a != v.end())
    {
        std::list<int>::iterator b = a;
        ++b;
        while(b != v.end())
        {
            if(*a == *b)
                b = v.erase(b);
            else
                ++b;
        }
        ++a;
    }
}

int main()
{
    std::list<int> v;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter<std::list<int> >(v));
    removedups(v);
    std::copy(v.begin(), v.end(),
              std::ostream_iterator<int>(std::cout, "\n"));
}
