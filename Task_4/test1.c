#include <stdio.h>
#include<string.h>

typedef struct {
  
  char name[50];
  int id;
  char class_id;
} Test;

int main() {
  Test myTest;
  myTest.id = 1;
  strncpy(myTest.name, "Test Name", sizeof(myTest.name));
  myTest.class_id = 'A';

  printf("%ld",sizeof(Test));

//   The size of a struct in C can change based on the order
// of the data types due to a concept known as "padding".
// Padding is added by the compiler to align data in memory, which can make accessing the data faster.

// In your struct, you have a char array of size 50, an int, and another char.
// The int type typically requires 4 bytes (on most modern systems),
// and the char type requires 1 byte. However, the int type is often aligned to 4 bytes, which means its starting address in memory is a multiple of 4.

// If you declare the int first in the struct, no padding is needed because the int is the first thing in the struct and can be aligned to a 4-byte boundary.
// But if you declare a char or char array first, the compiler will add padding before the int to align it to a 4-byte boundary.
// This padding increases the total size of the struct.

// So, in your case, if you change the order of the data types in the struct,
// the size can change due to the added padding.

  return 0;
}