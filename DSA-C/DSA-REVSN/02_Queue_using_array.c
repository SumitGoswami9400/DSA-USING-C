// using call by value

#include<stdio.h>
#include<stdlib.h>
#define max 10

int enq(int[],int);
int deq(int[],int,int);
void disp(int[],int,int);

int main(){
    int q[max],r = -1, f = -1;
    int ch;

    while(1){
        printf("\n1-enqueue\n2-dequeue\n3-display\n4-exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            r = enq(q,r);
            if(f == -1){
                f = 0;
            }
            break;

            case 2:
            f = deq(q,f,r);
             if(f == -1){
                r = -1;
            }
            break;

            case 3:
            disp(q,f,r);
            break;

            case 4:
            exit(0);
        }
    }
    return 0;
}

int enq(int q[],int r){
    int x;
    if(r == max-1){
        printf("Queue is full");
    }
    else{
        printf("Enter element in Queue: ");
        scanf("%d",&x);
        r++;
        q[r] = x;
    }
    return (r);
}

int deq(int q[],int f,int r){
    if(f == -1 ){
        printf("Queue is empty");
    }
    else{
        int x = q[f];
        printf("Dequed element is %d",x);

        if(f==r){
            f=-1;
        }
        else{
            f++;
        }
    }
    return (f);
}

void disp(int q[],int f,int r){
    if(f==-1){
        printf("Queue is empty");
    }
    else{
        int i;
        for(i=f;i<=r;i++){
            printf("%d  ",q[i]);
        }
    }
}