#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"




int main()
{
    int choice;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int publication_year;
    int num_copies;
    float price;
    char status[MAX_STATUS_LENGTH];

    while (1)
    {
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
        printf("\n\n\t\t\t\t      Library Management System");
        printf("\n\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t\t1. Add Book");
        printf("\n\t\t\t\t2. Delete Book");
        printf("\n\t\t\t\t3. Borrow Book");
        printf("\n\t\t\t\t4. Buy Book");
        printf("\n\t\t\t\t5. Print Library");
        printf("\n\t\t\t\t6. Search Book By Title");
        printf("\n\t\t\t\t7. Search Highest Price Book");
        printf("\n\t\t\t\t8. Exit");
        printf("\n\n\t\t\t\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\t\t\t\tEnter the title of the book: ");
            scanf("%s", title);
            printf("\n\t\t\t\tEnter the author of the book: ");
            scanf("%s", author);
            printf("\n\t\t\t\tEnter the publication year of the book: ");
            scanf("%d", &publication_year);
            printf("\n\t\t\t\tEnter the number of copies of the book: ");
            scanf("%d", &num_copies);
            printf("\n\t\t\t\tEnter the price of the book: ");
            scanf("%f", &price);
            printf("\n\t\t\t\tEnter the status of the book: ");
            scanf("%s", status);
            add_book(title, author, publication_year, num_copies, price, status);
            break;
        case 2:
            printf("\n\t\t\t\tEnter the title of the book: ");
            scanf("%s", title);
            delete_book(title);
            break;
        case 3:
            printf("\n\t\t\t\tEnter the title of the book: ");
            scanf("%s", title);
            borrow_book(title);
            break;
        case 4:
            printf("\n\t\t\t\tEnter the title of the book: ");
            scanf("%s", title);
            buy_book(title);
            break;
        case 5:
            print_library();
            break;
        case 6:
           printf("\n\t\t\t\tEnter the title of the book: ");
            scanf("%s", title);
            search_book(title);
            break;
        case 7:
            search_highest_price_book();
            break;
            case 8:
            exit(0);
            break;
        default:
            printf("\n\t\t\t\tInvalid Choice");
            break;
        }
    }
    return 0;
}


   
            
