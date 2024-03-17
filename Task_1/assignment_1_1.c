#include <stdio.h>
#include <stdlib.h>

/*
a) Write a program that finds the duplicate elements 
in an array of 14 integers. The array is as follows:
1, 2, 4,1, 5, 5, 7, 7, 11, 12, 13, 9 ,10

*/

int main()
{

    int array[14] = {1, 2, 4,1, 5, 5, 7, 7, 11, 12, 13, 9 ,10};
    int ans[25] = {};
   int counter = 0 ;

    for (int i = 0; i < 14 ; i++)
    {
        for (int j = i+1 ; j < 14;j++)
            {
                if(array[i] == array[j])
                    {
                   // printf("%d", array[i]);
                    counter++;
                    ans[counter] = array[i]; // store the duplicate value in the array

                    }
            }
    }

   for (int k = 0; k < 20 ; k++)
   {
       if(ans[k] == 0)
       continue;

       printf("%d ", ans[k]); // print the duplicate values


   }

}