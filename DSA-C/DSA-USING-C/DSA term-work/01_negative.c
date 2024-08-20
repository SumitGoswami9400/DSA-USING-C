/*Write a ‘C’  program to store N elements in  an array, then send all negative elements of the 
array  to the one end of same array without altering the original sequence(do not take any temporary  array).
Input:     Array[]    2   -11  -3    -4     -5    6    7   -88
Ouput:   Array[]    2     6     7    -11   -3   -4   -5    -88 */

#include<stdio.h>

void moved_negative(int*,int);

int main(){
    int i,j,n;
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    moved_negative(a,n);

    printf("The array with negative elements moved to the end:\n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    return 0;
}

void moved_negative(int *a,int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        if(a[i] > 0){
            for(j = i ; j > 0 && a[j-1] < 0; j--){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}