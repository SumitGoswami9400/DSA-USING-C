// insertion and deletion in double linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct dlist{
    int data;
    struct dlist *prev;
    struct dlist *next;
}dll;

void insert(dll**,dll**);
void delete(dll**,dll**);
void disp(dll*);

int main(){
    dll *l = NULL, *r = NULL;
    int ch;
    while(1){
        printf("\n----MENU----");
        printf("\n1-Insert\n2-delete\n3-display\n4-Exit");
        printf("\nEnter your choice ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert(&l,&r);
            break;

            case 2:
            delete(&l,&r);
            break;

            case 3:
            disp(l);
            break;

            case 4:
            exit(0);
        }
    }
    return 0;
}

void insert(dll **l,dll **r){
    dll *p = NULL;
    int x;
    p = (dll*) malloc(sizeof(dll));
    if(p != NULL){
    printf("Enter value of node ");
    scanf("%d",&x);
    p->data = x;
   
    if(*l == NULL && *r == NULL){
        *l = *r = p;
        p->prev = NULL;
    }
    else{
        (*r)->next = p;
        p->prev = *r;
        *r = p;
    }
    (*r)->next = NULL;
    }
}

void delete(dll **l,dll **r){
    dll *p = NULL;
    int ch;
    printf("Enter your choice ");
    scanf("%d",&ch);

    if((*l)->data == ch){
        p = *l;
        *l = (*l)->next;
        (*l)->prev = NULL;
    }
    else{
        p = (*l)->next;
        while(p->data != ch && p->next != NULL){
            p = p->next;
        }
        if(p->next != NULL){
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        else if(p->data == ch && p->next == NULL){
            p->prev->next = NULL;
            *r = p->prev;
        }
        else{
            printf("Your choice is not matched ");
        }
    }
    free(p);
}

void disp(dll *l){
    if(l == NULL){
        printf("Linked list is empty:");
    }
    else{
        while(l != NULL){
            printf("%d  ",l->data);
            l = l->next;
        }
    }
}