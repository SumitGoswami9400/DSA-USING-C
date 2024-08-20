#include<stdio.h>
#define max 100



void B_sort(int [],int);

int main(){
    int a[max],n,i;
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);

    printf("Enter %d values \n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    printf("Before sorting Array is \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    B_sort(a,n);

    printf("\nAfter sorting Array is \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}

void B_sort(int a[],int n){
    int i,j,temp=0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    } 
}