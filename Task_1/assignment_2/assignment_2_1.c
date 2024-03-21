#include <stdio.h>

/**
 * @brief This program demonstrates the declaration of variables and pointers.
 * 
 * This program declares three variables and three pointers without initializing them.
 * It serves as an example of variable and pointer declaration in C programming.
 */

int main() {
    int x, y, z; // Declaration of three variables

    int* p, *q, *r; // Declaration of three pointers

    x = 6;
    y = 7;
    z = 11;

   p = &x;
   q = &y;
   r = &z;

    printf("%d\n%d\n%d\n%p\n%p\n%p\n%d\n%d\n%d\n",x, y, z,p,q,r,*p,*q,*r);

    
    return 0;
}
