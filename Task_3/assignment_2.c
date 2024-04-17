#include <stdio.h>
#define add(x,y)         (x+y)
#define subtract(x,y)    (x-y)
#define mul(x,y)         ((x)*(y))
#define div(x,y)         (x/y)


int main()
{
    float num1, num2;
    int operation;

    printf("choose the operation\n\
1-additon\n2-subtration\n3-multiblication\n4-divion\n");

scanf("%d",&operation);
    

    switch (operation) {
        case 1:
            printf("enter the first number:");
            scanf("%f",&num1);
            printf("enter the second number:");
            scanf("%f",&num2);
            printf("the result is %f\n", add(num1,num2));
            break;
        case 2:
            printf("enter the first number:");
            scanf("%f",&num1);
            printf("enter the second number:");
            scanf("%f",&num2);
            printf("the result is %f\n", subtract(num1,num2));
            break;
        case 3:
             printf("enter the first number:");
            scanf("%f",&num1);
            printf("enter the second number:");
            scanf("%f",&num2);
           printf("the result is %f\n", mul(num1,num2));
            break;
        case 4:
             printf("enter the first number:");
            scanf("%f",&num1);
            printf("enter the second number:");
            scanf("%f",&num2);
           printf("the result is %f\n", div(num1,num2));
            break;
        default:
            break;
    }

    return 0;
}