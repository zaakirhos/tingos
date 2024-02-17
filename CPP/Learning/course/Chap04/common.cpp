// working.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

int main()
{
    int x = 47;
    int y = 5;

    printf("x is %d and y is %d\n", x, y);
    printf("-x is %d and -y is %d\n", -x, -y);

    //increment decrememt
    printf("x is %d\n", ++x); // increment first then return 
    printf("x is %d\n", x++);// return first then increment

    //type casting
    int x2 = 5;
    long long int y2;
    y2 = x2; //this is fine, because y2 holds more memory space
    
    int x3;
    long long int y3 = 5;
    x3 = y3; //this will warn because x3 has smaller memory space
    x3 = (int)y3; //to avoid the warning


    //sizeof operator
    size_t x_type = sizeof(int);


    return 0;
}
