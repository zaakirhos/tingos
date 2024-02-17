#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//
// Created by Zakir Hossain on 4/20/21.
//

#ifndef SIMPLESHELL_PARSECMD_H
#define SIMPLESHELL_PARSECMD_H
/*
 * Swarthmore College, CS 31
 * Copyright (c) 2017 Swarthmore College Computer Science Department,
 * Swarthmore PA, Professor Tia Newhall
 */


#define MAXLINE    1024   // max command line size
#define MAXARGS     128   // max number of arguments on a command line
/*
 * parse_cmd - Parse the command line and build the argv array.
 *
 *    cmdline: the command line string entered at the shell prompt
 *    argv:  an array of size MAXARGS of char *
 *           parse_cmd will initialize its contents from the passed
 *           cmdline string.
 *           The caller should pass in a variable delcared as:
 *              char *argv[MAXARGS];
 *              (ex) int bg = parse_cmd(commandLine, argv);
 *
 *           argv will be filled with one string per command line
 *           argument.  The first argv[i] value following the last
 *           command line string will be NULL.  For example:
 *              ls -l     argv[0] will be "ls"  argv[1] will be "-l"
 *                        argv[2] will be NULL
 *          for an empty command line, argv[0] will be set to NULL
 *    bg:   pointer to an int that will be set to 1 if the last
 *          argument is '&', 0 otherwise. So bg will be set to 1
 *          if the command is meant to be run in the background.
 *
 *    returns: -2 if cmdline is NULL
 *             -1 if the command line is empty
 *              0 to indicate success
 */ int parse_cmd(const char *cmdline, char **argv, int *bg){
    int argSize = MAXARGS;
    int cmdLength = strlen(cmdline), i, j;
    argv = malloc(argSize * sizeof(char*));
    char *each="";
    char c;
    char delimiter = ' ';

    
    if(argv == NULL){
        printf("Allocation failed!\n");
        return -2;
    }

    for (i = 0; i <  cmdLength; i++){
        c = cmdline[i];
        if(c == delimiter){
            argv[j] = each;
            j++;
            c = cmdline[i+1];
        }
        strncat(each, &c, 1);
    }


    return 0;
}

#endif //SIMPLESHELL_PARSECMD_H
