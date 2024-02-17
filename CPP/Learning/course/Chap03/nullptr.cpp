// nullptr.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

#ifndef NULL
//Long long 0
#define NULL (0LL) /* common C++ definition */
#endif

void f( int i ) {
    printf("the int is %d\n", i);
}

void f( const char * s ) {
    printf("the pointer is %p\n", s);
}

int main() {
    //f(NULL) => this is ambiguous
    f(nullptr);
    return 0;
}
