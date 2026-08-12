#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_STATUS_LENGTH 50

typedef struct
{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publication_year;
    int num_copies;
    float price;
    char status[MAX_STATUS_LENGTH];
} Book;



void add_book(char *title, char *author, int publication_year, int num_copies, float price, char *status);
void delete_book(char *title);
void borrow_book(char *title);
void buy_book(char *title);
void print_library();
void search_highest_price_book();
void search_book(char *title);

