// Ackermann function using recursion


#include<stdio.h>
int ack(int ,int);
int main(){
    int n,m;
    printf("Enter value of m :");
    scanf("%d",&m);
    printf("Enter value of n :");
    scanf("%d",&n);
    int x = ack(m,n);
    printf("%d",x);
    return 0;
}

int ack(int m,int n){
    if(m == 0){
       return (n+1);
    }
    else if(m>0 && n==0){
        return (ack(m-1,1));
    }
    else if(m>0 && n>0){
        return (ack(m-1,ack(m,n-1)));
    }
}