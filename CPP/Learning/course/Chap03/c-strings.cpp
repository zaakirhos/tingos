// c-strings.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-05
#include <cstdio>

int main() {
    char primitive_string[] = "String";
    //not giving const throws a warning because modern c++ wants this
    const char * sp = "String"; // sp is NOT const, but what sp points to is const
    const char * const sp2 = "String"; //now sp2 IS const;

    //Concactination
    const char * s2 = "String1" "String2";
    
    puts(primitive_string);
    
    //ends if primitive_string[i] = null terminator
    for(int i = 0; primitive_string[i]; i++) {
        printf("%d: %c\n", i, primitive_string[i]);
    }

    char primitive_string2[] = {'H', 'L', 'L', 0};

    for (char * cp = primitive_string2; *cp!=0; ++cp)
    {
        printf("char is %c\n", *cp);
    }
    
    return 0;
}
