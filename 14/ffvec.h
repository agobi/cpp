#ifndef FFVEC_H
#define FFVEC_H

#include <vector>
#include <algorithm>

//using namespace std;

template <typename T>
class full_fledged_vector: public std::vector<T>
{
public:
    full_fledged_vector()
    {}

    template<typename IT>
    full_fledged_vector(IT first, IT last)
        : std::vector<T>(first, last)
    {}

    void push_front(const T& value)
    {
        this->insert(this->begin(), value);
    }

    void pop_front()
    {
        this->erase(this->begin());
    }

    void sort()
    {
        std::sort(this->begin(), this->end());
    }

    template<typename F>
    void sort(F f)
    {
        std::sort(this->begin(), this->end(), f);
    }

    void unique()
    {
        this->erase(std::unique(this->begin(), this->end()), this->end());
        /*
        for(typename std::vector<T>::iterator it = this->begin(); it != this->end(); ++it)
        {
            typename std::vector<T>::iterator it2 = it;
            ++it2;
            while(it2 != this->end())
            {
                if(*it == *it2)
                    it2 = this->erase(it2);
                else
                    ++it2;
            }
        }
        */
    }

    void splice(typename std::vector<T>::iterator t,
        std::vector<T> &v,
        typename std::vector<T>::iterator v1,
        typename std::vector<T>::iterator v2)
    {
        this->insert(t, v1, v2);
        v.erase(v1, v2);
    }
};

#endif//FFVEC_H
