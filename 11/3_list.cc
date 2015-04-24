// Egyszeru lancolt lista
// meg lehet ra csinalni a fuggvenyeket, de nem konnyu hasznalni,
// nincs egysegbe zarva
struct list
{
    list *prev, *next;
    int value;
};


int main()
{
    list l = { nullptr, 0, 42 };
    list q = { l, 0, 42 };
    q.prev.next=q;
};
