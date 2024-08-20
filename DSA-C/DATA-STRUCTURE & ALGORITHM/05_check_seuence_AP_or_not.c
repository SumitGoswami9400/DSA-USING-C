//Write a c program to store N elements in 1 D array then check whether the given sequence of elements is in AP or not.
#include<stdio.h>
int main(){
    int a[50],i,j,n,flag;
    printf("Enter size of an array:\n");
    scanf("%d",&n);

    printf("Enter %d elements in array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n;i++){
        if(a[i]==i+1){
            flag=0;
        }
        else{
            flag++;
        }
    }
    if(flag==0){
        printf("Given sequence in A.P");
    }
    else{
        printf("Given sequence is not A.P");
    }
    return 0;
}