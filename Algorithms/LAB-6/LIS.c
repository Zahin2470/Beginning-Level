#include <stdio.h>

int binarySearch(int B[], int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (B[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int LIS(int A[], int size) {

    if (size == 0)
        return 0;

    int B[size];
    int length = 1;

    B[0] = A[0];

    for (int i = 1; i < size; i++) {
        if (A[i] < B[0]) {
            B[0] = A[i];
        } else if (A[i] > B[length - 1]) {
            B[length++] = A[i];
        } else {
            int pos = binarySearch(B, -1, length - 1, A[i]);
            B[pos] = A[i];
        }
    }

    return length;
}

int main() {
    int A[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Length of Longest Increasing Subsequence is %d\n", LIS(A, n));

    return 0;
}