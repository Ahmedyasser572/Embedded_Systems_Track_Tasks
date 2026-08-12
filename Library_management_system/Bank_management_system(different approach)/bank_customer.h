#ifndef BANK_CUSTOMER_H
#define BANK_CUSTOMER_H

#define NAME_MAX 100
#define PHONE_MAX 20

typedef struct Customer {
    char name[NAME_MAX];
    double cash;
    char phone[PHONE_MAX];
    int id;
    struct Customer* next;
} Customer;

// Customer management
Customer* add_customer(Customer* head, const char* name, double cash, const char* phone, int id);
Customer* edit_customer(Customer* head, int id, const char* new_name, const char* new_phone);
void view_customer(Customer* head, int id);
Customer* delete_customer(Customer* head, int id);
Customer* transfer_money(Customer* head, int from_id, int to_id, double amount);
Customer* deposit_money(Customer* head, int id, double amount);
Customer* withdraw_money(Customer* head, int id, double amount);
Customer * Load_data(Customer *head);
void save_data(Customer *head);

#endif // BANK_CUSTOMER_H
