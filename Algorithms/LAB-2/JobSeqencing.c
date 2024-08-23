#include <stdio.h>
#include <stdlib.h>

// Structure to store job information
struct Job {
    char id;       // Job ID
    int deadline;  // Deadline of the job
    int profit;    // Profit of the job
};

// Comparison function for sorting jobs based on profit in descending order
int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to find the sequence with maximum profit
void findMaxProfitSequence(struct Job *jobs, int n) {
    // Sort jobs based on profit in descending order
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    // Array to keep track of time slots availability
    int slots[n];
    for (int i = 0; i < n; i++) {
        slots[i] = 0;
    }

    // Find the sequence with maximum profit
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                slots[j] = 1;
                printf("%c ", jobs[i].id);
                break;
            }
        }
    }
}

int main() {
    // Sample input
    struct Job jobs[] = {
        {'a', 4, 20},
        {'b', 1, 10},
        {'c', 1, 40},
        {'d', 1, 30}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Find the sequence with maximum profit
    findMaxProfitSequence(jobs, n);

    return 0;
}