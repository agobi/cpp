#ifndef DUPKER_H
#define DUPKER_H

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


#endif//DUPKER_H
