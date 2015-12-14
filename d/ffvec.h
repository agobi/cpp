#ifndef FFVEC_H
#define FFVEC_H

#include <vector>
#include <algorithm>

template<typename T>
class full_fledged_vector: public std::vector<T>
{
public:
    void push_front(const T&d) { this->insert(this->begin(), d); }
    void pop_front() { this->erase(this->begin()); }
    void sort() { std::sort(this->begin(), this->end()); }
};

#endif//FFVEC_H
