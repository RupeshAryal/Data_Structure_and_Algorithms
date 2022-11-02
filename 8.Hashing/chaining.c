#include<stdio.h>
#include<stdlib.h>
#include "Chains.h"


int hash_function(int key)
{
    return key%10;
}

void insertHT(struct Node *H[], int key)
{
    int index = hash_function(key);
    SortedInsert(&H[index], key);
}



int main()
{
    struct Node *HT[10]; 

    for(int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    insertHT(HT, 13);
    insertHT(HT, 12);
    insertHT(HT, 14);
    
    struct Node *node_with_key = Search(HT[hash_function(10)], 10);
    if (node_with_key)
    {
     printf("%d ", node_with_key->data);
    }
    else
    {
        printf("key is not found");
    }
    return 0;

}
   
