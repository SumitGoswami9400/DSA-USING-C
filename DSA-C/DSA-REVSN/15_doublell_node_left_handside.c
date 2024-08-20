#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};


void insert(struct node**);
void disp(struct node*);

int main(){
    struct node *head = NULL;
    int ch;
     while(1){
        printf("\n1-insert\n2-disp\n3-exit");
        printf("\nEnter your choice  ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert(&head);
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

void insert(struct node **ptr){
    struct node *p;
    int x;
    p = (struct node*) malloc(sizeof(struct node));

    if(p != NULL){
        printf("\nEnter value ");
        scanf("%d",&x);
        p->data = x;
        if(*ptr == NULL){
            p->next = NULL;
            *ptr = p;
        }
        else{
        p->next = *ptr;
        (*ptr)->prev = p;
        *ptr = p;
        }
        (*ptr)->prev = NULL;
    }
}

void disp(struct node *head){
    if(head == NULL){
        printf("linked list is empty ");
    }
    else{
        while(head != NULL){
            printf("%d  ",head->data);
            head = head->next;
        }
    }
}