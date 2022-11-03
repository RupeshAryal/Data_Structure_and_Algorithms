//It solves the problem of clustering as we observer in linear probing
//It takes two funcion
//h(x) = x % 10  -- our regular hasing function for a hash table of size 10
//h1(x) = R - (x % R) where R is the closest prime number to the total size of hash table
//h'(x) = (h(x) + i * h1(x)) % 10


#include<stdio.h>

int regular_hash_function(int key)
{
    return key % 10;
}

int second_hash_function(int key)
{
    return (7 -(key % 7)); //we use 7 as it it the closest prime number to 10
}

int probing(int H[], int key)
{
    int i = 0;
    while (H[(regular_hash_function(key) + i * second_hash_function(key)) % 10] != 0 && i < 10)
    {
        i++;
    }

    return (regular_hash_function(key) + i * second_hash_function(key)) % 10;

}

void insert(int H[], int key)
{
    int index = regular_hash_function(key);

    if (H[index] == 0)
    {
        H[index] = key;
    }
    else
    {
       index = probing(H, key);
       H[index] = key;
    }
}

int Search(int H[], int key)
{
    int index = regular_hash_function(key);

    int i = 0;
    while(H[(regular_hash_function(key) + i * second_hash_function(key)) % 10] != key && i < 10)
    {
        i++;
    }

    if (H[(regular_hash_function(key) + (i) * second_hash_function(key)) % 10] == key)
        return key;
    else
        return 0;
}



int main()
{
    int HT[10] = {0};
    insert(HT, 5);
    insert(HT, 25);
    insert(HT, 15);
    insert(HT, 35);
    insert(HT, 95);

    int i = 0;
    for(i = 0; i < 10; i++)
    {
        printf("%d ", HT[i]);
    }
    printf("\n");

    printf("%d ", Search(HT, 5));
    printf("%d ", Search(HT, 15));
    printf("%d ", Search(HT, 125));
    printf("%d ", Search(HT, 35));
    printf("%d ", Search(HT,45));
   
    return 0;
}