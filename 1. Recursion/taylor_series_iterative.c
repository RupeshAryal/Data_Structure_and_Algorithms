//taylor series of e^x using iterative method
#include<stdio.h>

double e(int x, int n)
{
    int i = 1;
    double num = 1, den = 1, s = 1;

    for(i; i <=n;i++)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

int main()
{
    printf("%lf \n", e(1,10));
    return 0;
}