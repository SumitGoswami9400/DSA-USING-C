// Queue using linkedlist (call by value)
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue* next;
}q;

q * enq(q*);
q *deq(q*);
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
            r = enq(r);
            if(f == NULL){
                f = r;
            }
            break;

            case 2:
            f = deq(f);
            if(f == NULL){
                r = NULL;
            }
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

q * enq(q *r){
    q *p = NULL;
    int x;

    p = (q*) malloc(sizeof(q));
    if(p!= NULL){
        printf("Enter element in queue");
        scanf("%d",&x);
        p->data = x;
        if(r == NULL){
        r = p;
        }
        else{
            r->next = p;
            r = p;
        }
        p->next = NULL;
    }
    return(r);
}

q * deq(q *f){
    q *p = NULL;
    if(f==NULL){
        printf("Queue is empty: ");
    }
    else{
        p = f;
        printf("Removed element is %d",f->data);
        f=f->next;
        free(p);
    }
    return (f);
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