#include<stdio.h>
int Bsearch(int[] ,int,int,int);
int main(){
    int n,i,k,lb,ub;
    printf("Enter how many elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d values: ",n);
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }

    printf("Enter your choice :");
    scanf("%d",&k);

    int f = Bsearch(a,0,n,k);

    if(f==1){
        printf("Element found ");
    }
    else{
        printf("Element not found");
    }

    return 0;
}

int Bsearch(int a[],int lb,int ub,int k){

     while(lb<=ub){
        int mid =(ub+lb)/2;

        if(a[mid]==k){
            return 1;
        }
        else if(a[mid]>k){
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    return 0;
}