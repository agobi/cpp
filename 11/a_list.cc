// const_iterator
// illetve amit lehet constnak jeloltem
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
        if(this != &rhs)
            list(rhs).swap(*this);
        /*{
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
    class const_iterator
    {
    public:
        typedef const T value_type;

        const_iterator(elem *p)
            : _p(p)
        {}

        bool
        operator != (const const_iterator &rhs) const
        {
            return _p != rhs._p;
        }

        const_iterator &
        operator ++ ()
        {
            _p = _p -> next;
            return *this;
        }

        const_iterator &
        operator -- ()
        {
            _p = _p -> prev;
            return *this;
        }

        const T &
        operator * () const
        {
            return _p -> value;
        }

    private:
        const elem * _p;
    };

    class iterator
    {
    public:
        typedef T value_type;

        iterator(elem *p)
            : _p(p)
        {}

        bool
        operator != (const iterator &rhs) const
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
        operator * () const
        {
            return _p -> value;
        }

        // konvertalodjon automatikusan const_iteratorra
        operator const_iterator () const
        {
            return _p;
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

    const_iterator begin() const
    {
        return _front;
    }

    const_iterator end() const
    {
        return 0;
    }
};

int main()
{
    list<int> l;
    l.push_back(42);
    l.push_back(137);
    *l.begin() = 64;

    const list<int> q(l);
    // *q.begin() = 64;
    // q const, tehat ez ne mukodjon -> const_iterator

    // const int * <-> const_iterator
    // int *i const <-> const iterator

    // const_iterator -> az adatot nem lehet valtoztatni
    // const iterator -> az iteratort nem lehet valtoztatni

    std::copy(q.begin(), q.end(), std::ostream_iterator<int>(std::cout, "\n"));

    const list<int>::iterator i = l.begin();
    *i = 23;
    //++i;
    const list<int>::const_iterator qi = i;
};
