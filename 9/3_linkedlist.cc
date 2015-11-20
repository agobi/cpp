#include <iostream>
class linkedlist
{
    struct node
    {
        node(node *prev, node *next, int value)
            : _prev(prev), _next(next), _value(value)
        {}

        node *_prev, *_next;
        int _value;
    };

    // _first == 0 <=> _last == 0
    node *_first, *_last;

public:
    linkedlist()
        : _first(0), _last(0)
    {}

    linkedlist(const linkedlist &o)
        : _first(0), _last(0)
    {
        for(node *i=o._first; i; i=i->_next)
            push_back(i->_value);
    }

    ~linkedlist()
    {
        while(_last)
        {
            node *tmp = _last;
            _last = _last -> _prev;
            delete tmp;
        }
    }

    linkedlist &
    operator = (const linkedlist &rhs)
    {
        if(this != &rhs)
            linkedlist(rhs).swap(*this);

        //if(this != &rhs)
        //{
        //   linkedlist tmp(rhs);
        //   swap(tmp);
        //}

        return *this;
    }

    void swap(linkedlist &rhs)
    {
        std::swap(_first, rhs._first);
        std::swap(_last, rhs._last);
    }

    bool empty()
    {
        return !_first;
    }

    void push_back(int value)
    {
        // C++11: nem kell ctor
        //node *n = new node { _last, 0, value };
        node *n = new node(_last, 0, value);
        // (*n).prev == n -> prev

        if(_first)
            _last -> _next = n;
        else
            _first = n;
        _last = n;
    }

    // nem ures lista
    int &back()
    {
        return _last -> _value;
    }

    void pop_back()
    {
        node *tmp = _last;
        _last = _last -> _prev;
        if(_last)
            _last -> _next = 0;
        else
            _first = 0;

        delete tmp;

    }
};

void printlist(linkedlist l)
{
    while(!l.empty())
    {
        std::cout<<l.back()<<std::endl;
        l.pop_back();
    }
}

int main()
{
    {
        linkedlist l;
        linkedlist ll(l);
        linkedlist l2 = l;

        l.push_back(6);
        l.push_back(5);
        ll = l;
        printlist(ll);
        printlist(l);
    }

    // something
}
