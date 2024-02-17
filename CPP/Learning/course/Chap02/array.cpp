// array.cpp by Bill Weinman [bw.org]
// updated 2020-07-07
/*

*/
#include <cstdio>

int main()
{
    int arr1[10]; //10

    int* ip = arr1; //ip has address of arr1[0] 
    ++ip; // ip has address of arr1[1]
    *ip = 45; // arr1[1] = 45;
    *(++ip) = 9;  // ip has address of arr1[2] and arr1[2] = 9
    for(int i :  arr1){
         printf("%d \n", i);
    }

    int arr2[] = { 1, 2, 3, 4, 5 };
    int arr2Size = sizeof(arr2) / sizeof(arr2[0]);
    printf("Size of arr2 is %d\n", arr2Size);
    for(auto i : arr2) {
        printf("%d \n", i);
    }
    



    return 0;
}
