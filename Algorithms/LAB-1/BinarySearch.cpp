#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> & arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + right  / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    // If target is not found in array
    return -1;
}

int main() {
    vector<int> arr1 = {2, 3, 5, 7, 9};
    int target1 = 7;
    int result1 = binarySearch(arr1, target1);
    if (result1 != -1)
        cout << "Found at index: " << result1 << endl;
    else
        cout << "Not found" << endl;

    vector<int> arr2 = {6, 7, 12};
    int target2 = 15;
    int result2 = binarySearch(arr2, target2);
    if (result2 != -1)
        cout << "Found at index: " << result2 << endl;
    else
        cout << "Not found" << endl;

    return 0;
}