#include<stdio.h>
int lsearch(int[],int,int);
int main(){
    int n,i,k;
    printf("Enter How many values");
    scanf("%d",&n);


    int a[n];
    printf("Enter %d values ",n);
    
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter searched element ");
    scanf("%d",&k);
    int f = lsearch(a,n,k);
    if(f==1){
        printf("Element found ");
    }
    else{
        printf("Element not found ");
    }
    return 0;
}

int lsearch(int a[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==k){
            return 1;
        }
    }
    return 0;
}