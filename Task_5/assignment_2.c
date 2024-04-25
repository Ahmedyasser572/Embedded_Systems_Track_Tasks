#include <stdio.h>

typedef enum ArithmeticOperation
{
    ADDITION ,
    SUBTRACTION ,
    MULTIPLICATION  ,
    DIVISION 
} operation;

int main()
{
    int num1, num2;
    operation operator;

    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("Enter arithmetic operation \n0 for addition\n1 for subtraction\n2 for multiplication\n3 for division \n");
    scanf(" %d", (int*)&operator);

    switch (operator)
    {
    case ADDITION:
        printf("Result: %d\n", (num1 + num2));
        break;
    case SUBTRACTION:
        printf("Result: %d\n", (num1 - num2));
        break;
    case MULTIPLICATION:
        printf("Result: %d\n", (num1 * num2));
        break;
    case DIVISION:
        printf("Result: %d\n", (num1 / num2));
        break;
    default:
        printf("Invalid operation!\n");
        break;
    }

    printf("the size of the enum is always 4 bytes");
    printf("the size of the enum = %ld", sizeof(operation));

    return 0;
}