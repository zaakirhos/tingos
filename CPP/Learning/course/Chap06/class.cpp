// class.cpp by Bill Weinman <http://bw.org/>
// updated 2020-06-24
#include <cstdio>

// a very simple class
class C1 {
    int i = 0; //this is private by default
public:
    void setvalue( int value ) { i = value; }

    //one will be called by const-qualified objects and the other will be called by
    //non-const-qualified objects
    //const-qualified can be called by all objects, but non-const-qualified can only be called by non-const objects
    int getvalue() { return i; }
    // to make it 'const safe' => a const C1 instance can call this
    int getvalue() const { return i; } 
    int doubleIt() ;
};
//separate the interface
int C1::doubleIt() 
{
    i *= 2;
    return i;
}

int main() {
    int i = 47;
    C1 o1;    
    o1.setvalue(i);
    const C1 o2 = o1;
    printf("value is %d\n", o1.getvalue());
    printf("value is %d\n", o2.getvalue());
    o1.doubleIt();
    printf("value is %d\n", o1.getvalue());
    return 0;
}
