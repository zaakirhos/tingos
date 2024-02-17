// auto-type.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>
#include <string>
#include <vector>
#include <typeinfo>

std::string & func() {
    static std::string s = "this is a string";
    return s;
}

int main() {
    auto x = func(); //compiler knows what the type of func return is
    printf("x is %s\n", x.c_str());
    printf("type of x is %s\n", typeid(x).name());

     std::vector<int> vi = { 1, 2, 3, 4, 5 };
    for(std::vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        printf("int is %d\n", *it);
    }
    return 0;
}
