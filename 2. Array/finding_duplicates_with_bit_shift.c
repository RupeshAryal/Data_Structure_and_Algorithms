//using bit shifting operations to find duplicates in a string

#include<stdio.h>

int main()
{
    char A[] = "rruuppeesshh";
    int h = 0, x = 0;

    for(int i = 0; A[i]!= '\0'; i++)
    {
        x = 1;
        x = x<<(A[i]-97);

        if ((x & h) > 0)
            printf("%c is duplicate \n", A[i]);
        else
            h = x|h;
    }

    return 0;
}