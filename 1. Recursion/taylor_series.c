/*the taylor series for e^x is given by 
e^x = 1 + x + x^2/2! + x^3/3! + x^4/4! ...... n items

*/


#include<stdio.h>

double e(int x, int n) // function for taylor series at x, for upto nth item.
{
    static double p=1, f=1; //let product term  be initially 1 and factorial be 1
    double r;

    if(n == 0)
        return 1;
    r = e(x, n-1);
    p = p * x; //after returning we increase the product term for succeeding term by p
    f = f * n;
    return r + p/f;
}

int main()
{
    printf("%f \n ", e(4,15));
    return 0;
}

/* for each term the multiplication in numerator and denominator increases by two
then, total time = 0 + 2 + 4 + 6 + 8 .....
                = 2(1 = 2 + 3 + .... )
                = 2(n(n+1)/2)
                = n(n + 1)
            therefore. the time complexity is the order of n^2
    
