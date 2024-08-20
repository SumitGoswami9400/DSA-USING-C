// Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define max 10
int cenq(int [],int ,int);
int cdeq(int [],int ,int);
void cdisp(int [],int,int);
int main(){
    int CQ[max],r=-1,f=-1;
    int ch;
    
    while(1){
        printf("\n----- MENU -----");
        printf("\n1-Queue\n2-Dequeue\n3-display\n4-Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            r=cenq(CQ,f,r);
            if(f==-1){
                f=0;
            }
            break;
            case 2:
            f=cdeq(CQ,f,r);
            if(f==-1){
                r=-1;
            }
            break;
            case 3:
            cdisp(CQ,f,r);
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}

int cenq(int CQ[],int f,int r){
    int x;
    if((r+1)%max==f){
        printf("Queue is full");
    }
    else{
        printf("Enter the value to Enqueue: ");
        scanf("%d",&x);
        r=(r+1)%max;
        CQ[r]=x;
    }
    return (r);
}

int cdeq(int CQ[],int f,int r){
    int z=0;
    if(f==-1 && r==-1){
        printf("Queue is empty");
    }
    else{
        z=CQ[f];
        printf("Dequeue element is %d",z);
        if(f==r){
            f=-1;
        }
        else{
            f=(f+1)%max;
        }
    }
    return (f);
}

void cdisp(int CQ[],int f,int r){
    if(f==-1 && r==-1){
        printf("Queue is empty: ");
    }
    else{
        do{
            printf("%d   ",CQ[f]);
            f=(f+1)%max;
        }while(f!=r);
        printf("%d   ",CQ[f]);
    }
}

