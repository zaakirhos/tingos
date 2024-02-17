#include <iostream>
#include "function.h"
#include "date.h"
using namespace std;
int main(){
    print_hello();
    cout<< "The factorial of 5 is " << factorial(5) << endl;

    Date date(2000, 12, 28);

    cout<< "The month is " << date.getMonth() <<endl;
    return 0;
}