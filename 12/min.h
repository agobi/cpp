#ifndef MIN_H
#define MIN_H

template<typename IT>
typename IT::value_type
minimum(IT first, IT last)
{
    typename IT::value_type result = *first;
    for(++first; first != last; ++first)
        if(*first < result)
            result = *first;

    return result;
}

#endif//MIN_H
