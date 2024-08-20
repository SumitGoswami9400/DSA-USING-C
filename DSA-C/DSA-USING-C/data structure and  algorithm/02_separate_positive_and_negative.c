//Q2. Write a c program to store N elements in 1 D array (including positive ,negative and zero) , then separate and store them in different arrays(ie. Positive ,negative and zero).
#include<stdio.h>

int main(){
    int a[20],b[20],c[20],d[20],i,j,n,z,ng,po;
    printf("Enter size of an array:\n");
    scanf("%d",&n);

    printf("Enter elements in an array:\n");
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
     printf("Zero numbers in array is:  ");
    for(i=0;i<n;i++){
        if(a[i]==0){
            b[i]=a[i];
            printf("%d  ",b[i]);
        }
    }
    printf("\nNegative numbers in array is:  ");
    for(i=0;i<n;i++){
        if(a[i]<0){
            c[i]=a[i];
            printf("%d  ",c[i]);
        }
    }
     printf("\nPositive numbers in array is:  ");
    for(i=0;i<n;i++){
        if(a[i]>0){
            d[i]=a[i];
            printf("%d  ",d[i]);
        }
    }
    return 0;
}

// another method
/*
#include <stdio.h>

int main()
{
    int n, arr[10], pos[10], neg[10], zero[10],nec=0,pc=0,zc=0;
    int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements: \n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        if(arr[i] > 0){
            pos[pc++] = arr[i];
        }
        else if(arr[i] < 0){
            neg[nec++] = arr[i];
        }
        else{
            zero[zc++] = arr[i];
        }
    }

    printf("\nPositive elements is :");
    for(i=0;i<pc;i++){
        printf("%d   ",pos[i]);
    }
    printf("\nPositive elements is :");
    for(i=0;i<nec;i++){
        printf("%d   ",neg[i]);
    }
    printf("\nPositive elements is :");
    for(i=0;i<zc;i++){
        printf("%d   ",zero[i]);
    }
    return 0;
}
*/