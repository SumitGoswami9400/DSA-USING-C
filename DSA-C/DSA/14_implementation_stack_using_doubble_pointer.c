/* write a program to implementation of stack using doubble pointer (call by reference)*/


#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
void push(struct stack**);
void pop(struct stack**);
void disp(struct stack*);

int main(){ 
    struct stack *top = NULL;
    int ch;
    while(1){
        printf("\n----MENU-----");
        printf("\n1-push\n2-pop\n3-disp\n4-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
        push(&top);
        break;
        case 2:
        pop(&top);
        break;
        case 3:
        disp(top);
        break;
        case 4:
        exit(0);
        }
    }
    return 0;
}

void push(struct stack **tp){
    struct stack *p = NULL;
    int x;
    p = (struct stack*) malloc(sizeof(struct stack));    

    if(p != NULL){
        printf("\nEnter the value: ");
        scanf("%d",&x);
        p->data = x;
        p->next = (*tp);
        *tp = p;
    }
}

void pop(struct stack **tp){
    struct stack *p = NULL;
    if(*tp == NULL){
        printf("Stack is emtpy :");
    }
    else{
        p = *tp;
        printf("Poped elememt is :%d ",(*tp)->data);
        *tp = (*tp)->next;
        free(p);
    }
}

void disp(struct stack *tp){
    if(tp == NULL){
        printf("Stack is empty: ");
    }
    else{
    while(tp!= NULL){
        printf("  %d  ",tp->data);
        tp = tp->next;
    }
    }
}