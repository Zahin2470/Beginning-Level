#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to count the occurrences of a number in the array
int countOccurrences(int arr[], int n, int key)
{
    int count = 0;
    int index = binarySearch(arr, 0, n - 1, key);
    if (index == -1)
        return count;
    else
    {
        // Count occurrences to the left of the found index
        int left = index - 1;
        while (left >= 0 && arr[left] == key)
        {
            count++;
            left--;
        }
        // Count occurrences to the right of the found index
        int right = index + 1;
        while (right < n && arr[right] == key)
        {
            count++;
            right++;
        }
        // Add 1 for the element itself
        return count + 1;
    }
}

int main()
{
    int arr[] = {2, 3, 4, 4, 4, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 4; // Number to search for

    int count = countOccurrences(arr, n, key);

    printf("%d has occurred %d times\n", key, count);

    return 0;
}