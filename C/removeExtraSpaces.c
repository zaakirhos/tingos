#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
// Function to remove all extra whitespace from a string
// (note that the string is passed by reference)
void removeSpace(char *arr, int n)
{
    // space is 1 when a space character is found and
    // 0 when any non-space character is found
    int space = 0;
 
    // `k` points to the next free position
    int k = 0;
 
    // iterate through the characters of the string
    for (int i = 0; i < n; i++)
    {
        // handle leading spaces in the string
        while (k == 0 && i < n && arr[i] == ' ') {
            i++;
        }
 
        // if the current character is a space
        if (arr[i] == ' ')
        {
            // if the flag was 0 earlier, i.e., the first occurrence of a
            // space after a word
            if (!space)
            {
                // copy current char (whitespace) at the next free index
                // and set the flag
                arr[k] = arr[i];
                k++;
                space = 1;
            }
        }
        // // if the current character is a punctuation mark
        // else if (ispunct(arr[i]))
        // {
        //     // if the last assigned character was a space, overwrite it
        //     // with the current character
        //     if (k > 0 && arr[k-1] == ' ') {
        //         arr[k-1] = arr[i];
        //     }
        //     else {
        //         // copy the current character at the next free index
        //         arr[k++] = arr[i];
        //     }
        //     space = 0;
        // }

        else {
            // copy the current character at the next free index
            arr[k] = arr[i];
            k++;
            space = 0;
        }
    }
 
    // handle trailing spaces in the string
    arr[k] = '\0';
}
 
int main(void)
{
    char arr[] = "     ls       -h  ";
 
    removeSpace(arr, strlen(arr));
    printf("%s", arr);
 
    return 0;
}