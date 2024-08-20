/*. Write a C program to sort a sequence of characters given by user in an array, using selection  
sort technique.*/

#include<stdio.h>

#define max 100
void selection_sort(char [],int);
int main(){
    int n,i;
    char a[max];
    printf("How many character you want to insert ");
    scanf("%d",&n);

    printf("Please enter %d character ",n);
    for(i=0;i<n;i++){
        scanf(" %c",&a[i]);
    }    

    printf("before Sorting Array is \n");
    for(i=0;i<n;i++){
        printf("%c  ",a[i]);
    }

    selection_sort(a,n);
    printf("\nAfter Sorting Array becomes \n");
    for(i=0;i<n;i++){
        printf("%c  ",a[i]);
    }
    return 0;
}

void selection_sort(char a[],int n){
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