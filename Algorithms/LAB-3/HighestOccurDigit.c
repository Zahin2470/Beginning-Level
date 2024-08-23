#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Function to find the highest occurring digit in prime numbers between L and R
int highestOccurringDigit(int L, int R) {
    int freq[10] = {0};
    for (int i = L; i <= R; i++) {
        if (isPrime(i)) {
            int temp = i;
            while (temp > 0) {
                freq[temp % 10]++;
                temp /= 10;
            }
        }
    }
    int maxFreq = 0, digit = -1;
    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxFreq || (freq[i] == maxFreq && i > digit)) {
            maxFreq = freq[i];
            digit = i;
        }
    }
    return digit;
}

int main() {
    int L = 1, R = 20; // Sample input
    int result = highestOccurringDigit(L, R);
    printf("Highest occurring digit in prime numbers between %d and %d is %d\n", L, R, result);
    return 0;
}