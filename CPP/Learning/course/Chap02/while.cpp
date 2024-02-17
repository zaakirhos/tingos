// while.cpp by Bill Weinman [bw.org]
// updated 2020-06-24
#include <cstdio>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int i = 0;

    while (i < 5)
    {

        if (i == 2)
        {
            ++i;
            continue;
        }
        if (i == 4)
            break;
        printf("element at %d is %d\n", i, array[i]);
        ++i;
    }

    i = 0;
    do
    {
        if (i == 2)
        {
            ++i;
            continue;
        }
        if (i == 4)
            break;
        printf("element at %d is %d\n", i, array[i]);
        ++i;
    } while (i < 5);

    return 0;
}
