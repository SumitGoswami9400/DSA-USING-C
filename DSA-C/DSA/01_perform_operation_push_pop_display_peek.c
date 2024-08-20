// stack using call by value
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int push(int [],int);
int pop(int [], int);
void disp(int [], int);

void peek(int [], int);

int main(){
    int ch;
    int stack[MAX],top=-1;
    while(1){
    printf("\nEnter\n1-push\n2-pop\n3-display\n4-peek\n5-exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

        switch (ch)
        {
        case 1:
        top=push(stack,top);
            break;
        case 2:
        top=pop(stack,top);
        break;
        case 3:
        disp(stack,top);
        break;
        case 4:
        peek(stack,top);
        break;
        case 5:
        exit(0);
        default:
        printf("Enter valid choice:");
        }
    }
}


    int push(int stack[],int top){
        int x;
        if(top==MAX-1){
            printf("stack is full\n");
        }
        else{
            printf("Enter the value of Top:  ");
            scanf("%d",&x);
            top++;
            stack[top]=x;
        }
        return (top);

    }
    int pop(int stack[],int top){
        if(top==-1){
            printf("stack is empty\n");
        }
        else{
            printf("pop element %d",stack[top]);
            top--;
        }
        return (top);
    }
    void disp(int stack[],int top){
        int temp;
        if(top==-1){
            printf("Stack is empty:\n");
        }
        else{
            for(temp=top;temp>=0;temp--){
                printf("%d",stack[temp]);
            }
        }
    }
    void peek(int stack[],int top){
        if(top==-1){
            printf("stack is empty\n");
        }
        else{
            printf("%d",stack[top]);
        }
    }
