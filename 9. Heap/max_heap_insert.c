//Heap is a tree based data structure which where the treecomplete binary tree.
//In a max-heap  all the descendents of a node are smaller


#include<stdio.h>
#include<math.h>
#define SIZE  15


void insert(int AT[], int x)
{
    int i = 1;
    while(AT[i] != 0)
    {
        i++;
    }

    int temp = i;
    
    AT[temp] = x;
    i = ceil(i/2);

    while(i >= 1 && (AT[i] < AT[temp]))
     {
         AT[temp] = AT[i];
         AT[i] = x;
         temp = i;
         i = ceil(i/2);
     }    
}


int main()
{
    int A[SIZE] = {0};
    insert(A, 10);
    insert(A, 20);
    insert(A, 30);
    insert(A, 25);
    insert(A, 5);
    insert(A,40);
    insert(A, 35);
   
   
    
    int i = 1;
    for (i;i <=SIZE-1;i++)
    {
        printf("%d ", A[i]);
    }
    return 0;

}