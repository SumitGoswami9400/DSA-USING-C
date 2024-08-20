// delete last node single in linked list 


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linkedlistTraversal(struct node *head){
    
    while(head != NULL){
        printf("  %d  ",head->data);
        head = head->next;
    }
}

struct node* deleteatlast(struct node *head){
    struct node *ptr = head;
    struct node *p = head->next;

    while(p->next != NULL){
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return (head);

}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;
    struct node *sixth;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));
    fifth = (struct node*) malloc(sizeof(struct node));
    sixth = (struct node*) malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = fourth;
    fourth->data = 40;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = sixth;
    sixth->data = 60;
    sixth->next = NULL;

    printf("Linked list Before deleting\n");
    linkedlistTraversal(head);
    head = deleteatlast(head);
    printf("\nLinked list After deleting\n");
    linkedlistTraversal(head);
    return 0;
}