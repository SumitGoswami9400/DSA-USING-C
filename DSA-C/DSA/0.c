/* Write a c program to implement double linked list by insdll 
in such a way that the resulting linked list remains in ascending order*/



#include <stdio.h>
#include <stdlib.h>
typedef struct dlist {
    int data;
    struct dlist* prev;
    struct dlist* next;
}dll;
void insert_node(dll** l ,dll** r){
    int data;
    dll* p = (dll*)malloc(sizeof(dll));
    printf("\nEnter data :");
    scanf("%d",&data);
    p->data = data;
    p->prev = NULL;
    p->next = NULL;

    if (*l == NULL && *r == NULL) {
        *l = *r = p;
        return;
    }

    if (p->data < (*l)->data) {
        p->next = *l;
        (*l)->prev = p;
        *l = p;
        return;
    }
    dll *cp = *l;
    while (cp->next != NULL && cp->next->data < p->data) {
        cp = cp->next;
    }

    p->next = cp->next;
    if (cp->next == NULL) {
        (*r)->prev = p;
        *r = p;
    }
    cp->next = p;
    p->prev = cp;
}

void print_list(dll* l) {
    while (l != NULL) {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

int main() {
    dll* l = NULL ,*r= NULL;
     int ch;
     int data;
    while(1){
        printf("\n-----MENU-----");
        printf("\n1-insert\n2-display\n3-exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
    
        switch(ch){
            case 1:
            insert_node(&l,&r);
            break;

            case 2:
            print_list(l);
            break;

            case 3:
            exit(0);
        }
    }

    return 0;
}

