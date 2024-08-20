/* Write a c program to implement double linked list by insdll 
in such a way that the resulting linked list remains in ascending order*/


#include <stdio.h>
#include <stdlib.h>
typedef struct dlist {
    int data;
    struct dlist* prev;
    struct dlist* next;
}dll;
void Insertnode(dll**,dll**);
void disp(dll*); 

int main() {
    dll* l = NULL , *r = NULL;
     int ch;
     int data;
    while(1){
        printf("\n-----MENU-----");
        printf("\n1-insert\n2-display\n3-exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
    
        switch(ch){
            case 1:
            Insertnode(&l,&r);
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



void Insertnode(dll** l ,dll** r) {
    int data;
    dll* p = (dll*)malloc(sizeof(dll));
    printf("\nEnter data :");
    scanf("%d",&data);
    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    if (*l == NULL && (*r) == NULL) {
        *l = *r = p;
        return;
    }

    if (p->data < (*l)->data) {  // node data is less then first node its their code
        p->next = *l;
        (*l)->prev = p;
        *l = p;
        return;
    }
        *r = *l;
    while ((*r)->next != NULL && (*r)->next->data < p->data) {
        (*r) = (*r)->next;
    }

    p->next = (*r)->next;
    if ((*r)->next != NULL) {
        (*r)->next->prev = p;
    }
    (*r)->next = p;
    p->prev = (*r);
}

void disp(dll* l) {
    while (l != NULL) {
        printf("%d   ", l->data);
        l = l->next;
    }
    printf("\n");
}
