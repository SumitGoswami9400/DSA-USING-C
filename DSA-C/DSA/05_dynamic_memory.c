/*Write a c program to implement an array using dynamic memory allocation to allocate memory
for n element given by the user and then find sum and avg of the given values.*/


#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p=NULL,n,i,s=0;
    float avg;
    printf("Enter no of elements: ");
    scanf("%d",&n);



    p=(int*) malloc(n* sizeof (int));
    printf("Enter %d values",n);

    for(i=0;i<n;i++){
        scanf("%d",(p+i));
    }
    for(i=0;i<n;i++){
        s=s+ *(p+i);
    }

    free(p);

    avg = (float)s/n;
    printf("\nThe sum of these numbers of: %d",s);
    printf("\nThe avg of these numbers is: %f",avg);
    return 0;
}