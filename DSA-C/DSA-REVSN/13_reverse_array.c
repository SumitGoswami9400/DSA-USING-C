/*Write a C function to create a dynamic array and then reverse the elements of the array.*/

#include<stdio.h>
#include<stdlib.h>
void reverse(int n){
    int *arr;
    int i,temp;
    arr = (int*) malloc(n*sizeof(int));
    printf("Enter %d values ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Before Reversing array is\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    for(i=0;i<n/2;i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    printf("After Reversing array is\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
int main(){
    int *p;
    int i,n;

    printf("Enter How many elements ");
    scanf("%d",&n);
    reverse(n);
    return 0;
}

/*Consider the array A[5][6]. If base address is 200 and size of each element is 4 byte
 Find the address of A[3][3] if array is row-major implemented*/
