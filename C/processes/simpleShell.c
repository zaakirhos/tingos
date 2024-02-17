#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
//#include <ctype.h>
//#include <conio.h>


//Functions prototypes
int parse_cmd(const char *cmdline, char *argv[], int *bg)
int main(int argc, char* argv[]){

}

// Parses a command line into an argv array
// The function initializes argv bucket values to individual
// tokens from the cmdline string.
// The argv array of char * is passed in by the caller.
// This version doesn't do dynamic memory allocation...no freeing after use.
int parse_cmd(const char *cmdline, char *argv[], int *bg)