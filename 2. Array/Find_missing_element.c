//given an array of sorted integar find the missing element

#include<stdio.h>

int main()
{
    int array1[10] = {2,3,5,8,9,12,13,14,16,20};
    int diff = 1;
    int increase = 1;
    for (int i = 0 ; i < 10; i++) {
        diff = array1[i+1] - array1[i];
        if (diff > 1)
        {
            while (diff > 1) 
            {
            printf("%d \n", array1[i] + increase++);
            diff = diff - 1;
            }
            
        } 

        increase = 1;
  }
  return 0;
}

/*int diff = array1[i] - i;
    for (int i = 0; i<SIZE; i++) {
        if (array1[i]-i !=  diff) {
            while (diff< array1[i] - i) {
            printf("%d ", i+diff);
            diff++;
            }
        }
    }
*/