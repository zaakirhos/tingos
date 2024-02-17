// working.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>

int main()
{
    static const char * fn1 = "file1";
    static const char *fn2 = "file2";

    FILE *fh = std::fopen(fn1, "w");

    std::rename(fn1, fn2);
    std::fclose(fh);
    std::remove(fn2);

    const int bufsize = 256;
    static char buf[bufsize];
    std::fputs("prompt: ", stdout);
    std::fgets(buf, bufsize, stdin);
    std::puts("output:")
    std::fputs(buf, stdout);
    std::fflush(stdout); //finish writing it now, does not execute further lines until done;
    std::fputs("Hello, World\n", stdout); //stdout is like a file handler
    return 0;
}
