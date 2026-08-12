#include <stdio.h>
#include "bank_customer.h"

int main() {
    Customer* head = NULL;

//     head = add_customer(head, "ahmed Yasser", 20000,"01064414572",222658);

//     // printf("%f\n", head->cash );
//     // printf("%s\n", head->name );
//     // printf("%s\n", head->phone );
//     // printf("%d\n", head->id );


//      head = add_customer(head, "mohamed ahmed", 20000,"01064414572",222678);

//     // printf("%f\n", head->next ->cash );
//     // printf("%s\n", head->next ->name );
//     // printf("%s\n", head->next ->phone );
//     // printf("%d\n", head->next ->id );

//     head = edit_customer(head,222658 ,"ahmed moh","01064414556");

//     // printf("%f\n", head->cash );
//     // printf("%s\n", head->name );
//     // printf("%s\n", head->phone );
//     // printf("%d\n", head->id );

//     view_customer(head, 222678);

//     delete_customer(head,222678);
    
//     view_customer(head, 222678);

//     add_customer(head, "ahmed hosam", 25000,"01065514572",222333);

//    head = transfer_money(head, 222333,222658, 5000);

//    view_customer(head, 222658);
//    view_customer(head, 222333);

//    head = deposit_money(head, 222333, 25000);

//    printf("========================================\n");
//    view_customer(head, 222333);
    head = add_customer(head, "ahmed Yasser", 20000,"01005224469",222658);
    head = add_customer(head, "mohamed ahmed", 20000,"01064414572",222678);
    head = add_customer(head, "ahmed hosam", 25000,"01065514572",222333);


    save_data(head);
    

    return 0;
}
