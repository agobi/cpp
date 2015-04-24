// Csinaljunk copy constructort, es ertekadas operatort
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
class list
{
public:
    typedef T value_type;

    list()
        : _front(0), _back(0)
    { }

    list(const list &o)
        : _front(0), _back(0)
    {
        for(elem *p = o._front; p; p=p->next)
            push_back(p->value);
    }

    ~list()
    {
        elem *p = _front;
        while(p)
        {
            elem * tmp = p;
            p = p->next;
            delete tmp;
        }
    }

    list&
    operator = (const list &rhs)
    {
        // trukk: visszavezetjuk a copy constructorra es a destructorra
        if(this != &rhs)
            list(rhs).swap(*this);
        /*{ // Ez ugyanaz, csak picit olvashatobb, mert
            // kiirom az ideiglenes valtozo nevet
            list tmp(rhs);
            tmp.swap(*this);
        }*/
        return *this;
    }

    void swap(list &rhs)
    {
        std::swap(_front, rhs._front);
        std::swap(_back, rhs._back);
    }

    void push_back(const T& value)
    {
        elem * e = new elem(_back, 0, value);
        if(_back)
            _back->next = e;
        else
            _front = e;
        _back = e;
    }

private:
    struct elem
    {
        elem(elem *p, elem *n, const T &v)
            : prev(p), next(n), value(v)
        {}
        elem *prev, *next;
        T value;
    };

    elem *_front, *_back;

public:
    class iterator
    {
    public:
        typedef T value_type;

        iterator(elem *p)
            : _p(p)
        {}

        bool
        operator != (const iterator &rhs)
        {
            return _p != rhs._p;
        }

        iterator &
        operator ++ ()
        {
            _p = _p -> next;
            return *this;
        }

        iterator &
        operator -- ()
        {
            _p = _p -> prev;
            return *this;
        }

        T &
        operator * ()
        {
            return _p -> value;
        }

    private:
        elem * _p;
    };

    iterator begin()
    {
        return _front;
    }

    iterator end()
    {
        return 0;
    }
};

void f(list<int>)
{ }

int main()
{
    {
        list<int> l;
        l.push_back(42);
        l.push_back(137);
        std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, "\n"));

        f(l);
        list<int> q;
        q = l;
    }
    {
        list<int> l;
        l.push_back(42);
        l.push_back(137);
        std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, "\n"));
    }
};
