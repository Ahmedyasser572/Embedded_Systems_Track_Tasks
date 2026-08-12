#include "bank_customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



Customer* add_customer(Customer* head, const char *name, double cash, const char* phone, int id)
{   
    // initializing the parameters of the customer 
    Customer *  newPtr = malloc(sizeof(Customer));

    if (newPtr ==NULL){
    printf("allocation failed");
    }

    for (int i =0 ; i < strlen(name);i++)
    {
        newPtr -> name[i] = name[i];
    }
    newPtr -> cash = cash;
    for (int j =0 ; j< strlen(phone);j++)
    {
        newPtr -> phone[j] = phone[j];
    }
    newPtr -> id = id;
    newPtr -> next = NULL;

    if (head == NULL)
    {
        head = newPtr;
        return head;
    }

    Customer *current = head ;

    while (current->next != NULL)
    {
        current = current -> next;
    }
    current -> next = newPtr;

    return head;

}


Customer* edit_customer(Customer* head, int id, const char* new_name, const char* new_phone)
{
    Customer * current = head;
   while(current != NULL && current-> id != id ){
        current = current -> next ;
    }

    if (current == NULL)
    {
        printf("The id is wrong or unavailable");
        return head;
    }


    if (current-> id == id)
    {

        for (int k =0 ; k < strlen(current->name);k++)
    {
        current -> name[k] = '\0';
    }


    for (int i =0 ; i < strlen(new_name);i++)
    {
        current -> name[i] = new_name[i];
    }
    current->name[strlen(new_name)] = '\0';

    for (int j =0 ; j < strlen(new_phone);j++)
    {
        current -> phone[j] = new_phone[j];
    }
    }

    return head;
}




void view_customer(Customer* head, int id)
{
    Customer * current = head;
    while(current != NULL && current-> id != id ){
        current = current -> next ;
    }

    if (current == NULL)
    {
        printf("The id is wrong or unavailable\n");
        return;
    }

  else if(current-> id == id)
    {
        printf( "the Name is %s \n",current -> name) ;
        printf( "the id is %d \n",current -> id) ;
        printf( "the phone is %s\n ",current -> phone) ;
        printf( "the cash is %2.f \n",current -> cash) ;
    }

}
Customer * delete_customer(Customer* head, int id)
{   
    int counter = 0;
    Customer * current = head;
    Customer * prev = NULL;
    while(current-> id != id && current != NULL ){
        prev = current;
        current = current -> next;
        counter++;
    }

    if (current-> id != id || current == NULL)
    {
        printf("The id is wrong or unavailable");
        return head;
    }
if (prev == NULL) {
        head = current->next;  // Move head to next node
    } 
    // Case 2: Deleting non-head node
    else {
        prev->next = current->next;  // Bridge the gap
    }
    
    free(current);  // Free memory
    printf("The customer deleted successfully\n");

    return head;
}

Customer* transfer_money(Customer* head, int from_id, int to_id, double amount)
{
    Customer * sender = head;
    Customer * receiver = head;

   while(sender != NULL && sender->id != from_id) {
        sender = sender->next;
    }

    // Find receiver - FIXED: Check NULL first  
    while(receiver != NULL && receiver->id != to_id) {
        receiver = receiver->next;
    }

     if ( receiver == NULL || sender == NULL ||  receiver-> id != to_id || sender-> id != from_id)
    {
        printf("The id is wrong or unavailable\n");
        return head;
    }

    if (sender -> cash <= amount)
    {
        printf("The sender doesn't have enough cash");
        return head;
    }

    sender -> cash -= amount;
    receiver -> cash += amount;

    printf("Transfer successful! %.2f transferred from ID %d to ID %d\n", 
           amount, from_id, to_id);

    return head;
}
Customer* deposit_money(Customer* head, int id, double amount)
{
   Customer * current = head;

    while(current != NULL != id && current-> id != id ){
        current = current -> next ;
    }

    if (current == NULL)
    {
        printf("The id is wrong or unavailable\n");
        return head;
    }

    current -> cash += amount;

    printf("The depoiste completed successfully\n");

    return head;
}
Customer* withdraw_money(Customer* head, int id, double amount)
{
    Customer * current = head;

    while(current != NULL != id && current-> id != id ){
        current = current -> next ;
    }

    if (current == NULL)
    {
        printf("The id is wrong or unavailable\n");
        return head;
    }

    current -> cash -= amount;

    printf("The depoiste completed successfully\n");

    return head;
}

Customer * Load_data(Customer *head){
    FILE* myfile;
    char name[NAME_MAX];
    double cash;
    char phone[PHONE_MAX];
    int id;
    
    myfile = fopen("customer.txt", "r");
    
    if (myfile == NULL) {
        printf("No existing data file found. Starting with empty database.\n");
        return head;
    }
    
    // Read each customer record from file
    while (fscanf(myfile, "%s %lf %s %d", name, &cash, phone, &id) == 4) {
        head = add_customer(head, name, cash, phone, id);
    }
    
    fclose(myfile);
    printf("Customer data loaded successfully.\n");
    
    return head;
}

void save_data(Customer *head){
    FILE* myfile;
    Customer* current = head;
    
    myfile = fopen("customer.txt", "w");
    
    if (myfile == NULL) {
        printf("Error: Unable to open file for saving.\n");
        return;
    }
    
    // Write each customer record to file
    while (current != NULL) {
        fprintf(myfile, "%s %.2f %s %d\n", 
                current->name, 
                current->cash, 
                current->phone, 
                current->id);
        current = current->next;
    }
    
    fclose(myfile);
    printf("Customer data saved successfully.\n");
}