#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};



void insert(struct node**,struct node**);
void disp(struct node*);

int main(){
    struct node *l = NULL,*r=NULL;
    int ch;
     while(1){
        printf("\n1-insert\n2-disp\n3-exit");
        printf("\nEnter your choice  ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert(&l,&r);
            break;

            case 2:
            disp(l);
            break;

            case 3:
            exit(0);
        }
    }
    return 0;
}

void insert(struct node **l,struct node **r){
    struct node *p;
    int x;
    p = (struct node*) malloc(sizeof(struct node));

    if(p != NULL){
        printf("\nEnter value ");
        scanf("%d",&x);
        p->data = x;
        if(*l==NULL && *r==NULL){
            *l=*r=p;
        }
        else{

        }
        (*r)->next = NULL;
    }
}

void disp(struct node *l){
    if(l == NULL){
        printf("linked list is empty ");
    }
    else{
        while(l != NULL){
            printf("%d  ",l->data);
            l = l->next;
        }
    }
}