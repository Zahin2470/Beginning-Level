#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestIncreasingSubsequence(int arr[], int n) {
    int lis[n], maxLIS = 0;

    // Initialize LIS values for all indices
    for (int i = 0; i < n; i++) {
        lis[i] = 1; // Minimum LIS length is 1 (the element itself)
    }

    // Compute LIS values in bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        maxLIS = max(maxLIS, lis[i]);
    }

    return maxLIS;
}

int main() {
    int A[] = {5, 10, 3, 9, 8, 12, 7, 13, 4, 11};
    int n = sizeof(A) / sizeof(A[0]);
    
    int lisLength = longestIncreasingSubsequence(A, n);
    
    printf("Length of Longest Increasing Subsequence: %d\n", lisLength);

    return 0;
}
