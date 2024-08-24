#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarySearch(int A[], int n, int data){
// Time Complexity O(log n)
    clock_t start = clock();
    int l = 0, r = n - 1;
    int found = 0;

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (data == A[mid])
        {
            printf("Element %d found at index %d\n", data, mid);
            found = 1;
            break;
        }
        else if (data > A[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (!found)
        printf("Element %d not found in the array\n", data);

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for binary search: %.8f seconds\n", time_taken);
}

void bubbleSort(int A[], int n){
// Time Complexity worst case O(n^2), best O(n)
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %.8f seconds\n", time_taken);
}

void insertionSort(int A[], int n){
// Time Complexity worst case O(n^2), best O(n)

    clock_t start = clock();
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %.8f seconds\n", time_taken);
}

void selectionSort(int A[], int n){
// Time Complexity O(n^2)
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for selection sort: %.8f seconds\n", time_taken);
}

void merge(int A[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r){
// Time Complexity worst case O(n^2), best O(nlogn)

    clock_t start = clock();
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);

        merge(A, l, mid, r);
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for merge sort: %.8f seconds\n", time_taken);
}

int partition(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1;
}

void quickSort(int A[], int low, int high){
// Time Complexity worst case O(n^2), best & avarage case O(nlogn)

    clock_t start = clock();
    if (low < high)
    {
        int pivotIndex = partition(A, low, high);

        quickSort(A, low, pivotIndex - 1);
        quickSort(A, pivotIndex + 1, high);
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for quick sort: %.8f seconds\n", time_taken);
}

int main()
{
    int size, choice, data;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int A[size];

    // Seed for random numbers
    srand(time(NULL));

    printf("Randomly generated array: ");
    for (int i = 0; i < size; i++)
    {
        A[i] = rand() % 10000; // Generate random numbers between 0 and 9999
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("\n");

    printf("Choose the operation:\n");
    printf("1. Binary Search\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the element to search: ");
        scanf("%d", &data);
        binarySearch(A, size, data);
        break;
    case 2:
        bubbleSort(A, size);
        break;
    case 3:
        insertionSort(A, size);
        break;
    case 4:
        selectionSort(A, size);
        break;
    case 5:
        mergeSort(A, 0, size - 1);
        break;
    case 6:
        quickSort(A, 0, size - 1);
        break;
    default:
        printf("Invalid choice\n");
        return 1;
    }

    printf("Sorted array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}