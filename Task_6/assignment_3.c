#include<stdio.h> 
#define mysizeof(type) (char *)(&type+1)-(char*)(&type)

size_t my_sizeof(void* ptr);


int main() 
{ 
    double x; 
    printf("%ld", my_sizeof(x)); 
    getchar(); 
    return 0; 
}


size_t my_sizeof(void* ptr)
{
    
   int size = (int)((ptr+1) - ptr);

   return size;

}