#include<stdio.h>

void Q_sort(int [],int , int);
int main(){
    int i,n;
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Before sorting array is : ");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    Q_sort(a,0,n-1);

    printf("\nAfter sorting array becomes : ");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}

void Q_sort(int a[], int lb, int ub){
    int i = lb, j = ub, k = a[lb],t=0;
    if(lb >= ub){
        return;
    }
    else{
        while(i < j){
            while(k >= a[i] && i<j){
                i++;
                while(k < a[j]){
                    j--;
                }
                if(i < j){
                    t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
        }
    }
    a[lb] = a[j];
    a[j] = k;
    Q_sort(a,lb,j-1);
    Q_sort(a,j+1,ub);
}