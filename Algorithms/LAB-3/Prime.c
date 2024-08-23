#include <stdio.h>

// Function to print prime factors of a number
void primeFactors(int n) {
    // Print 2 as a factor and divide n by 2
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    // Now n must be odd, start from 3 and go up to square root of n
    for (int i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    // If n is a prime number greater than 2
    if (n > 2)
        printf("%d ", n);
}

int main() {
    int n = 315;
    printf("Prime factors of %d are: ", n);
    primeFactors(n);
    printf("\n");
    return 0;
}