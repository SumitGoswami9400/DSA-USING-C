/* Write a c program to create double linked list by inserting node 
in such a way that the resultant linked list remains in ascending order*/


#include<stdio.h>
#include<stdlib.h>
typedef struct doublelinked{
    int data;
    struct doublelinked* prev;
    struct doublelinked* next;
}dll;

void Insertnode(dll**);
void disp(dll*);

int main(){
    dll *head = NULL;
    int ch;

    while(1){
        printf("\n-----MENU-----");
        printf("\n1-insert\n2-display\n3-exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            Insertnode(&head);
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

void Insertnode(dll **ptr){
    dll *p;
    int x;
    p = (dll*) malloc(sizeof(dll));
    printf("Enter value in linked list ");
    scanf("%d",&x);

    p->data = x;
    p->prev = NULL;
    p->next = NULL;

    if(*ptr == NULL){
        *ptr = p;
        return;
    }

    if(p->data < (*ptr)->data ){   // node data is less then first node its their code
        p->next = (*ptr);
        (*ptr)->prev = p;
        (*ptr) = p;
        return;
    }

    dll *cp = *ptr;   // cp is current position
    while(cp->next != NULL && cp->next->data < p->data){
        cp = cp->next; 
    } 

    p->next = cp->next;

    if(cp->next != NULL){
    cp->next->prev = p;
    }
    cp->next = p;
    p->prev = cp;

}
void disp(dll *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}