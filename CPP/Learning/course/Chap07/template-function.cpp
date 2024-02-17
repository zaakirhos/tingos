// template-function.cpp by Bill Weinman <http://bw.org/>
// updated 2020-07-21
#include <iostream>

//'typename' is same as 'class' but this is recommended;
// template has to be top level (not inside a block)
template <typename T>
T maxof ( T a, T b ) {
    return ( a > b ? a : b );
}

int main() {
    std::cout << maxof<int>( 7, 9 ) << std::endl;
    std::cout << maxof(7, 9) << std::endl; // type not needed, complier used template argument deduction to derive the type
    return 0;
}
