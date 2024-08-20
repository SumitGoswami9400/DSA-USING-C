//. Write a c program to store N elements in 1 D array then count frequency of each element in the array.
#include<stdio.h>

int main(){
    int a[10],b[10],freq[10],i,j,n,count;
    printf("Enter size of an array:\n");
    scanf("%d",&n);

    printf("Enter %d elements in array:\n",n);

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        freq[i]=-1;
    }

    for(i=0;i<n;i++){
        count=1;
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
            count++;
            freq[j]=0;
            }
        }
        if(freq[i]!=0){
            freq[i]=count;
        }
    }

    for(i=0;i<n;i++){
        if(freq[i]!=0){
            printf("%d occurs %d times: ",a[i],freq[i]);
        }
        printf("\n");
    }

    return 0;
}
