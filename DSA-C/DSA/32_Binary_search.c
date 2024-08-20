// Binary search


#include<stdio.h>
#define max 100

int Bsearch(int[],int,int,int);


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
    
    int f = Bsearch(a,0,n,k); 

    if(f==1){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }  
    return 0;
}

int Bsearch(int a[],int lb,int ub,int k){  // lb = lower bound , up = uper bound

    int mid = 0;
    while(lb<=ub){
       mid = (ub+lb)/2;
        if(a[mid]==k){
            return 1;
        }
        else if(a[mid]>k){
            ub = mid -1;
        }
        else{
            lb = mid +1;
        }
    }
    return 0;
}