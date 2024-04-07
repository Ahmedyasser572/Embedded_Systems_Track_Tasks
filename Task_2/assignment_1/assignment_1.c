#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  *p1;
    char *p2;
    long long int *p3;

    printf("%p\n%p\n%p\n", p1, p2, p3);
    p1++;
    p2++;
    p3++;

    printf("%p\n%p\n%p\n", p1, p2, p3);

    printf("An integer pointer that stores address 1000 is incremented, "
           "then it will increment by 4(size of an int), "
           "and the new address will point to 1004. "
           "Apply this role on the rest.\n");

    int *ptr;
    int hex = 0x66;

    ptr = &hex;

    (*ptr)++;
    printf("%x\n", *ptr);
    ++ptr;
    printf("%x\n", *ptr);
    ++(*ptr);
    printf("%x\n", *ptr);

    return 0;
}