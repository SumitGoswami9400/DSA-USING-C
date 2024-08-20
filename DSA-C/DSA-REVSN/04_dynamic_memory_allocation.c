// using dynamic memory allocation find sum and average of n numbers

#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,s=0;
    int *p=NULL;
    float avg;
    printf("Enter how many elements ");
    scanf("%d",&n);

    p= (int*) malloc(n*sizeof(int));
    printf("Enter %d values ",n);

    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }

    for(i=0;i<n;i++){
        s=s+*(p+i);
    }

     avg = (float)s/n;
    printf("Sum of n element is %d",s);
    printf("\nAverage of n elements is %f",avg);
    return 0;
}