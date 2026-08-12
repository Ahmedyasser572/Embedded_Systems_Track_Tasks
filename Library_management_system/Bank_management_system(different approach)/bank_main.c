#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_customer.h"

#define BLUE "\x1b[36m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"

static void clear_screen(void) { system("cls"); }
static void pause_screen(void) { printf("\nPress Enter to continue..."); getchar(); }
static void show_customers(Customer *head) {
    printf("\n%-8s %-25s %-15s %12s\n", "ID", "NAME", "PHONE", "BALANCE");
    printf("---------------------------------------------------------------\n");
    for (Customer *current = head; current != NULL; current = current->next)
        printf("%-8d %-25s %-15s %12.2f\n", current->id, current->name, current->phone, current->cash);
}

int main(void) {
    Customer *head = Load_data(NULL);
    int choice, id, from_id, to_id;
    double amount;
    char name[NAME_MAX], phone[PHONE_MAX];

    do {
        clear_screen();
        printf(BLUE "==============================================\n" RESET);
        printf(BLUE "              SMART BANK SYSTEM              \n" RESET);
        printf(BLUE "==============================================\n" RESET);
        printf("  1. Add customer       5. Deposit money\n");
        printf("  2. View customer      6. Withdraw money\n");
        printf("  3. Edit customer      7. Transfer money\n");
        printf("  4. Delete customer    8. Show all customers\n");
        printf("  0. Save and exit\n\nChoose an option: ");
        if (scanf("%d", &choice) != 1) { while (getchar() != '\n'); choice = -1; }
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printf("Name: "); fgets(name, NAME_MAX, stdin); name[strcspn(name, "\n")] = 0;
            printf("Phone: "); fgets(phone, PHONE_MAX, stdin); phone[strcspn(phone, "\n")] = 0;
            printf("ID: "); scanf("%d", &id);
            printf("Opening balance: "); scanf("%lf", &amount); while (getchar() != '\n');
            head = add_customer(head, name, amount, phone, id); printf(GREEN "Customer added.\n" RESET); pause_screen(); break;
        case 2: printf("Customer ID: "); scanf("%d", &id); while (getchar() != '\n'); view_customer(head, id); pause_screen(); break;
        case 3:
            printf("Customer ID: "); scanf("%d", &id); while (getchar() != '\n');
            printf("New name: "); fgets(name, NAME_MAX, stdin); name[strcspn(name, "\n")] = 0;
            printf("New phone: "); fgets(phone, PHONE_MAX, stdin); phone[strcspn(phone, "\n")] = 0;
            head = edit_customer(head, id, name, phone); printf(GREEN "Customer updated.\n" RESET); pause_screen(); break;
        case 4: printf("Customer ID: "); scanf("%d", &id); while (getchar() != '\n'); head = delete_customer(head, id); pause_screen(); break;
        case 5: printf("Customer ID: "); scanf("%d", &id); printf("Amount: "); scanf("%lf", &amount); while (getchar() != '\n'); head = deposit_money(head, id, amount); pause_screen(); break;
        case 6: printf("Customer ID: "); scanf("%d", &id); printf("Amount: "); scanf("%lf", &amount); while (getchar() != '\n'); head = withdraw_money(head, id, amount); pause_screen(); break;
        case 7: printf("From ID: "); scanf("%d", &from_id); printf("To ID: "); scanf("%d", &to_id); printf("Amount: "); scanf("%lf", &amount); while (getchar() != '\n'); head = transfer_money(head, from_id, to_id, amount); pause_screen(); break;
        case 8: show_customers(head); pause_screen(); break;
        case 0: save_data(head); printf(GREEN "Data saved. Goodbye!\n" RESET); break;
        default: printf(RED "Invalid option.\n" RESET); pause_screen();
        }
    } while (choice != 0);

    while (head != NULL) { Customer *next = head->next; free(head); head = next; }
    return 0;
}
