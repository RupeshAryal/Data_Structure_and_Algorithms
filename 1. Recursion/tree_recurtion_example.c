/*A recursion is said to be tree recursion if the function 
call itself more than one time */

#include<stdio.h>

void fun(int n)
{
    if (n>0)
    {
        printf("%d ", n );
        fun(n-1);
        fun(n-1);
    }
}
int main()
{
    fun(3);
}

/*call made  in sequence
    fun(3)
        print(3)
        fun(2)"left fun 2"
            print(2)
            fun(1) "left fun 1"
                print(1)
                fun(0) "we return to fun 1"
                fun(0)
            fun(1) "right fun 1"
                print(1)
                fun(0)
                fun(0)
        fun(2) "right fun 2"
            print(2)
            fun(1)
                print(1)
                fun(0)
                fun(0)
            fun(1)
                print(1)
                fun(0)
                fun(0)
                return
            return
        return
    return to main
terminate

Here time complexity depends upon the total number of calls made in each level
first level has 1 call, second has 2, third has 4 calls and the last level has 8 calls
Then time complexity is given by 
T(n) = 1 + 2 + 4 + 8 + ...... which follows a geometric series. then T(n) = 2^(n+2) - 1
Therefore, the time complexity is given by T(n) = O(2^n).

space complexity depends on height of the tree.
The maximum height in this function is 4 or n + 1, then the space complexity is the order of n
or, space complexity = O(n)
*/


            
        


