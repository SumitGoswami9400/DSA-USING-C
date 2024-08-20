// implementation of Queue using linked list


#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
    int data;
    struct queue *next;
}que;

que * enq(que *);
que * deq(que *);
void disp(que *);

int main(){
    que *r = NULL , *f=NULL;
    int ch;

    while(1){
        printf("\n------MENU------");
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit\n");
        printf("Enter your choice: ");
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

que * enq(que *r){
    que *p = NULL;
    int x;
    p = (que *) malloc(sizeof(que));
    if(p != NULL){
        printf("Enter value in queue: ");
        scanf("%d",&x);
        p->data = x;

        if(r == NULL){
           // printf("\n%d",p);
            r = p;
        }
        else{
            r->next = p;
            r=p;
        }
        r->next = NULL;
    }
    return (r);
}
que * deq(que *f){
    que *p = NULL;
    if(f == NULL){
        printf("Queue is empty");
    }
    else{
        p = f;
        printf("Dequeue element is %d",f->data);
        f = f->next;
        free(p);
    }
    return (f);
}
void disp(que *f){
    if(f == NULL){
        printf("Queue is empty");
    }
    else{
        while(f != NULL){
            printf("%d\n",f->data);
            f = f->next;
        }
    }
}

