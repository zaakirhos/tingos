// new-delete.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <new>

const long int count = 1024;

int main() {
    printf("allocate space for %lu long int at *ip with new\n", count);
    
    // allocate array
    long int * ip;
    try {
        ip = new long int [count]; //space for an array of count 1024 integers, only in C++
    } catch (std::bad_alloc & ba) {
        fprintf(stderr, "Cannot allocate memory (%s)\n", ba.what());
        return 1;
    }
    // alternative to try-catch for failure
    long int * ip2;
    ip2 = new (std::nothrow) long int [count];
    if(!ip2){
        fputs("Cannot allocate memory (%s)\n ", stderr);
        return 1;
    }
    
    // initialize array
    for( long int i = 0; i < count; i++ ) {
        ip[i] = i;
    }
    
    // deallocate array
    delete [] ip;
    puts("space at *ip deleted");
    
    return 0;
}
