#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} s;

void push(s **);
void pop(s **);
void disp(s *);
void peek(s *);

int main()
{
    s *top = NULL;
    int ch;
    while (1)
    {
        printf("\n1-push\n2-pop\n3-disp\n4-peek\n5-exit");
        printf("\nEnter your choice  ");
        scanf("%d", &ch);
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
            peek(top);
            break;

            case 5:
            exit(0);
        }
    }
    return 0;
}

void push(s **tp){
    s *p = NULL;
    int x;
    p = (s*) malloc(sizeof(s));
    if(p != NULL){
        printf("Enter data: ");
        scanf("%d",&x);
        p->data = x;

        if(*tp == NULL){
            p->next = NULL;
            *tp = p;
        }
        else{
            p->next = (*tp);
            *tp = p;
        }
    }
}

void pop(s **tp){
    s *p = NULL;
    if(*tp == NULL){
        printf("Stack is empty ");
    }
    else{
        p = *tp;
        printf("Poped element is: %d",(*tp)->data);
        *tp = (*tp)->next;
        free(p);
    }
}

void disp(s *tp){
    if(tp == NULL){
        printf("Stack is empty");
    }
    else{
        while(tp != NULL){
            printf("%d  ",tp->data);
            tp = tp->next;
        }
    }
}

void peek(s* tp){
    if(tp == NULL){
        printf("Stack is empty");
    }
    else{
        printf("Peeked element is: %d",tp->data);
    }
}