#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting positions
int comparePositions(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to find the minimum time for all mice to reach holes
int minTimeToReachHoles(int *mice, int *holes, int n) {
    // Sort positions of mice and holes
    qsort(mice, n, sizeof(int), comparePositions);
    qsort(holes, n, sizeof(int), comparePositions);

    // Calculate the time for each mouse to reach its corresponding hole
    int maxTime = 0;
    for (int i = 0; i < n; i++) {
        int time = abs(mice[i] - holes[i]);
        if (time > maxTime) {
            maxTime = time;
        }
    }

    return maxTime;
}

int main() {
    // Sample input
    int mice[] = {4, -4, 2};
    int holes[] = {4, 0, 5};
    int n = sizeof(mice) / sizeof(mice[0]);

    // Find the minimum time for all mice to reach holes
    int minTime = minTimeToReachHoles(mice, holes, n);

    // Print the result
    printf("Minimum time for all mice to reach holes: %d\n", minTime);

    return 0;
}