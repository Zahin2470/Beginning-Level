#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    int i = 0, j = 0, k = p;
    int local_inv = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
            local_inv += (n1 - i); // Calculate the number of local inversions
        }
    }

    // Copy the remaining elements of L[] if any
    while (i < n1)
        A[k++] = L[i++];

    // Copy the remaining elements of R[] if any
    while (j < n2)
        A[k++] = R[j++];

    return local_inv;
}

int mergeSort(int A[], int p, int r) {
    int inversions = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inversions += mergeSort(A, p, q);
        inversions += mergeSort(A, q + 1, r);
        inversions += merge(A, p, q, r);
    }
    return inversions;
}

int main() {
    int A[] = {4, 7, 2, 6, 1, 4, 7, 3, 5, 2, 6};
    // int A[] = {2, 4, 5, 7, 1, 2, 3, 6};
    int n = sizeof(A) / sizeof(A[0]);

    clock_t start = clock();
    int local_inv = mergeSort(A, 0, n - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Local Inversions: %d\n", local_inv);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("Time taken for merge sort: %f seconds\n", time_taken);

    return 0;
}