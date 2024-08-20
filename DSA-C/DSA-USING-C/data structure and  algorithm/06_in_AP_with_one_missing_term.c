//Write a c program to store N elements in 1 D array then check whether the given sequence of elements is in AP with one missing term if there is a missing tem print the series including the missing term .
#include<stdio.h>

int main(){
    int a[100],b[100],i,j,mt,n,d=0,flag;   // mt for missing term
    printf("Enter size of array:\n");
    scanf("%d",&n);

    printf("Enter elements in array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    
    for(i=0;i<n-1;i++){
        if(a[i+1]-b[i]==1){
             flag=0;
        }
        else if(a[i+1]-b[i]==2){
            mt=i+2;
            d++;
           // printf("%d\n\n",d); check value of d otherwise no need this.
        }
           else{
            j++;
           }
        }
    if(j==1||d>1){
        printf("There is more than one missing term");
    }
    else if (d==0){
         printf("Given sequence is alredy in A.P form");
    }
    else if (d==1){
        for(i=0;i<n;i++){
        printf("%d, ",a[i]);
        }
        printf("in AP with one missing term,%d",mt);
    }
    return 0;
}