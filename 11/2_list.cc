struct list
{
    list &prev, &next;
    int value;
};

int main()
{
    // nem igazan hasznalhato, pointer kell
    list l = { l, l, 42 };
    l.next.prev.value = 137;
};
