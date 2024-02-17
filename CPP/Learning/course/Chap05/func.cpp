// func.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include "func.h"
#include <string>

void func2(int * i){
    *i = 100;
    printf("%d \n", *i);
}
void func3(const std::string & s){
    printf("%s\n", s.c_str());
}

int main()
{
    puts("this is main()");
    func();

    int a = 67;
    std::string s = "This is a string";
    func2(&a);
    func3(s);

    void (*pfunc)() = func;
    pfunc();
    
    return 0;
}

void func()
{
    puts("this is func()");
}
