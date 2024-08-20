/*assuming you have a single linked list and the first node of the linked 
list pointed by a pointer ptr then write a c function to convert this 
single linked list into circular linked list*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d   ", ptr->data);
        ptr = ptr->next;
    }
}

void sTOcircular(struct node *head){
    struct node *ptr = NULL;
    ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = head;

    struct node *p = head;
    do{
        printf("%d   ",p->data);
        p = p->next;
    }while(p != head);
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

    printf("\nGiven circular linked list: \n");
    linkedlistTraversal(head);
    printf("\nAfter converting single linked list into circular linked list: \n");
    sTOcircular(head);
    return 0;
}