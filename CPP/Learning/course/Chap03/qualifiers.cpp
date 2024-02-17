// qualifiers.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24

/*
Constant Volatile qualifiers:
1, const
2. mutable
3. volatile

Storage Duration Qualifiers:
1. stattic
2. register
3. extern
*/
#include <cstdio>

class S {
public:
    static const int a = 10;
    int static_value() {
        static int x = 7;
        return ++x;
    }
};

int func() {
    int x = 7;
    return ++x;
}
int func2(){
    static int x = 7;
    return ++x;
}
int main() {
    const int i = 42; //immutable
    printf("The integer is %d\n", i);

    int j = func(); //8
    printf("The integer is %d\n", j);
    j = func(); //8 or 9? it's 8
    printf("The integer is %d\n", j);

    int k = func2(); // 8;
    printf("The integer is %d\n", k);
    k = func2(); // 9
    printf("The integer is %d\n", k);

    S s1;
    S s2;
    S s3;

    //Different for each
     printf("The integer is %d\n", s1.a);
    printf("The integer is %d\n", s2.a);
    printf("The integer is %d\n", s3.a);

    printf("The integer is %d\n", s1.static_value());
    printf("The integer is %d\n", s2.static_value());
    printf("The integer is %d\n", s3.static_value());

    return 0;
}

