#include <stdio.h>


#define max 100

void merge_sort(int [], int [],int, int);
void merge(int [],int [],int ,int ,int);


int main()
{
    int a[max], t[max],n, i;
    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    merge_sort(a,t,0,n-1);

    printf("\nAfter Sorting array becomes:  ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}

void merge_sort(int a[],int t[],int lb,int ub){
    int mid = 0;
    if(lb < ub){
        mid = (lb+ub)/2;
    
    merge_sort(a,t,lb,mid);
    merge_sort(a,t,mid+1,ub);

    merge(a,t,lb,mid,ub);
    }
}

void merge(int a[],int t[],int lb,int mid,int ub){
    int i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;

    while (i <= mid && j <= ub)
    {
        if (a[i] < a[j])
        {
            t[k] = a[i];
            i++;
            k++;
        }
        else
        {
            t[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        t[k] = a[i];
        k++;
        i++;
    }
    while (j <= ub)
    {
        t[k] = a[j];
        k++;
        j++;
    }
    for (int i = lb; i <= ub; i++)
    {
        a[i] = t[i];
    }
}
