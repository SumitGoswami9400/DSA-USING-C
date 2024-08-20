/*assuming that you have a single linked list list and pointer ptr ponting to the first node of
that linked list write a c function to list insert a new node before the first node of the linked
list*/


#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node* ptr){

    while(ptr != NULL){
        printf("  %d  ",ptr->data);
        ptr = ptr->next;
    }
}

struct node* insertnodeAtbegining(struct node *ptr){   // ptr = 1e
    struct node *p = NULL;
    int x; 
    p =(struct node*) malloc(sizeof(struct node));    // p = 3e 
    p->next = ptr;
    printf("\nInsert node: ");
    scanf("%d",&x);
    p->data = x;
    return (p);

}


int main(){
    struct node *head;

    head = (struct node*) malloc(sizeof(struct node));

    head->data = 10;
    head->next = NULL;

    printf("Linked list before inserting:\n");
    linkedlistTraversal(head);
    while (1)
    {
        int ch;
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insertnodeAtbegining(head);
            break;
        case 2:
            printf("\nLinked list After inserting:\n");
            linkedlistTraversal(head);
            break;
        }
    }
}

