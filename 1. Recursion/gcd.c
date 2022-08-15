#include<stdio.h>

int gcd(int a, int b)
{
    int r = a % b;
    if (r == 0 )
         return b ;
    return gcd(b,r);
}

int main()
{
    printf("%d ", gcd(100,40));
    return 0;
}