#include <stdio.h>

float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int main() {
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
           printf("the result is %f\n", multiply(num1,num2));
            break;
        case 4:
             printf("enter the first number:");
            scanf("%f",&num1);
            printf("enter the second number:");
            scanf("%f",&num2);
           printf("the result is %f\n", divide(num1,num2));
            break;
        default:
            break;
    }

    return 0;
}