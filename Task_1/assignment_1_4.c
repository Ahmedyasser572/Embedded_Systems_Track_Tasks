#include <stdio.h>

/**
 * @brief 
 *
 * This program takes two integer numbers as input and adds them together
 * by passing them by reference. The result is stored in the first number.
 *
 * @param[in,out] num1 The first number to be added.
 * @param[in] num2 The second number to be added.
 */
 
void addNumbers(int* num1, int *num2);

int main() {
    int num1 = 5;
    int num2 = 10;

    addNumbers(&num1, &num2);

    printf("The sum is: %d\n", num1);

    return 0;
}

void addNumbers(int* num1, int *num2) {
    *num1 += *num2;
}
 