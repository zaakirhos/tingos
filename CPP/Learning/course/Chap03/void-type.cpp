// void-type.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>


//no return
// 2nd void is not required, just for compatibility
void func ( void ) {
    puts("this is void func ( void )");
    return; //allowed, but with a value is not allowed
}

int main() {
    puts("calling func()");
    func();
    return 0;
}

