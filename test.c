#include <stdio.h>




int main()
{

short int  x = 0xABCD;

char *ptr ;
char *ptr1;
ptr = &x;
ptr1 = ptr++;

printf("%x\n%x",*ptr,*ptr1);

char temp;

temp = *ptr;
*ptr = *ptr1;
*ptr1 = temp;

printf("\n%x",x);


}