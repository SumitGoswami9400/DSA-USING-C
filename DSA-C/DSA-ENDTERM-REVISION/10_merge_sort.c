#include<stdio.h>

void M_sort(int [],int [], int,int);
void merge(int [],int [],int ,int,int);
int main(){
    int i,n;
    printf("Enter how many elements you want to insert: ");
    scanf("%d",&n);

    int a[n],t[n];

    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Before sorting array is : ");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

    M_sort(a,t,0,n-1);

    printf("\nAfter sorting array becomes : ");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    return 0;
}

void M_sort(int a[],int t[],int lb,int ub){
    int mid = 0;
    if(lb < ub){
        mid = (ub+lb)/2;

        M_sort(a,t,lb,mid);
        M_sort(a,t,mid+1,ub);

        merge(a,t,lb,mid,ub);
    }
}

void merge(int a[], int t[],int lb,int mid,int ub){
  int i = lb;
  int j = mid+1;
  int k = lb;

  while(i <= mid && j <= ub){
    if(a[i] < a[j]){
        t[k] = a[i];
        k++;
        i++;
    }
    else{
        t[k] = a[j];
        k++;
        j++;
    }
  }
  while(i <= mid){
    t[k] = a[i];
    i++;
    k++;
  }
  while(j <= ub){
    t[k] = a[j];
    k++;
    j++;
  }

  for(int p = lb; p <= ub; p++){
    a[p] = t[p];
  }
}