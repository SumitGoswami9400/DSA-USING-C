#include <stdio.h>

void sort_2d_array(int arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[0][j] > arr[0][j + 1]) {
                int temp = arr[0][j];
                arr[0][j] = arr[0][j + 1];
                arr[0][j + 1] = temp;
            }
        }
    }
}

void merge_sorted_arrays(int A[][100], int B[][100], int C[][100], int n) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n) {
        if (A[0][i] <= B[0][j]) {
            C[0][k] = A[0][i];
            i++;
        }
        else {
            C[0][k] = B[0][j];
            j++;
        }
        k++;
    }
    while (i < n) {
        C[0][k] = A[0][i];
        i++;
        k++;
    }
    while (j < n) {
        C[0][k] = B[0][j];
        j++;
        k++;
    }
}

int main() {
    int n;
    printf("Enter the size of the arrays: ");
    scanf("%d", &n);
    int A[1][100], B[1][100], C[1][200];
    printf("Enter the elements of array A: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[0][i]);
    }
    printf("Enter the elements of array B: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[0][i]);
    }
    sort_2d_array(A, n);
    sort_2d_array(B, n);
    merge_sorted_arrays(A, B, C, n);
    printf("The merged sorted array is: ");
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", C[0][i]);
    }
    printf("\n");
    return 0;
}
