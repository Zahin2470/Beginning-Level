#include <stdio.h>
#include <stdlib.h>

// Structure to represent a schedule
struct Schedule {
    float arrival;
    float departure;
};

// Function to compare two schedules based on arrival time (used for sorting)
int compareSchedules(const void *a, const void *b) {
    return ((struct Schedule *)a)->arrival - ((struct Schedule *)b)->arrival;
}

// Function to find minimum number of platforms needed using a greedy approach
int minPlatforms(struct Schedule schedules[], int n) {
    // Sort schedules based on arrival times
    qsort(schedules, n, sizeof(struct Schedule), compareSchedules);

    int platformsNeeded = 1; // Number of platforms needed initialized to 1
    int maxPlatformsNeeded = 1; // Maximum number of platforms needed initialized to 1

    // Iterate through schedules
    for (int i = 1, j = 0; i < n && j < n;) {
        // If the next train arrives before the previous departure, increment platforms needed
        if (schedules[i].arrival <= schedules[j].departure) {
            platformsNeeded++;
            if (platformsNeeded > maxPlatformsNeeded)
                maxPlatformsNeeded = platformsNeeded;
            i++;
        }
        // If the train departs, decrement platforms needed
        else {
            platformsNeeded--;
            j++;
        }
    }
    return maxPlatformsNeeded;
}

int main() {
    int n = 6;
    struct Schedule schedules[] = {
        {2.00, 2.30}, {2.10, 3.40},
        {3.00, 3.20}, {3.20, 4.30},
        {3.50, 4.00}, {5.00, 5.20}
    }; // Schedules with arrival and departure times

    int minPlatformsNeeded = minPlatforms(schedules, n);
    printf("Minimum number of platforms needed: %d\n", minPlatformsNeeded);
    return 0;
}