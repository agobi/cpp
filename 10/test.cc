#include "t.h"
#include "test.h"

int f(T&)
{
    return 42;
}

T &getT()
{
    static T t;
    return t;
}

int i = 42;

// lokalis definicio
static int j;

// nevtelen nevter
namespace
{
    int k;
}
