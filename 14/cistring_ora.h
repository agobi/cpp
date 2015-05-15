#ifndef CISTRING_H
#define CISTRING_H

#include <algorithm>
#include <locale>

template <typename T>
struct insensitive_match
{
    T _c;

    insensitive_match(T c)
        : _c(std::toupper(c))
    {}

    bool operator () (T t)
    {
        return std::toupper(t) == _c;
    }
};

template <typename T>
struct insensitive_compare
{
    bool operator () (T a, T b)
    {
        return std::toupper(a) == std::toupper(b);
    }
};


template<typename C>
class case_insensitive_basic_string
{
    std::basic_string<C> _str;

public:
    size_t size() const
    {
        return _str.size();
    }

    void push_back(C c)
    {
        _str.push_back(c);
    }

    size_t find(C c) const
    {
        typename std::basic_string<C>::const_iterator it = std::find_if(_str.begin(), _str.end(), insensitive_match<C>(c));

        if(it == _str.end())
            return _str.npos;
        else
            return it - _str.begin();
    }

    size_t find(const std::basic_string<C> & c) const
    {
        typename std::basic_string<C>::const_iterator it =
            std::search(_str.begin(), _str.end(),
                    c.begin(), c.end(),
                    insensitive_compare<C>());

        if(it == _str.end())
            return _str.npos;
        else
            return it - _str.begin();
    }
};

#endif//CISTRING_H
