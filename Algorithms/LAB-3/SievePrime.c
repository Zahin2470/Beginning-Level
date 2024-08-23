#include <stdio.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int limit) {
    bool prime[limit+1];
    
    // Initialize all elements of prime[] as true
    for (int i = 2; i <= limit; i++)
        prime[i] = true;

    // Iterate through all numbers starting from 2
    for (int p = 2; p * p <= limit; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }

    // Print prime numbers
    printf("Prime numbers up to %d are: ", limit);
    for (int p = 2; p <= limit; p++) {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");
}

int main() {
    int limit;
    printf("Enter the limit to find prime numbers: ");
    scanf("%d", &limit);
    sieve_of_eratosthenes(limit);
    return 0;
}