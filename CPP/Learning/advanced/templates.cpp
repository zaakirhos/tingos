#include <iostream>
#include <cstdlib>

template <class T>
void swap(T&a,T&b)      //Function Template
{
    T temp=a;
    a=b;
    b=temp;
}

template <class T>
void print(T a){
    std::cout << a << std::endl; 
}


// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T>
T myMax(T x, T y)
{
   return (x > y)? x: y;
}

 int main() {

     int x1=4, y1=7;
    float x2=4.5, y2=7.5;
    swap(x1,y1);
    swap(x2,y2);

    print(myMax<int>(3, 7));
    print(myMax<double>(3.0, 7.0));
    print(myMax<char>('g', 'e') );

     return 0;
 }

