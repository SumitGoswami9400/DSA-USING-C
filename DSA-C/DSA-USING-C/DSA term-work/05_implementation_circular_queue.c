/*Write a menu driven program to implement circular queue using linked list with double pointer*/

#include<stdio.h>
#include<stdlib.h>

typedef struct circularqueue{
    int data;
    struct circularqueue *next;
}cq;

void enqueue(cq**,cq**);
void dequeue(cq**,cq**);
void disp(cq*);

int main(){
    cq *f = NULL, *r = NULL;
    int ch;

    while(1){
        printf("\n-----MENU-----");
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            enqueue(&f,&r);
            break;

            case 2:
            dequeue(&f,&r);
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

void enqueue(cq **f,cq **r){
    cq *p = NULL;
    int x;
    p = (cq*) malloc(sizeof(cq));

    if(p !=  NULL){
    printf("Enter data:  ");
    scanf("%d",&x);
    p->data = x;
    if(*f == NULL && *r == NULL){
        *f = *r = p;
    }
    else{
        (*r)->next = p;
        *r = p;
    }
    (*r)->next = *f;
    }
}

void dequeue(cq **f, cq **r){
    cq *p = NULL;
    if(*f == NULL && *r == NULL){
        printf("Queue is empty");
    }
    else{
        p = *f;
        printf("Dequeue element is %d  ",(*f)->data);
        *f = (*f)->next;
        (*r)->next = *f;
        if(p == *r){
            *f = *r = NULL;
        }
        free(p);
    }
}

void disp(cq *f){
    cq *p = f;
    if(f == NULL){
        printf("Queue is empty");
    }
    else{
    do{
        printf("%d  ",p->data);
        p = p->next;
    }while(p != f);
    }
}
