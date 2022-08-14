/* lets suppose we want to find the factorial of number n.
From defination factorial of n is given by, 
n! = 1 * 2 * 3 * ...(n - 1) * n,
which equals;
n! = (n-1)! * n .....(2)
the above equation is the recursive definition of factorial of a number.

The function can be defined as the recurrence relation,
                {
factorial(n) =  0                    when n = 0
                factorial(n-1) * n   when n > 0                  
                                                } */


#include<stdio.h>

int factRecursive(int n)
{
    if(n == 0)
    return 1;
    return factRecursive(n-1) * n;
}

/*The time complexity dependes upon the number of function call made, since there will be n+1
function calls the time complexity would be the order of n.

The space complexity depends upon the height of the recursion tree, height in this equals the number input
Therefore, time complexity would be the order of n */

int factIterative(int n)
{
    int fact = 1;
    for(int i = 1; i<=n;i++)
    {
        fact = fact * i;
    }
        return fact;

}

/*time complexity is order of n as for loop run n number of times
space complexity is constant as only one activation record is created.
*/

int main()
{
    factRecursive(5);
    factIterative(5);
    return 0;
}
    
