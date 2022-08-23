//finding duplicates items in array using hashing method


#include<stdio.h>

int main()
{
    int array[10] = {1,2,3,4,4,4,5,6,6,7};
    int HashTable[array[9]+1] = {0};
    int i = 0;
    int length = sizeof(array) / sizeof(int);
    int hashlength = sizeof(HashTable) / sizeof(int);

   for(i = 0; i < length; i++ )
   {
    HashTable[array[i]]++;
   }

   for(i = 0; i < hashlength; i++)
   {
    if(HashTable[i] > 1)
    {
        printf("%d repeats %d times \n", i, HashTable[i]);
    }
   }


}
