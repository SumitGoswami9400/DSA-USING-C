#include<stdio.h>
#include<stdlib.h>
typedef struct circularll{
    struct circularll *next;
    int data;
}cll;
void insert(cll **,cll **);
void disp(cll*);
int main(){
    cll *head = NULL, *last = NULL;
    int ch;
    while(1){
        printf("\n1-insert\n2-disp\n3-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insert(&head,&last);
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

void insert(cll **head , cll **last){
    cll *p = NULL;
    int x;
    p = (cll*) malloc(sizeof(cll));
    if(p != NULL){
        printf("Enter data: ");
        scanf("%d",&x);
        p->data = x;
        if(*head == NULL && *last == NULL){
            *head = *last = p;
        }
        else{
            (*last)->next = p;
            *last = p;
        }
        (*last)->next = *head;
    }
}

void disp(cll *head){
    if(head != NULL){
        cll *p = head;
        do{
            printf("%d  ",p->data);
            p = p->next;
        }while(p != head);
    }
}