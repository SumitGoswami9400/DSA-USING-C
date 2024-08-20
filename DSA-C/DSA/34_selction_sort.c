// Selection sort 


#include<stdio.h>

#define max 100
void selection_sort(int [],int);

int main(){
    int a[max],n,i;
    printf("How many elements you want to insert ");
    scanf("%d",&n);

    printf("Please enter %d elements ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }    

    printf("before Sorting Array is \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    selection_sort(a,n);
    printf("\nAfter Sorting Array becomes \n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}

void selection_sort(int a[],int n){
    int i,j,pos=0,min=0;

    for(i=0;i<n-1;i++){
        min = a[i];
        pos = i;
        for(j=i+1;j<n;j++){
            if(min>a[j]){
                min = a[j];
                pos = j;
            }
        }
         if(pos != i){
                a[pos] = a[i];
                a[i] = min;
            }
    }
}