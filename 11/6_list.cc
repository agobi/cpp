// Lista, most mar inicializatorral, es megy a push_back is
// irtunk ra iteratort, az egyetlen gond a memory leak
#include <iostream>
#include <iterator>
#include <algorithm>

class list
{
public:
    list()
        : _front(0), _back(0)
    { }

    void push_back(const int& value)
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
        elem(elem *p, elem *n, const int &v)
            : prev(p), next(n), value(v)
        {}
        elem *prev, *next;
        int value;
    };

    // _front es _back nem dangling
    // _front == 0 <=> _back == 0
    // _front == 0 || _front->prev == 0
    // _back == 0 || _back->next == 0
    // p == _front || p->prev->next=p
    // p == _back || p->next->prev=p

    elem *_front, *_back;

public:
    class iterator
    {
    public:
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

        int &
        operator * ()
        {
            return _p -> value;
        }

    private:
        elem * _p;
    };

    iterator begin()
    {
        // return iterator(_front);
        //         ^^^ felesleges,
        //         a _front konvertalodik, mert van olyan egy parameteres
        //         konstruktora
        return _front;
    }

    iterator end()
    {
        //return iterator(0);
        return 0;
    }
};


int main()
{
    list l;
    l.push_back(42);
    l.push_back(137);
    std::copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, "\n"));
};
