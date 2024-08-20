// implementation of queue using circular linked list (using call by reference)

#include<stdio.h>
#include<stdlib.h>
typedef struct circularqueue{
    int data;
    struct circularqueue *next;
}cque;

void enq(cque**,cque**);
void deq(cque**,cque**);
void disp(cque*);

int main(){
     cque *f = NULL, *r = NULL;
    int ch;
    while(1){
        printf("\n------MENU------");
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            enq(&f,&r);
            break;
            case 2:
            deq(&f,&r);
            break;
            case 3:
            disp(f);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}

void enq(cque **f1,cque **r1){
    cque *p = NULL;
    int x;
    p = (cque*) malloc(sizeof(cque));
    if(p != NULL){
        printf("Enter value in queue: ");
        scanf("%d",&x);
        p->data = x;
    }
    if(*f1 == NULL && *r1 == NULL){
            *f1 = *r1 = p;
        }
        else{
            (*r1)->next = p;
            *r1=p;
        }
        (*r1)->next = *f1;
}

void deq(cque **f1,cque **r1){
    cque *p = NULL;
    if(*f1 == NULL && *r1 == NULL){
        printf("Queue is empty");
    }
    else{
        p = *f1;
        printf("Delete node is %d",(*f1)->data);
        *f1 = (*f1)->next;
        (*r1)->next = *f1;
         if(p == *r1){
         *f1=*r1=NULL;
         }
        free(p);
    }
}

void disp(cque *f1){
    cque *p = NULL;
    p = f1;
    if(f1 == NULL){
        printf("Queue is empty");
    }
    else{
        do{
            printf("%d  ",p->data);
            p = p->next;
        }while(p != f1);
    }
}