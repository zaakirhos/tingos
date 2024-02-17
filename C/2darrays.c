#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <math.h>
//#include <time.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <signal.h>
//#include <ctype.h>
//#include <conio.h>

int main(){

    int *arr;
    int rows = 4;
    int cols = 5;

    arr = malloc((rows * cols) * sizeof(int));
    for (int i = 0; i < rows; i++)
    {
        for ( int j = 0; j < cols; j++)
        {
            arr[i*cols + j] = i+j;
            printf("%d", arr[i*cols + j]);
            // printf("(%d, %d): %d\n", i, j, arr[i*cols + j]);
        }
        printf("\n");
        
    }
    printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for ( int j = 0; j < 3; j++)
        {
            printf("%d", arr[i*cols + j]);
            // printf("(%d, %d): %d\n", i, j, arr[i*cols + j]);
        }
        printf("\n");
        
    }
    
    return 0;
}