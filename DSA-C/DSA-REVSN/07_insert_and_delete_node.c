// Insertion and deletion in single linked list

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node*ptr){
    if(ptr == NULL){
        printf("Linked list is empty");
    }
    else{
        while(ptr != NULL){
            printf("%d  ",ptr->data);
            ptr = ptr->next;
        }
    }
}

 void insertafter(struct node *ptr){
        struct node *p = NULL;
        int x;
        p = (struct node*) malloc(sizeof(struct node));

        printf("\ninsert node element ");
        scanf("%d",&x);
        p->data = x;
        p->next = ptr->next;
        ptr->next = p;
        
    }

    struct node * insertbefore(struct node *ptr){
        struct node *p = NULL;
        int x;

        p = (struct node*) malloc(sizeof(struct node));
        printf("\ninsert node element ");
        scanf("%d",&x);

        p->data = x;
        p->next = ptr;
        ptr = p;

        return (ptr);
    }

int main(){
    struct node *head;
    head = (struct node*) malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;

    printf("Before inseerting linked list is\n");
    linkedlistTraversal(head);
    head = insertbefore(head);
    head = insertbefore(head);
    head = insertbefore(head);
    head = insertbefore(head);
    head = insertbefore(head);
    printf("\nAfter insertion linked list is ");
    linkedlistTraversal(head);
    return 0;
}