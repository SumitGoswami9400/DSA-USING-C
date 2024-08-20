/* write a program to implementation of Queue using doubble pointer (call by reference)*/


#include<stdio.h>
#include<stdlib.h>


struct queue{
    int data;
    struct queue *next;
};

void enq(struct queue** , struct queue**);
void deq(struct queue** , struct queue**);
void disp(struct queue*);

int main(){
    struct queue *r = NULL , *f=NULL;
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

void enq(struct queue **f,struct queue **r){
    struct queue *p = NULL;
    int x;
    
    p = (struct queue*) malloc(sizeof(struct queue));

    if(p != NULL){
        printf("Enter node: ");
        scanf("%d",&x);
        p->data = x;
        if(*f == NULL && *r==NULL){
            *f = *r = p;
        }
        else{
            (*r)->next = p;
            *r = p;
            (*r)->next = NULL;
        }
    }
}

void deq(struct queue **f,struct queue **r){
    struct queue *p = NULL;

    if(*f == NULL && *r == NULL){
        printf("Queue is empty: ");
    }
    else{
        p = *f;
        printf("Deleted element is: %d",(*f)->data);
        if(*f == *r){
            *f = *r = NULL;
        }
        else{
            *f = (*f)->next;
        }
        free(p);
    }
}

void disp(struct queue *f){
    if(f == NULL){
        printf("Queue is empty: ");
    }
    else{
        while (f != NULL)
        {
            printf("%d\n",f->data);
            f = f->next;
        }
    }
}