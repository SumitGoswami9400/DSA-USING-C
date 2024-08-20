/* Inserting nodes at right hand side in double linked list and delete any node as well as.*/
// using call by reference.


#include<stdio.h>
#include<stdlib.h>


typedef struct dlist{
    struct dlist *prev;
    int data;
    struct dlist *next;
}dll;

void Insert(dll**,dll**);
void Delete(dll**,dll**);
void disp(dll*);

int main(){
    dll *l = NULL, *r = NULL;
    int ch;
    while(1){
        printf("\n-----MENU-----");
        printf("\n1-Insert\n2-Delete\n3-disp\n4-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            Insert(&l,&r);
            break;

            case 2:
            Delete(&l,&r);
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

void Insert(dll **l,dll **r){
    dll *p = NULL;
    int x;
    p = (dll*) malloc(sizeof(dll));

    if(p != NULL){
        printf("Enter value of node: ");
        scanf("%d",&x);
        p->data = x;

        if(*r == NULL && *l == NULL){
            *r = *l = p;
            p->prev = NULL;
        }
        else{
            p->prev = *r;
            (*r)->next = p;
            *r = p;
        }
        (*r)->next = NULL;
    }
}

void Delete(dll **l,dll **r){
    dll *p = NULL;
    int ch;
    printf("Enter your choice: ");
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
        else if(p->next == NULL && p->data == ch){
            p->prev->next = NULL;
            *r = p->prev;
        }
        else{
            printf("\nYour choice is not matched:");
        }
    }
    printf("%d  Deleted is successfullly\n",ch);
    free(p);
}

void disp(dll *l){
    if(l == NULL){
        printf("Linked list is empty: ");
    }
    else{
        while(l != NULL){
            printf("%d   ",l->data);
            l = l->next;
        }
    }
}