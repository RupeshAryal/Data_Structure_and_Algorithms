#include<stdio.h>
#define SIZE 10

int hash_function(int key)
{
    return key % SIZE;
}

int probe(int H[], int key)
{
    int index = hash_function(key);
    int i = 0;
    while(H[(index + i)%SIZE]!=0 && i<SIZE)
    {
        i++;
    }
    return (index+i)%SIZE;
}



void insert(int H[], int key)
{
    int index = hash_function(key);
    if (H[index] == 0)
    {
        H[index] = key;
    }
    else
    {
        index = probe(H, key);
        H[index] = key;
    }
}

int Search(int H[], int key)
{
    int index = hash_function(key);
    while(H[index]!= 0)
    {
        if (H[index] == key)
        {
            return key;
        }
        index++;
    }
    
    return 0;
}


int main()
{
    int HT[10] = {0};
    insert(HT, 1);
    insert(HT, 3);
    insert(HT, 5);
    insert(HT, 7);
    insert(HT, 9);
    for(int i = 1; i <= SIZE; i++)
    {
        int x = Search(HT, i);
        if (x!= 0 )
        {
            printf("contains  element %d \n", x);

        }
        else
        {
            printf("contains no element \n");
        }
    }

    return 0;
}

//advantage of linear probing
//---no extra space needed

//disadvantages of linear probing
//---forms a primary cluster
//---deletion is difficult and may need rehasing