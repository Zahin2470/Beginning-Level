#include <stdio.h>
#include <math.h>

// Function to compute the power of a number
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Function to sort an array using bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int maxSumOfExponents(int A[], int B[], int n) {
    
    bubbleSort(A, n);
    bubbleSort(B, n);

    // Calculate the maximum sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += power(A[i], B[i]);
    }

    return sum;
}

int main() {
    int A1[] = {3, 1, 1};
    int B1[] = {6, 5, 4};
    int N1 = 3;
    printf("Maximum sum of exponents (Example 1): %d\n", maxSumOfExponents(A1, B1, N1));

    int A2[] = {6, 1, 5, 4};
    int B2[] = {3, 4, 2, 4};
    int N2 = 4;
    printf("Maximum sum of exponents (Example 2): %d\n", maxSumOfExponents(A2, B2, N2));

    return 0;
}