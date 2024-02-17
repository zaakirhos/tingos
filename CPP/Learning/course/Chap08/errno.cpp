// errno.cpp by Bill Weinman <http://bw.org/>
// updated 2002-06-24
#include <cstdio>
#include <cerrno>
#include <cstring>

int main() {
    printf("Erasing file foo.bar\n");
    remove("foo.bar");
    printf("errno is: %d\n", errno);
    perror("Cannot erase file");

    const char * errstr = strerror(errno);
    printf("error (%d): %s\n", errno, errstr);
    return 0;
}
