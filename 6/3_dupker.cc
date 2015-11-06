#include <iostream>
#include <vector>
#include <list>

template<typename T>
ssize_t
dupker(const std::vector<T> &s)
{
    for(size_t i = 0; i != s.size(); ++i)
        for(size_t j = i + 1; j != s.size(); ++j)
            if(s[i] == s[j])
                return i;
    return -1; // extremalis
}

template<typename T>
typename std::list<T>::iterator
dupker(std::list<T> &s)
{
    for(typename std::list<T>::iterator i = s.begin(); i != s.end(); ++i)
    {
        typename std::list<T>::iterator j = i;
        for(++j; j != s.end(); ++j)
        {
            if(*i == *j)
                return i;
        }
    }
    return s.end();
}

int main()
{
    dupker(std::vector<int>({2,3,4,2}));
    std::list<int> s({2,3,4,2});
    for(std::list<int>::iterator it = dupker(s); it != s.end(); it = dupker(s))
    {
        ++*it;
    }
/*
    for(std::list<int>::iterator it = s.begin(); it != s.end(); ++it);
    {
        int &v = *it;
        std::cout<<v<<std::endl;
    }
    */

    for(int & v : s)
    {
        std::cout<<v<<std::endl;
    }

//    for(;;);
}
