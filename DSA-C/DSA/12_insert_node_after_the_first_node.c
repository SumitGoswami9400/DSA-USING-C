/*assuming that you have a single linked list list and pointer ptr ponting to the first node of
that linked list write a c function to list insert a new node after the first node of the linked
list*/



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertafter(struct node *ptr)
{
    struct node *p = NULL;
    int x;
    p = (struct node *)malloc(sizeof(struct node)); // ptr = 1e

    printf("\nInsetr node:\n ");
    scanf("%d", &x);
    p->data = x;
    p->next = ptr->next;
    ptr->next = p;
}
void linkedlistTraversal(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("  %d  ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct node *head;

    head = (struct node *)malloc(sizeof(struct node));

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
            insertafter(head);
            break;
        case 2:
            printf("\nLinked list After inserting:\n");
            linkedlistTraversal(head);
            break;
        }
    }
    return 0;
}