/*array in c cannot be increased, this is because array stores item in contiguous
memory location, for an example, we create and array of size 5 to store integars value,
assuming the size of in integar is 2 bytes, array would take addresses say starting from 
2000-2010, then to increase the size of an array from 5 to 6, we should have the memory address
2010,12 be empty, which may not be the case.


To increase the size of an array the best we can do is create another array of bigger size, copy the
contents of the array to the bigger array and point it to the bigger array" */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p, *q;
    int i;
    p = (int *)malloc(5 * sizeof(int)); //This dynamically create array of size 5 in heap section of the memory
    p[0] = 1;
    p[1] = 2;
    p[3] = 3;
    p[4] = 4;
    p[5] = 5; // At this point we may want to add more elements to the array but we have reached the limit. 

    q = (int *)malloc(10*sizeof(int)); //create a bigger array

    for(i = 0; i < 5; i++) //we have to transfer content into bigger array
        q[i] = p[i];

    free(p); //since we transferred the contents of smaller array to bigger array, we remove it to free the memory and avoid memory leak

    p = q; //assign the first address of q to p
    q = NULL; //lets point q to null to avoid accidentally accessing the array with q
}