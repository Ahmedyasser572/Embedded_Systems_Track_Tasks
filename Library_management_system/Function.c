#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

Book library[MAX_BOOKS];
int num_books = 0;


void add_book(char *title, char *author, int publication_year, int num_copies, float price, char *status)
{
    if (num_books >= MAX_BOOKS)
    {
        printf("\n\n\t\t\t   Error: Library is full\n");
        return;
    }
    if (strlen(title) > MAX_TITLE_LENGTH || strlen(author) > MAX_AUTHOR_LENGTH || strlen(status) > MAX_STATUS_LENGTH)
    {
        printf("\n\n\t\t\t   Error: Input fields exceed maximum length\n");
        return;
    }
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i].title, title) == 0 && strcmp(library[i].author, author) == 0 && library[i].publication_year == publication_year)
        {
            printf("\n\n\t\t\t   Error: Book already exists in library\n");
            return;
        }
    }
    Book new_book;
    strcpy(new_book.title, title);
    strcpy(new_book.author, author);
    new_book.publication_year = publication_year;
    new_book.num_copies = num_copies;
    new_book.price = price;
    strcpy(new_book.status, status);
    library[num_books] = new_book;
    num_books++;
    printf("\n\n\t\t\t   Book added successfully\n");
}

void delete_book(char *title)
{
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i].title, title) == 0)
        {
            for (int j = i; j < num_books - 1; j++)
            {
                library[j] = library[j + 1];
            }
            num_books--;
            printf("\n\n\t\t\t   Book deleted successfully\n");
            return;
        }
    }
    printf("\n\n\t\t\t   Error: Book not found\n");
}
void borrow_book(char *title)
{
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i].title, title) == 0)
        {
            if (library[i].num_copies == 0)
            {
                printf("\n\n\t\t\t   Error: No copies of book available\n");
                return;
            }
            library[i].num_copies--;
            printf("\n\n\t\t\t   Book borrowed successfully\n");
            return;
        }
    }
    printf("\n\n\t\t\t   Error: Book not found\n");
}

void buy_book(char *title)
{
    for (int i = 0; i < num_books; i++)
    {
        if (strcmp(library[i].title, title) == 0)
        {
            library[i].num_copies++;
            printf("\n\n\t\t\t   Book bought successfully\n");
            return;
        }
    }
    printf("\n\n\t\t\t   Error: Book not found\n");
}

void print_library()
{
    for (int i = 0; i < num_books; i++)
    {
        printf("\n\n\t\t\t   Title: %s\n", library[i].title);
        printf("\n\n\t\t\t   Author: %s\n", library[i].author);
        // printf("\n\n\t\t\t   Publication Year: %d\n", library[i].publication_year);
        // printf("\n\n\t\t\t   Number of Copies: %d\n", library[i].num_copies);
        // printf("\n\n\t\t\t   Price: %.2f\n", library[i].price);
        // printf("\n\n\t\t\t   Status: %s\n", library[i].status);
        // printf("\n");
    }
}

void search_book(char *title) {
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("\n\n\t\t\t   Title: %s\n", library[i].title);
            printf("\n\n\t\t\t   Author: %s\n", library[i].author);
            printf("\n\n\t\t\t   Publication Year: %d\n", library[i].publication_year);
            printf("\n\n\t\t\t   Number of Copies: %d\n", library[i].num_copies);
            printf("\n\n\t\t\t   Price: %.2f\n", library[i].price);
            printf("\n\n\t\t\t   Status: %s\n", library[i].status);
            printf("\n");
            return;
        }
    }
    printf("Error: Book not found\n");
}

void search_highest_price_book() {
    if (num_books == 0) {
        printf("Error: Library is empty\n");
        return;
    }
    int highest_price_index = 0;
    for (int i = 1; i < num_books; i++) {
        if (library[i].price > library[highest_price_index].price) {
            highest_price_index = i;
        }
    }
    printf("\n\n\t\t\t   Title: %s\n", library[highest_price_index].title);
    printf("\n\n\t\t\t   Author: %s\n", library[highest_price_index].author);
    printf("\n\n\t\t\t   Publication Year: %d\n", library[highest_price_index].publication_year);
    printf("\n\n\t\t\t   Number of Copies: %d\n", library[highest_price_index].num_copies);
    printf("\n\n\t\t\t   Price: %.2f\n", library[highest_price_index].price);
    printf("\n\n\t\t\t   Status: %s\n", library[highest_price_index].status);
    printf("\n");
}