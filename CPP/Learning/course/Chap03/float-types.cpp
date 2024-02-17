// float-types.cpp by Bill Weinman <http://bw.org/>
// updated 2020-08-05
#include <cstdio>

// a byte is 8 bits
const size_t byte = 8;

int main() {
    float f;
    double df;
    long double ldf;
    
    printf("size of float f is %zd bits\n", sizeof(f) * byte);
    printf("size of double df is %zd bits\n", sizeof(df) * byte);
    printf("size of long double ldf is %zd bits\n", sizeof(ldf) * byte);
    f = 500.0;
    f = 5e2; //same
    printf("f is %1.10f\n", f); // precision to 10 digits

    f = .1+.1+.1;
     if (f == 0.3)
     {
         puts("True");
     }else puts("False"); //This is false
     printf("f is %1.10f\n", f); 
     
    
    return 0;
}
