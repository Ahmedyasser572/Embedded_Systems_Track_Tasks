#include <stdio.h>

#define SIZE 10
// #define ORDER DESCENDING

// #define ASCENDING 1
// #define DESCENDING 0
#define add(x,y)         (x+y)
#define subtract(x,y)    (x-y)

void sortasc(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortdesc(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];

    printf("Enter %d numbers: ", SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

#ifdef ORDER 
    sortasc(arr,SIZE);
#else
    sortdesc(arr,SIZE);
#endif

    printf("Sorted numbers: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}