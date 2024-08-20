// Queue using call by value

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int enq(int [],int);       // enq is enqueue
int deq(int [],int,int);       // deq is dequeue
void disp(int [],int,int);



int main(){
    int q[MAX],f=-1,r=-1,ch;
    while(1){
    printf("\nEnter\n1-Enqueue\n2-dequeue\n3-display\n4-exit\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

        switch (ch)
        {
        case 1:
        r=enq(q,r);
        if(f==-1){
            f=0;
        }
        break;
        case 2:
        f=deq(q,f,r);
        if(f==-1){
            r=-1;
        }
        break;
        case 3:
        disp(q,f,r);
        break;
        case 4:
        exit(0);
        default:
        printf("Enter valid choice:");
        }
    }
    return 0;
}

    int enq(int q[],int r){
        int x;
        if(r==MAX-1){
            printf("Queue is full");
        }
        else{
            printf("Enter value of Queue:  ");
            scanf("%d",&x);
            r++;
            q[r]=x;
        }
        return (r);
    }

    int deq(int q[],int f,int r){
        int x;
        if(f==-1){
            printf("Queue is empty");
        }
        else{
            x=q[f];
            printf("The removed element is %d",x);
        }
        if(f==r){
            f=-1;
        }
        else{
            f++;
        }
        return (f);
    }

    void disp(int q[],int f,int r){
        int i;
        if(f==-1){
            printf("Queue is empty");
        }
        else{
            for(i=f;i<=r;i++){
                printf("%d  ",q[i]);
            }
        }
    }