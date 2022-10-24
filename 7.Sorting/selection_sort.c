#include<stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int A[], int n)
{
    int i, j, k;
    for(i = 0; i<n-1; i++)
    {
        j = i;
        k = i;
        for (j = i+1; j<n; j++)
        {
            if (A[k] > A[j])
            {
                k = j;
            } 
        }
        swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[10] = {8,6,3,10,9,4,12,5,2,7};
    int x = 10;
    selection_sort(A, x);
    for(int i = 0; i < 10;i++)
    {
     printf("%d ", A[i]);
    }
    return 0;
}


   //Analysis for selection sort//
//................................//

//let us consider an array [5,4,3,2,1]
//we are considering the worst case scenario. The selection sort proceeds as:
//[5,4,3,2,1] current A[i] = 5, number of comparision : 4, compared to: [4,3,2,1], total swap :1
//[1,4,3,2,5] current A[i] = 4, number of comparision : 3, compared to: [3,2,5], total swap :1
//[1,2,3,4,5] current A[i] = 3, number of comparision : 2, compared to: [4,5], total swap :1
//[1,2,3,4,5] current A[i] = 4, number of comparision : 1, compared to: [5], total swap :1
//[1,2,3,4,5] current A[i] = 5, number of comparision : 0, compared to: None, total swap :1
//[1,2,3,4,5] current A[i] = exceeds the Array range, loop terminates, the array is now sorted

//Based on comparision, for n elements we have n-1 comparision 
//then total comparision  = _ + 1 + 2 + ..... + (n-1) = n(n-1) / 2
//Time complexity = O(n^2)

//Based on swaps, the swaps is constant
//then total swaps  = 1 + 1 + 1 +..... = n


//Also if the array is already sorted(best case scenario),
//this sorting technique performs every comparision and the time complexity is still order of n square
//therefore, the time complexity of selection sort  is O(n^2). i.e  selection sort is not adaptive

//suppose we have an array as [2,3,8,8,4]
//At certain point of sorting the "8" at index 2 is swapped with "4" at index 4
//even though there are two "8", the first 8 moves behind the second "8" at index 4.
//The order of the original Array is not maintained, therefore selection sort is not stable. 

