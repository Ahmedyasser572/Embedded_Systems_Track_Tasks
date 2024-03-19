#include <stdio.h>

void CountFrequency(int * array ,int size);
/*
 * This program counts the frequency of each element in an array without using a function.
 * It takes an array of integers as input and prints the frequency of each element.
 */

int main() {
    int array[16] = {1,1,2,3,4,5,4,5,7,8,9,9,10,10,12,15};
    int size = 16 ;

    CountFrequency(array, size);
    return 0;
}

void CountFrequency(int* array, int size)
{
    int counter = 1 ; 
    // for (int i = 0 ; i > size; i++ )
    // {
    //     printf("Please Enter the array elements:");
    //     scanf("%d",&array[i]);
    // }

    for (int i = 0; i < size ; i++)
    {
        counter = 1;
         for (int j = i - 1; j >= 0; j--) // Check if the number has been counted before
        {
            if(array[i] == array[j])
            {
                goto skip; // Skip this number if it has been counted before
            }
        }

        for (int j = 0 ; j < size;j++)
            {
                if((array[i] == array[j]) && (i != j)) // to compare the elements and avoide comparing to itself
                    {
                        counter++;
                    }
            }

            printf("%d apperared %d times\n", array[i], counter);
            skip: ;
            
    }
}
          







