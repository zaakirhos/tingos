/* Swarthmore College, CS 31
 * Copyright (c) 2019 Swarthmore College Computer Science Department,
 * Swarthmore PA, Professor Tia Newhall
 */

// TODO: Add your top-level coment here
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
//#include <sys/types.h>
#include <sys/wait.h>
#include "parsecmd.h"

//#define MAXHIST 10   // max number of commands in the history
//
//
//// used to store history information about past commands
//struct history_t {
//    char command[MAXLINE];  // the command line from a past command
//    // TODO: you are welcome to add more fields to this struct type
//};
//
///* global variables: add only globals for history list state
// *                   all other variables should be allocated on the stack
// * static: means these variables are only in scope in this .c file
// *
// * history: a circular list of the most recent command input strings.
// *          Note: there are MAXHIST elements, each element is a
// *          history_t struct, whose definition you can change (by
// *          adding more fields).  It currently has one filed to store
// *          the command line string (a statically declared char array
// *          of size MAXLINE)
// *          Remember: the strcpy function to copy one string to another
// */
//static struct history_t history[MAXHIST];
//static int history_next = 0;
//static int history_size = 0;
//// TODO: you may add some more global variables for the history list
////       (and these should be the only globals in your program)
//
//
//// TODO: add your function prototypes here
////       (your solution should have some helper functions)
//void add_to_history_queue(char *cmdline);
//
//void print_history_queue();
//
//void sigchld_handler(int sig);
//
//void sigint_handler(int sig);
//
//
///******************************************************************/
//int main() {
//
//    char cmdline[MAXLINE];
//    char *argv[MAXARGS];
//    int ret_parse, ret_exec;
//    pid_t pid;
//    int status, num, bg;
//
//    // TODO: add a call to signal to register your signal handler on
//    //       SIGCHLD here
//    signal(SIGCHLD, sigchld_handler);
//    signal(SIGINT, sigint_handler);
//
//    while (1) {
//        // (1) print the shell prompt (in a cool color!)
//        printf("\e[1;36mcs31shell> \e[0m");
//        fflush(stdout);
//
//        // (2) read in the next command entered by the user
//        if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin)) {
//            perror("fgets error");
//        }
//        if (feof(stdin)) { /* End of file (ctrl-d) */
//            fflush(stdout);
//            exit(0);
//        }
//
//        // You can uncomment this to see what the command line is
//        // NOTE: remove or comment out all debug output from submitted version
//        // printf("DEBUG: %s\n", cmdline);
//
//        // TODO: complete top-level steps
//        // (3) make a call to parse_cmd function to parse it into its
//        ret_parse = parse_cmd(cmdline, argv, &bg);
//        printf("%d\n", ret_parse);
//        printf("%s\n", cmdline);
//        printf("%p\n", argv);
//        printf("%s\n", argv[0]);
////    fprintf(stderr, "ret %d", ret);
//        if (ret_parse != -1) {
//            add_to_history_queue(cmdline);
//            pid = fork();
//            if (pid < 0) {
//                printf("Fork failed\n");
//                exit(0);
//            }
//            if (pid == 0) { // child
//                if (strcmp(argv[0], "history") == 0) {
//                    print_history_queue();
//                    exit(0);
//                }
//                if ((argv[0][0]) == '!') {
//
//                    num = atoi(&cmdline[1]);
//                    printf("%d\n", num);
//                    strcpy(cmdline, history[num].command);
//                    printf("%d\n", history_next);
//                    history[history_next - 1].command[0] = '\0';
//                    strcpy(history[history_next - 1].command, history[num].command);
//                    ret_parse = parse_cmd(cmdline, argv, &bg);
//                    ret_exec = execvp(argv[0], argv);
//                    exit(0);
//                }
//                ret_exec = execvp(argv[0], argv);
//                if (ret_exec < 0) {
//                    printf("%s: Command is not found\n", argv[0]);
//                    exit(0);
//                }
//                exit(0);
//            } else { // parent
//                //signal(SIGCHLD, sigchld_handler);
//                if (bg != 1) {
//                    waitpid(pid, &status, 0);
//                }
//            }
//        }
//
//        // (4) determine how to execute it, and then execute it
//        //
//
//    }
//
//    free(argv);
//    return 0;
//}
//
///******************************************************************/
//void add_to_history_queue(char *cmdline) {
//
//    strcpy(history[history_next].command, cmdline);
//    /*
//    if(history_size < MAXHIST){
//       history_size++;
//    }
//    */
//    history_size++;
//    history_next = (history_next + 1) % MAXHIST;
//
//}
///************************0*****************/
//// print out the values in order that they
//// were added to the queue: first to last
//// print:  bucket_index_value: bucket_value
////
//void print_history_queue() {
//
//    // int t = history_next;
//    int index;
//    int size; //how many entries we want to print
//    if (history_size <= MAXHIST) {
//        size = history_size;
//        index = 0;
//    } else {
//        size = MAXHIST;
//        index = history_size - MAXHIST;
//    }
//
//    int index_in_history = index % MAXHIST;
//
//    int i;
//
//    for (i = index_in_history; i < size; i++) {
//        printf("%d : %s\n", index, history[i].command);
//        index++;
//    }
//    for (i = 0; i < index_in_history; i++) {
//        printf("%d : %s\n", index, history[i].command);
//        index++;
//    }
//
//
//
//    /*for(int i = 0; i<history_size; i++){
//       if(history_size == MAXHIST){
//         printf("%d : %s\n", index, history[t].command);
//         t = (t+1)%MAXHIST;
//         index++;
//       }
//       else{
//        printf("%d : %s\n", i, history[i].command);
//       }
//    */
//}
//
//
///**********************************************************/
//
//void sigchld_handler(int sig) {
//    int child_status = 0;
//    while (waitpid(-1, &child_status, WNOHANG) > 0);
//
//}
//
//void sigint_handler(int sig) {
//    //pid_t pid = getpid();
//    printf("\nBye Bye!");
//    exit(0);
//    //kill(pid, SIGKILL);
//}


#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void lsh_loop(void);
char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_cd(char **args);
int lsh_help(char **args);
int lsh_exit(char **args);
int lsh_execute(char **args);


int main()
{
    // Load config files, if any.

    // Run command loop.
    lsh_loop();

    // Perform any shutdown/cleanup.

    return EXIT_SUCCESS;
}

void lsh_loop(void)
{
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);
}

char *lsh_read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Read a character
        c = getchar();

        // If we hit EOF, replace it with a null character and return.
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // If we have exceeded the buffer, reallocate.
//        if (position >= bufsize) {
//            bufsize += LSH_RL_BUFSIZE;
//            buffer = realloc(buffer, bufsize);
//            if (!buffer) {
//                fprintf(stderr, "lsh: allocation error\n");
//                exit(EXIT_FAILURE);
//            }
//        }
    }
}


char **lsh_split_line(char *line)
{
    int bufsize = LSH_TOK_BUFSIZE;
    int position = 0, j;
    unsigned long cmdLength = strlen(line);
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    char *c;
    char *delimiter = ' ';

    if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

//    token = strtok(line, LSH_TOK_DELIM);

    for (int i = 0; i <  cmdLength; i++){
        c = line[i];
        if(c == delimiter){
            tokens[j] = token;
            j++;
            c = line[i+1];
        }
        strncat(token, &c, 1);
    }
//    while (token != NULL) {
//        tokens[position] = token;
//        position++;
//
//        if (position >= bufsize) {
//            bufsize += LSH_TOK_BUFSIZE;
//            tokens = realloc(tokens, bufsize * sizeof(char*));
//            if (!tokens) {
//                fprintf(stderr, "lsh: allocation error\n");
//                exit(EXIT_FAILURE);
//            }
//        }
//
//        token = strtok(NULL, LSH_TOK_DELIM);
//    }
//    tokens[position] = NULL;
    return tokens;
}


int lsh_launch(char **args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("lsh");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

/*
  List of builtin commands, followed by their corresponding functions.
 */
char *builtin_str[] = {
        "cd",
        "help",
        "exit"
};

int (*builtin_func[]) (char **) = {
        &lsh_cd,
        &lsh_help,
        &lsh_exit
};

int lsh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

/*
  Builtin function implementations.
*/
int lsh_cd(char **args)
{
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
    return 1;
}

int lsh_help(char **args)
{
    int i;
    printf("Stephen Brennan's LSH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < lsh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int lsh_exit(char **args)
{
    return 0;
}

int lsh_execute(char **args)
{
    int i;

    if (args[0] == NULL) {
        // An empty command was entered.
        return 1;
    }

    for (i = 0; i < lsh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return lsh_launch(args);
}