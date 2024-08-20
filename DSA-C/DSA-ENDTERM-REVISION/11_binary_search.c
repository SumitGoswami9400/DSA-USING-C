#include <stdio.h>

#define max 50
int bsearch(int[], int, int,int);

int main()
{
    int a[max], i, j, n,f=0,k;

    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to be searched:  ");
    scanf("%d",&k);

    f = bsearch(a, 0, n - 1,k);

    if(f==0){
        printf("Element not found");
    }
    else{
        printf("element is found");
    }

    return 0;
}

int bsearch(int a[],int lb,int ub,int k){
    int mid = 0;
    while(ub >= lb){
        mid = (ub+lb)/2;
        if(a[mid] == k){
            return 1;
        }
        else if(a[mid] > k){
            ub = mid -1;
        }
        else{
            lb = mid +1;
        }
    }
    return 0;
}