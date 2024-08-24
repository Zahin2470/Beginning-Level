#include <stdio.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

int maxActivities(struct Activity activities[], int n) {
    int selected = 1; // First activity is always selected
    int prevFinish = activities[0].finish;

    // Iterate through remaining activities
    for (int i = 1; i < n; i++) {
        // If current activity doesn't overlap with previous, select it
        if (activities[i].start >= prevFinish) {
            selected++;
            prevFinish = activities[i].finish;
        }
    }
    return selected;
}

int main() {
    struct Activity activities[] = {{10, 20}, {12, 25}, {20, 30}, {32,41}, {40,50}};
    int n = sizeof(activities) / sizeof(activities[0]);         
    int max = maxActivities(activities, n);
    printf("Maximum number of activities: %d\n", max);  
    return 0;
}