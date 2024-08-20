// insert node in linked and display alternative nodes.
#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist{
    int data;
    struct linkedlist *next;
}ls;

void insert(ls **, ls**);
void deletef(ls**,ls**);
void disp(ls*);

int main(){
    ls *head = NULL,*r = NULL;
    int ch;
    while(1){
        printf("\n1-insert\n2-disp\n3-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert(&head,&r);
            break;

            case 2:
            disp(head);
            break;

            case 3:
            exit(0);
        }
    }
    return 0;
}

void insert(ls **head, ls **r){
    ls *p = NULL;
    int x;
    p = (ls*) malloc(sizeof(ls));
    if(p != NULL){
        printf("Enter value: ");
        scanf("%d",&x);
        p->data = x;

        if(*head == NULL && *r == NULL){
            *head = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
        }
        (*r)->next = NULL;
    }
}

void disp(ls *head){
    if(head == NULL){
        printf("Linked list is empty");
    }
    else{
        while(head != NULL){
            printf("%d  ",head->data);
            head = head->next->next;
        }
    }
}