/* Write a c program to store N elements in 1 D array (including positive ,negative values) , then
Separate all positive and negative elements at the either side of the array, without altering the     
Original sequence of elements.*/

#include <stdio.h>

int main() {
    int a[100],n, i, j, temp;
    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements in array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    j = 0;
    int k=0;
    for(i=0; i<n; i++){
        if(a[i] < 0){
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j++;
        }
    }

    printf("\nArray with positive and negative elements separated:\n");
    for(i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
