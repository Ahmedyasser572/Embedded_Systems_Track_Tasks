#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *Next;
};

void print_list_data(struct node *Head) {
    if (Head == NULL) {
        printf("The list is empty ");
        return;
    }

    struct node *ptr = Head;
    printf("Head");
    while(ptr != NULL) {
        printf ("->%d", ptr->data);
        ptr = ptr->Next;
    }
    printf("->END\n");
}

void Insert_at_first(struct node **Head, int Value) {
    struct node *link = (struct node *) malloc(sizeof(struct node));
    link->data = Value;
    link->Next = *Head;
    *Head = link;
}

void insert_at_the_end(struct node **Head, int Value) {
    struct node *ptr = *Head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = Value;
    temp->Next = NULL;

    if (ptr == NULL) {
        *Head = temp;
        return;
    }

    while (ptr->Next != NULL) {
        ptr = ptr->Next;
    }
    ptr->Next = temp;
}

void delete_from_end(struct node **Head) {
    if (*Head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *second_last = *Head;
    struct node *last = (*Head)->Next;

    if (last == NULL) {
        free(*Head);
        *Head = NULL;
        return;
    }

    while (last->Next != NULL) {
        second_last = last;
        last = last->Next;
    }

    free(last);
    second_last->Next = NULL;
}

int main() {
    struct node *head = NULL;
    char operator;
    int value = 66;



    while(1) {

         // You need to add code here to get the operator value
    printf("+ to add a node\n");
    printf("- to delete the last node you add\n");
    printf("p to print list\n");
    printf("x to stop the program\n");
    scanf("%c",&operator);

        switch(operator) {
            case '+': 
                insert_at_the_end(&head, value++);
                printf("\n\n");
                break;
            case '-':
                delete_from_end(&head);
                printf("\n\n");
                break;
            case 'p':
                print_list_data(head);
                printf("\n\n");
                break;
            case 'x':
            printf("\n\n");
                return 0;
                
        }
    }
}