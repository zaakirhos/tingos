#include <cstdio>

//Reference does not make a copy
int & f(int & i){
    return ++i;
}
int main(){

    int i = 5;
    f(i) = 42;
    //make i const to avoid side-effect

    printf("i is %d\n", i);
    return 0;

}