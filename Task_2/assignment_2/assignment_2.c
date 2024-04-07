#include <stdio.h>
#include <stdlib.h>

int increment(int x)
{
    ++x;
    return x;
}

int main(void)
{
    int (*y)(int) = increment;
    int x = 4;

    x = (*y)(x);

    printf("%d\n", x);

    int *ptr_array;
    int array[5]={1,2,3,4,5};

    ptr_array = array;

    printf("Printing array using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr_array);
        ptr_array++;
    }
    return 0;
}
