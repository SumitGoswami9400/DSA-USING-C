// Linear search


#include<stdio.h>
 
#define max 100
int Lsearch(int[],int,int);
int main(){
    int a[max],i,n,k;
    printf("Enter no of elements");
    scanf("%d",&n);

    printf("Enter %d elements ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }   
    printf("Enter value for search");
    scanf("%d",&k);

    int f = Lsearch(a,n,k); 

    if(f==1){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }
    return 0;
}

int Lsearch(int a[],int n,int k){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==k){
            return 1;
        }
    }
    return 0;
}