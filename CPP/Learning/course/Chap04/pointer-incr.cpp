// pointer-incr.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <cstdint>

void printp(uint8_t *p, uint32_t *p2) {
    printf("8 bit-pointer is %p, value is %d\n", p, *p);
    printf("32-bit pointer is %p, value is %d\n", p2, *p2);
}

int main()
{
    uint8_t arr[5] = { 1, 2, 3, 4, 5 };
     uint32_t arr2[5] = { 1, 2, 3, 4, 5 };
    uint8_t *p = arr;
    uint32_t *p2 = arr2;
    //p2 will be incremented by 4 bits
    printp(p++, p2++);
    printp(p++, p2++);
    printp(p++, p2++);

    return 0;
}
