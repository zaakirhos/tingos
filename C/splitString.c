#include <stdio.h>
#include <stdlib.h>
#include<string.h>
/*
Write a program in C to split string into words by white space

Input: Hello World
Output:
Hello
World
*/

int main(){
  int max = 100;
  int maxArg  = 50;
  char *inputString = malloc(max * sizeof(char));
  char **words = malloc(maxArg * sizeof(char*));
  char *word = malloc(max * sizeof(char));
  int indexCtr = 0;
  int wordIndex = 0;
  int actualArg = 0;

  //Request string Input
  printf("Input a string: ");
  fgets(inputString, 100, stdin);

  //Loop through each character in the string

  for (indexCtr = 0; indexCtr<=strlen(inputString); indexCtr++){
    // If current character is space or null
    if (inputString[indexCtr] == ' ' || inputString[indexCtr] == '\0'){
      // Append the null character to the current word
      words[actualArg] = word;

      // Increment total words found
      actualArg++;

      // Reset the index to zero for the next word
      wordIndex = 0;
    }

    // Found a character of a word
    else
    {
      // Copy the character of the word
      word[wordIndex] = inputString[indexCtr];
      // Increment the index of the word
      wordIndex++;

    }
  }

  printf("\nWords from the string are:\n");

  // Loop through all the words that were copied

  for (wordIndex = 0; wordIndex < actualArg; wordIndex++)
  {
    // Print each word
    printf("%s\n", words[wordIndex]);
  }
  
  return 0;
}
