//given an array find the duplicate element and the number of time they repeat

//for example: [1,2,3,4,4,5,6,6,6,7]
//here, 4 repeats 2 times and 8 repeats two times, we have to print that information

#include<stdio.h>

int main()
{
    int array[10] = {1,2,3,4,4,5,6,6,6,7};

    int last_duplicate = 0; //to keep track of last duplicate item

    int i = 0,j = 0;
    /*for(int i=0; i<=9; i++)
    {
        if(array[i] == array[i+1] && array[i] != last_duplicate)
         printf("%d", array[i]);
         last_duplicate = array[i];

    }*/ //this method only prints which element repeats but dont print how many time they repeat

    for(i=0; i<=9; i++)
    {
        if(array[i] == array[i+1])
        {
            j = i + 1;
            while(array[j] == array[i]) j++;
            printf("%d repeats %d times \n", array[i], j-i);
            i = j - 1;
        }
    }
    return 0;
}