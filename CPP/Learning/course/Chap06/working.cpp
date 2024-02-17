// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

struct A{
    int a;
    int b;
     int c;
};
class B{
    public:
        int a;
        int b;
        int c;
};

int main()
{
    A a = {1, 2, 4};
    B b = {1, 2, 4};
    puts("Hello, World!");
    return 0;
}
