#include<stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int bubble_sort(int A[], int n)
{
    int i = 0;
    int j = 0;
    int flag = 0;

    for(i; i < n; i++)
    {    
        for(j = 0; j < n-1 ; j++)
        {
            if (A[j] > A[j+1])
            {
            swap(&A[j], &A[j+1]);
            flag = 1;
            }
         }
    }    
    return 0;  
}

int main()
{
    int A[10] = {10,9,8,7,6,5,4,3,2,1};
    int x = 10;
    bubble_sort(A, x);
    for(int i = 0; i < 10;i++)
    {
     printf("%d ", A[i]);
    }
    return 0;
}


//Analysis for bubble sort;

//suppose we have an array, such that A[] = [5,4,3,2,1]
//in the first iteration we would have maximum 4 swap that is n-1 swap
//in the second iteration we would have maximum 3 swat that is n-2 swap

//in the final iteration we would have 0 swaps
//then total swaps can be written as 1 + 2 + 3 + ..... n
//i.e n(n-2) / 2
//therefore, bubble sort takes order of n^2 time based on swapping

//also since the outer loop runs for n number of time and inner loop run for maximum of n - 1, n -2 , ..... 3,2,1 times 
//the time complexity is order of n^2

//Since the swap is done only if jth element is greater than j+1th element, the order is maintained and the sort is stable.

//if there are no swaps in a iteration, that means the array is sorted. The flag terminates the program once the array is sorted.
//for example: [1,2,3,4,5], here no sorting is required. The inner loop runs for n times before the flag terminates the program.
//In this case the time complexity is the order of n and the bubble sort is adoptive in nature. i.e the time complexity ranges from
//O(n) to O(n^2)