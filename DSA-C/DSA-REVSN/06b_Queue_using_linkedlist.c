// Queue using linkedlist (call by reference)
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue* next;
}q;

void enq(q**,q**);
void deq(q**,q**);
void disp(q*);

int main(){
    q *f = NULL, *r=NULL;
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

void enq(q **f, q **r){
    q *p = NULL;
    int x;

    p = (q*) malloc(sizeof(q));
    if(p!= NULL){
        printf("Enter element in queue");
        scanf("%d",&x);
        p->data = x;
        if(*f== NULL && *r == NULL){
          *f = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
            (*r)->next = NULL;
        }
    }
}

void deq(q **f,q **r){
    q *p = NULL;
    if(*f==NULL){
        printf("Queue is empty: ");
    }
    else{
        p = *f;
        printf("Removed element is %d",(*f)->data);
        if(*f == *r){
            *f = *r = NULL;
        }

        else{
        *f=(*f)->next;
        }
        free(p);
    }
}

void disp(q*f){
    if(f== NULL){
        printf("Queue is empty");
    }
    else{
        while(f != NULL){
            printf("%d  ",f->data);
            f = f->next;
        }
    }
}