//taylor series of e^x using horner polynomial

#include<stdio.h>

double e(int x, int n)
{
    static double s = 1;
    if(n==0)
        return s;
    s = 1 + x*s/n;
    return e(x, n-1);
}

int main()
{
    printf("%lf \n", e(4,10));
    return 0;
}