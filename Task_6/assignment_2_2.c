#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str[MAX_LEN];
    int freq[256] = {0};

    while(1) {
        printf("Enter a string (or \"!!\" to stop): ");
        fgets(str, MAX_LEN, stdin); //it handels the space better \
         better than scanf and the input function.

        // Remove trailing newline character
        str[strcspn(str, "\n")] = 0;

        // Check for stop code
        if(strcmp(str, "!!") == 0) {
            break;/*it will break and close the program*/
        }
        // Calculate frequency of each character by converting to integer and put it 
        // the index 
        for(int i = 0; str[i] != '\0'; i++) {
            freq[(int)str[i]]++;
        }

        // Print unique characters if it is it more than one it means that letter 
        // existed more than one time 
        printf("Unique characters: ");
        for(int i = 0; i < 256; i++) {
            if(freq[i] == 1) {
                printf("%c ", i);
            }
            // Reset frequency array for next input
            freq[i] = 0;
        }
        printf("\n");
    }

    return 0;
}