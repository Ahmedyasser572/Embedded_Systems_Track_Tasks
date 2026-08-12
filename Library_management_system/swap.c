#include <stdio.h>




void bubbel_sort(int* array);



int main()
{

    int arr[4] = {5,0,6,3};

    bubbel_sort(arr);

    for(int k = 0 ; k < 4; k++)
    {
        printf("%d", arr[k]);
    }


}


void bubbel_sort(int* array)
{
    int i =0;
    int temp = 0;

    for(i = 0 ; i < 4; i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            if( *(array + i) < *(array + j))
            {
            temp = *(array + i);
            *(array + i) = *(array + j);
            *(array + j) = temp;
            }
        }
    }
    for(int k = 0 ; k > 4; k++)
    {
        printf("%d", *(array + k));
    }
    

}



