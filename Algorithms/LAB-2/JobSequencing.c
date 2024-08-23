#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to store job information
struct Job {
    int id;    
    int loss; 
    int time;  
};

// Comparison function for sorting jobs based on loss in descending order
int compareJobs(const void *a, const void *b) {
    return ((struct Job *)b)->loss - ((struct Job *)a)->loss;
}

// Function to find the sequence with minimized loss
void findMinimizedLossSequence(int *loss, int *time, int n) {
    struct Job jobs[n];

    // Initialize job information
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].loss = loss[i];
        jobs[i].time = time[i];
    }

    // Sort jobs based on loss in descending order
    qsort(jobs, n, sizeof(struct Job), compareJobs);

    // Array to store the sequence of jobs
    int sequence[n];
    // Array to keep track of time slots availability
    int slots[n];
    for (int i = 0; i < n; i++) {
        slots[i] = 0;
    }

    // Find the sequence with minimized loss
    for (int i = 0; i < n; i++) {
        for (int j = fmin(n, jobs[i].time) - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                sequence[j] = jobs[i].id;
                slots[j] = 1;
                break;
            }
        }
    }

    // Print the sequence
    printf("Minimized Loss Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int main() {
    // Sample input
    int loss[] = {3, 1, 2, 4};
    int time[] = {4, 1000, 2, 5};
    int n = sizeof(loss) / sizeof(loss[0]);

    // Find the sequence with minimized loss
    findMinimizedLossSequence(loss, time, n);

    return 0;
}