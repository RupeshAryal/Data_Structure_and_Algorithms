#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    //int *A; //uncomment this to  use pointer
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    printf("elements are \n");
    for(i=0;i<arr.length;i++)
        printf("%d\n", arr.A[i]);
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if(index >=0 && index<arr->length)
    {   
        x = arr->A[index];
        for(i = index; i < arr->length; i++ )
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }

    return 0;
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index <= arr->length)
    {
        for(int i = arr->length; i>index; i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    struct Array arr1 = {{1,2,3,4,5}, 10,5};
   // int n, i;
   /* printf("enter the size of the array \n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("enter the number of numbers");
    scanf("%d", &n);


    printf("enter all the elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr.A[i]);

    }*/ //uncomment all of this too
    //arr.length = n;
    Append(&arr1,10);
    Insert(&arr1,0,12);
    Delete(&arr1,0);
    //Display(arr1);
   
return 0;
}