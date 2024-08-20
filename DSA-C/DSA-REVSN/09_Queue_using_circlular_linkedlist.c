// Implementation of Queue using circular linked list using call by reference



#include<stdio.h>
#include<stdlib.h>
typedef struct clinkedlist{
    int data;
    struct clinkedlist *next;
}cll;

void enq(cll**,cll**);
void deq(cll**,cll**);
void disp(cll*);

int main(){
    cll *f = NULL, *r = NULL;
    int ch;
     while(1){
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit");
        printf("\nEnter your choice: ");
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

void enq(cll **f ,cll **r){
    cll *p = NULL;
    int x;
    p = (cll*) malloc(sizeof(cll));
    if(p != NULL){
        printf("Enter vlaue in Queue  ");
        scanf("%d",&x);
        p->data = x;

        if(*f == NULL && *r == NULL){
            *f = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
        }
        (*r)->next = (*f);
    }
}

void deq(cll **f,cll **r){
    cll *p = NULL;
   
    if(*f == *r){
        *f = *r = NULL;
    }
    else{
        p = *f;
        printf("Removed element is %d",(*f)->data);
        *f = (*f)->next;
        (*r)->next = *f;
        free(p);
    }
}

void disp(cll *f){
    cll *p=NULL;
    if(f== NULL){
        printf("Queue is empty");
    }
    else{
        p = f;
        do{
            printf("%d  ",p->data);
            p = p->next;
        }while(p != f);
    }
}