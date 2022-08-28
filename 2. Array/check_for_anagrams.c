//check if two words are anagrams or not

#include<stdio.h>

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    int H[26] = {0};
    int i = 0

    for(i = 0; i != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }

    for(int i = 0, i != '\0'; i++)
    {
        H[B[i]] -= 1;
        if(H[A[i] - 97] < 0)
            {
                printf("not anagram")
                break;
            }
    }
}



