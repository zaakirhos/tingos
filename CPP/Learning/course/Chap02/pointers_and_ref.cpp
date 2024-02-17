// pointers.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int x = 7;
    int * ip = &x;
    int & y = x; //reference, not a pointer, only in c++

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);

    y = 73; //this changes x, which leads to a change in *ip
      printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);

    //To prevent changing the x from y:
    int x2 = 67;
    const int & y2 = x2; 
    return 0;
}
