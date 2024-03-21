#include <stdio.h>
#include <stdbool.h>

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
        
        str[i] = ch;
        
    }

    str[i] = '\0';
    return i; 
}

 void seperate(char* str)
{
    int length = sizeof(str) / sizeof(str[0]);  // Get the length of the string (excluding null terminator)
    printf("\n");
    printf("Individual characters of the string '%s':\n", str);

    for (int i = 0; i < (length * 2) - 1; i++) {  // Loop through each character (excluding null terminator)
        printf("%c ", str[i]);  // Print the character with a space
    }

    printf("\n");

}





bool strcompare(char* str, char* str1)
{
    for(int i = 0; i < 15 && (str[i] != '\0' || str1[i] != '\0'); i++) {
        if (str[i] != str1[i])
            return false;
    }
    return true;
}


void copyString(char *str, char *str2) {
    int i = 0;
    while (str[i] != '\0') {
        str2[i] = str[i];
        i++;
    }
    str2[i] = '\0'; // Add null terminator to the destination string
}



int main() {
    char str[100];
    int n = input(str, 100);
    printf("%d %s", n, str);
    
    
   char* str1 = "ahmed yasser" ;
    // strcompare(str , str1);
    bool x = strcompare(str , str1);
    if (x)
    {   printf("\n");
        printf("Both of them is Identical");
    }
    seperate(str);
    char str2[20];

    copyString(str , str2);

    printf("%s\n", str2);


    
    return 0;
}
