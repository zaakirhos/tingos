// printf.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>

int main()
{
    int i = 5;
    long int li = 1234567890L;
    const char * s = "This is a string.";
    //4 is for 4 spaces, 0 will fill leading zeroes to spaces
    printf("i is %04d, li is %ld, s is %s\n", i, li, s);
    //stdout is the console, a file can be given instead
    std::fprintf(stdout, "pointer is %p, sizeof is %zd\n", s, sizeof(s));
    return 0;
}
