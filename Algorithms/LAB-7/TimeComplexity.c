#include <stdio.h>
#include <math.h>
#include <time.h>

// Function to compute the power of a number
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

// Bubble Sort implementation
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

// Quick Sort partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge function for merge sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort implementation
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to compute the maximum sum of the minimum value of the exponents
int maxSumOfExponents(int A[], int B[], int n) {
    // Sort both arrays
    //quickSort(A, 0, n - 1);
    //quickSort(B, 0, n - 1);

    //bubbleSort(A, n);
    //bubbleSort(B, n);

    mergeSort(A, 0, n - 1);
    mergeSort(B, 0, n - 1);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += power(A[i], B[i]);
    }

    return sum;
}

// Function to copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Driver code
int main() {
    int A1[] = {3, 1, 1};
    int B1[] = {6, 5, 4};
    int N1 = 3;

    int A2[] = {6, 1, 5, 4};
    int B2[] = {3, 4, 2, 4};
    int N2 = 4;

    // Timing variables
    clock_t start, end;
    double cpu_time_used;

    int A_copy[4];
    int B_copy[4];

    // Bubble Sort Timing
    copyArray(A2, A_copy, N2);
    copyArray(B2, B_copy, N2);
    start = clock();
    bubbleSort(A_copy, N2);
    bubbleSort(B_copy, N2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort time: %f\n", cpu_time_used);

    // Quick Sort Timing
    copyArray(A2, A_copy, N2);
    copyArray(B2, B_copy, N2);
    start = clock();
    quickSort(A_copy, 0, N2 - 1);
    quickSort(B_copy, 0, N2 - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort time: %f\n", cpu_time_used);

    // Merge Sort Timing
    copyArray(A2, A_copy, N2);
    copyArray(B2, B_copy, N2);
    start = clock();
    mergeSort(A_copy, 0, N2 - 1);
    mergeSort(B_copy, 0, N2 - 1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Merge Sort time: %f\n", cpu_time_used);

    return 0;
}