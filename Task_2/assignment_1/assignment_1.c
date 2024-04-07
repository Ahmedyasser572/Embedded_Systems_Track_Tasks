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

    printf("the first increment was the value in the pointer\
the second it incremented but on the address with a step 4 bytes(size of integer)\
the third the same of the first but pre-increment rather than post-increment");

    return 0;
}