#include <stdio.h>
#include <stdlib.h>


int main()
{

    int array[14] = {1, 2, 4, 1, 5, 5, 7, 7, 11, 12, 13, 9 ,10};
    int ans[25] = {};
   int counter = 0 ;
   int x = 0;

    for (int i = 0; i < 14 ; i++)
    {
        counter = 0;
        for (int j = 0 ; j < 14;j++)
            {
                if((array[i] == array[j]) && (i != j))
                    {
                        counter++;
                    }
            }
            if (counter == 0)
          {
            ans[x] = array[i];
            x++;
          }

    }

   for (int k = 0; k < 20 ; k++)
   {
       if(ans[k] == 0)
       continue;

       printf("%d ", ans[k]);


   }

}
