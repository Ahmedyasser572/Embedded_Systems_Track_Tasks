#include <stdio.h>


void sortasc(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}



int main()
{

int array[10] = {9,3,5,2,6,7,8,10,12,56};
int x = 0x44220511;
char *ptr2;
char *ptr1;

for (int i= 0; i<8; i++)
{   ptr1 = &x;
    ptr2 = ptr1++;
    // printf("%x\n%x",*ptr1,*ptr2);

    for(int j = 0;j<=2;j++)
    {
    if (*ptr1 > *ptr2)
    {
        char temp;
        // printf("sss\n");
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
    }
    ptr1++;
    ptr2++;
    
    // printf("%X\n",x);
    }
}


printf("%X",x);


// sortasc(array,10);


//  printf("Sorted numbers: ");
//     for (int i = 0; i < 10; i++) {
//         printf("%d ", array[i]);
//     }






}