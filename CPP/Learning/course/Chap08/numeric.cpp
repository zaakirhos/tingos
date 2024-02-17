// numeric.cpp by Bill Weinman <http://bw.org/>
// updated 2002-07-27
#include <cstdio>
#include <cstdlib>
#include <cmath>

int main()
{
    int neg = -47;
    int x = abs(neg);
    printf("x is %d\n", x);
    int y = llabs(neg); //long long abs
    int z = fabs(neg); //float;

    double expo = exp(2);
    double logVal = log(10); //log2 and more 
    double powered = pow(3, 4);
    double sqrtVal = sqrt(1024);
    const double pi = acos(-1);
    double radiantVal = cos(pi/3);
    radiantVal = tan(pi/4);



    return 0;
}
