/* sum of n natural number.
lets suppose we have n natural numbers 
1,2,3,4,5 ......n or
1,2,3,4,5 ..... n-1, n

then sum of n natural number can be said as,
sum(n) = sum(n-1) + n
which is recursive in nature */

#include<stdio.h>

int SumRecursion(int n)
{
    if (n == 0)
        return 0;
    return SumRecursion(n-1) + n;
}
/*Here time complexity for recursive function is order of n. as we can see
for n number of items n + 1 calls is made.

since new activation record is made everytime a function is called
the space complexity for the function is order of n. Or O(n).
*/

int SumIterrative(int n)
{
    int sum = 0;
    for(int i; i <= n; i++)
    {
        sum = sum +i;
    }
    return sum;
}
/*here time complexity for iterative function is number of time the for loops runs.
since there is only one for loop and it runs n number of time the time complexity if the 
iterative function is ihe order of n.

for space complexity, it is observed that memory is only assigned to the function and its local variables
just during the compilation time. Therefore space complexity of function is constant. */


    
int main()
{
    SumRecursion(10);
    SumIterrative(10);
    return 0;
}

/*since iterative version has better space complexity we should be avoiding recursive function since it is less
efficient */


