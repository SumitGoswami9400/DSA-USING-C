#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void insert(struct node**,struct node**);
void count(struct node*);

int main(){
    struct node *l=NULL , *r = NULL;
    int ch;

    while(1){
        printf("\n1-insert\n2-cound-disp\n3-exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);


        switch(ch){
            case 1:
            insert(&l,&r);
            break;

            case 2:
            count(l);
            break;

            case 3:
            exit(0);
        }
    }
    return 0;
}

void insert(struct node **l,struct node **r){
    struct node *p = NULL;
    int x;
    p = (struct node*) malloc(sizeof(struct node));
    if(p != NULL){
        printf("Enter value ");
        scanf("%d",&x);
        p->data = x;
        if(*l == NULL && *r == NULL){
            *l = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
        }
        (*r)->next = NULL;
    }
}

void count(struct node *l){
    int count = 0;
    if(l == NULL){
        printf("linked list is empty");
    }
    else{
        while(l != NULL){
            count++;
            printf("%d  ",l->data);
            l = l->next;
        }
        printf("\nTotal %d Nodes present in linked list: ",count);
    }
}