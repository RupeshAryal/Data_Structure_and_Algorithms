#include<stdio.h>

void insertion_sort(int A[], int n)
{
    int j;
    int x;
    for(int i = 1; i < n; i++)
    {
        j = i - 1; 
        x = A[i];
        while(A[j]>x && j > -1)
        {
            A[j+1] = A[j];
            j--;   
        }
        A[j+1] = x;
    }
}

int main()
{
    int A[10] = {4,5,3,6,7,1,2,10,9,8};
    int x = 10;
    insertion_sort(A, x);
    for(int i = 0; i < 10;i++)
    {
     printf("%d ", A[i]);
    }
    return 0;
}

//Analysis for insertion sort
//----------------------------//


//in insertion sort with array data structure, we need to shift array elements one step further to make space for
//the correct element. for eg:
//let us consider an array [5,4,3,2,1]
//we are considering the worst case scenario. The insertion sort proceeds as:
//[5,4,3,2,1] current A[i] = 4, number of comparision : 1, compared to: [5], total shift :1
//[4,5,3,2,1] current A[i] = 3, number of comparision : 2, compared to: [4,5], total shift :2
//[3,4,5,2,1] current A[i] = 2, number of comparision : 3, compared to: [3,4,5], total shift :3
//[2,3,4,5,1] current A[i] = 1, number of comparision : 4, compared to: [2,3,4,5], total shift :4
//[1,2,3,4,5] current A[i] = exceeds the Array range, loop terminates, the array is now sorted

//Based on comparision, for n elements we have n-1 comparision 
//then total comparision  = 1 + 2 + ..... + (n-1) = n(n-1) / 2
//Time complexity = O(n^2)

//Based on shifts, for n elements we have n-1 shifts
//then total shifts  = 1 + 2 + ..... + (n-1) = n(n-1) / 2
//Time complexity = O(n^2)

//Also if the array is already sorted(best case scenario), the outer loop will run for n-1 times and the program will 
//never enter the inner while loop as there would be no elements such that A[j] > A[i]
//Therefore, the time complexity is order of n, i.e
//Time complexity = O(n)

//therefore, the time complexity of insertion sort varies from O(n) to O(n^2). i.e insertion sort is stable

//for sorting two elements with same value, the order of those elements never changes and no swaps were made. Therefore,
//insertion sort is stable

