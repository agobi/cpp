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

    ~linkedlist()
    {
        while(_last)
        {
            node *tmp = _last;
            _last = _last -> _prev;
            delete tmp;
        }
    }

    bool empty()
    {
        return !_first;
    }

    void push_back(int value)
    {
        // C++11: nem kell ctor:
        //node *n = new node { _last, 0, value };
        node *n = new node(_last, 0, value);
        // (*n).prev == n -> prev

        _last = n;
        if(_first)
            _last -> _next = n;
        else
            _first = n;
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

int main()
{
    {
        linkedlist l;
        l.push_back(6);
        l.push_back(5);
    }

    // something
}
