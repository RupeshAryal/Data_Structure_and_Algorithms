/* A recursion is called indeirect recursion if it calls another function 
and that another function calls the original function.
For example, if func1 calls func2 and func2 calls func1, such recursive function calls
are called indirect recursion */


#include<stdio.h>
void funB(int n);
void funA(int n)
    {
      if (n > 0)
        {
            printf("%d ", n);
            funB(n-1);
        }
    }

void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n/2);
    }
}

int main()
{
    funA(20);
    return 0;
}