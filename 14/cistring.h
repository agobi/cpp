#ifndef CISTRING_H
#define CISTRING_H

#include <algorithm>
#include <locale>

template <typename T>
struct insensitive_eq: public std::binary_function<T, T, bool>
// bevezet egy rakas typedef-et ^^
// pl. second_argument_type
{
    bool operator () (T a, T b) const
    {
        return std::toupper(a) == std::toupper(b);
    }
};


template<typename C>
class case_insensitive_basic_string
{
    std::basic_string<C> _str;
    size_t index(typename std::basic_string<C>::const_iterator it) const
    {
        if(it == _str.end())
            return npos;
        else
            return it - _str.begin();
    }

public:
    const static size_t npos = std::basic_string<C>::npos;

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
        return index(std::find_if(_str.begin(), _str.end(), std::bind1st(insensitive_eq<C>(), c)));
    }

    size_t find(const std::basic_string<C> & c) const
    {
        return index(std::search(_str.begin(), _str.end(),
                    c.begin(), c.end(),
                    insensitive_eq<C>()));

    }

    size_t rfind(const std::basic_string<C> & c) const
    {
        typedef typename std::basic_string<C>::const_iterator it_type;
        it_type result = _str.end();

        for(it_type it = _str.begin(); it != _str.end();)
        {
            it = std::search(it+1, _str.end(), c.begin(), c.end(), insensitive_eq<C>());
            if (it != _str.end())
                result = it;
        }

        return index(result);
    }

    C& operator [] (size_t index)
    {
        return _str[index];
    }

    const C& operator [] (size_t index) const
    {
        return _str[index];
    }

    bool equal(const case_insensitive_basic_string& rhs) const
    {
        return std::equal(_str.begin(), _str.end(), rhs._str.begin(), insensitive_eq<C>());
    }

    bool equal(const std::basic_string<C>& rhs) const
    {
        return std::equal(_str.begin(), _str.end(), rhs.begin(), insensitive_eq<C>());
    }
};

typedef case_insensitive_basic_string<char> case_insensitive_string;

template<typename C>
bool operator == (const case_insensitive_basic_string<C> &a, const case_insensitive_basic_string<C> &b)
{
    return a.equal(b);
}

template<typename C>
bool operator == (const std::basic_string<C> &a, const case_insensitive_basic_string<C> &b)
{
    return b.equal(a);
}

template<typename C>
bool operator == (const case_insensitive_basic_string<C> &a, const std::basic_string<C> &b)
{
    return a.equal(b);
}

#endif//CISTRING_H
