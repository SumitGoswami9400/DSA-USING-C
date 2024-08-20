// Quick sort


#include <stdio.h>
#define max 100

void Quick_sort(int[], int , int );

int main()
{
    int a[max], n, i;
    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    Quick_sort(a, 0, n - 1);

    printf("\nAfter Sorting array becomes:  ");
    for (i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }

    return 0;
}

void Quick_sort(int a[], int lb, int ub)
{
    int i = lb, j = ub, key = a[lb], t = 0;
    if (lb >= ub)
    {
        return;
    }
    while (i < j)
    {
        while (key >= a[i] && i < j)
        {
            i++;
            while (key < a[j])
            {
                j--;
            }
            if (i < j)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    a[lb] = a[j];
    a[j] = key;

    Quick_sort(a, lb, j - 1);
    Quick_sort(a, j + 1, ub);
}