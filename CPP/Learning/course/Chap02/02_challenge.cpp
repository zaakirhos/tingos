// 02_challenge.cpp by Bill Weinman [bw.org]
// updated 2020-07-12
#include <cstdio>

const char string[] = "This is a null-terminated string.";

int main()
{
    int count = 0;

    for (int i = 0; string[i]; i++)
    {
        count++;
    }
    
    printf("The number of characters is: %d\n", count);
    return 0;
}
