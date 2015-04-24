// probaljuk ki a regi jo dup fuggvenyunkkel
// + minden komment benne van
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
class list
{
public:
    // Ez jol tud jonni, lasd jovo heten
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

    // _front es _back nem dangling
    // _front == 0 <=> _back == 0
    // _front == 0 || _front->prev == 0
    // _back == 0 || _back->next == 0
    // p == _front || p->prev->next=p
    // p == _back || p->next->prev=p

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
        //return iterator(_front);
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

    const_iterator begin() const
    {
        return _front;
    }

    const_iterator end() const
    {
        return 0;
    }
};

template <typename T>
bool dup(T it, T end)
{
    for(;it != end; ++it)
    {
        T it2 = it;
        ++it2;
        if(std::find(it2, end, *it) != end)
            return true;
    }

    return false;
}

int main()
{
    list<int> l;
    l.push_back(42);
    l.push_back(137);
    std::cout<<dup(l.begin(), l.end())<<std::endl;

    l.push_back(42);
    std::cout<<dup(l.begin(), l.end())<<std::endl;
};
