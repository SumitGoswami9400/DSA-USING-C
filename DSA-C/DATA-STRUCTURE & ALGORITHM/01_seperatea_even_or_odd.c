//Q1. Write a c program to store N elements in 1 D array then  count and print total even and odd elements in the array.
#include<stdio.h>
int main(){
    int a[20],b[10],c[10],n,i,e=0,o=0;
    printf("Enter size of an array:\n");
    scanf("%d",&n);

    printf("Enter numbers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            b[e]=a[i];
            e++;
        }
        else{
            c[o]=a[i];
            o++;
        }
    }
    printf("Even numbers are:\n");
    for(i=0;i<e;i++){
        printf("%d\n",b[i]);
    }
    printf("Odd numbers are:\n");
    for(i=0;i<o;i++){
        printf("%d\n",c[i]);
    }
    printf("%d",e);
    printf("\n%d",o);

    return 0;
}