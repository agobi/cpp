// Csinaljunk destructort, hogy ne legyen memory leak
// Csakhogy a masolas rossz, igy segfaultol a program
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

// Ez ugye masolas -> copy constructor
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
        list<int> q(l);
    }
    {
        list<int> l;
        l.push_back(42);
        l.push_back(137);
        std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, "\n"));
    }
};
