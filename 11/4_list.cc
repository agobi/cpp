// Egysegbe zarjuk a listat
// Ezutan kis kitero, a 8. sort lehet szebben
class list
{
public:
    list()
    {
        _front = 0; _back = 0;
    }

private:
    // _front es _back nem dangling
    // _front == 0 <=> _back == 0

    struct elem
    {
        elem *prev, *next;
        int value;
    };

    elem *_front, *_back;
};


int main()
{
    list l;
};
