#include <stdio.h>

/**
 * @brief 
 * 
 * The String data type represents a sequence of characters in C.
 * It is commonly used for storing and manipulating text.
 * 
 * In this program, we will define a String variable and perform some basic operations on it.
 * and input string and print it 
 */

int input(char str[], int n) 
{
    int ch;
    int i;
    for (i = 0; ((ch = getchar()) != '\n') && i < n - 1; i++) {
        // if (ch == ' ') {
            
        //     while ((ch = getchar()) == ' ' && i < n - 1);
        //     ungetc(ch, stdin); // Put the non-space character back into input stream
        // }
        str[i] = ch;
        
    }

    str[i] = '\0';
    return i; 
}

int main() {
    char str[100];
    int n = input(str, 100);
    printf("%d %s", n, str);
    return 0;
}
