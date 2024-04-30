#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{

    int *ptr;
    float *ptr1;
    char *ptr2;


    ptr = (int*)malloc(sizeof(int)*4);

    if (ptr == NULL)
        {
            fprintf(stderr,"the allocation failed");
            return 1;
        }

    *ptr = 10 ; 


    ptr1 = (float*)calloc(1, sizeof(float));

    if (ptr1 == NULL)
        {
            fprintf(stderr,"the allocation failed");
            free(ptr);// Free previously allocated memory
            return 1;
        }
    *ptr1 = 55.66;

    ptr2 = (char*)malloc(20 * sizeof(char));
    if (ptr2 == NULL) {
        fprintf(stderr, "Memory allocation for character array failed!\n");
        free(ptr); // Free previously allocated memory
        free(ptr1); // Free previously allocated memory
        return 1;
    }

    strncpy(ptr2, "Hello, world!", 20);

    printf("Integer value: %d\n", *ptr);
    printf("Float value: %f\n", *ptr1);
    printf("String value: %s\n", ptr2);

    ptr1 = (float*)realloc(ptr1, 2*sizeof(float));
    ptr1[1] = 15.44;

    printf("Integer values after reallocation: %f %f\n", ptr1[0], ptr1[1]);

    free(ptr);

    long int* ptr_nint;

    ptr_nint = (int*)malloc(sizeof(long int)*2);

    printf("we can use this method if we have tempororliy variable to achieve some tasks\
then free the memroy for another variable");





    free(ptr);
    free(ptr1);
    free(ptr2);

}




