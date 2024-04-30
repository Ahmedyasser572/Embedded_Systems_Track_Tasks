#include <stdio.h>
#include <stdlib.h>
#define my_sizeof(ptr)  (char *)(&ptr+1)-(char *)(&ptr)

// char* my_sizeof(void* ptr)
// {

//    char size = 0;
//    size = (char *)(ptr+1)-(char *)(ptr);
   

//    return size;

// }
int main()
{
    int x;
    printf("%ld\n", my_sizeof(x));

    int* ptr = &x;

    //printf("%x\n",(ptr) );
    printf("%ld\n",(char *)(ptr+1)-(char *)(ptr) );
    return 0;
}

