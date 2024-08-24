#include <stdio.h>
#include <string.h>

void searchRabinKarp(char *pattern, char *text) {
    int m = strlen(pattern);
    int n = strlen(text);

    // Slide the pattern over the text
    for (int i = 0; i <= n - m; i++) {
        // Check character by character for a match
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            // Pattern found at index i
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    // Sample input
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char pattern[] = "fox";

    // Search for the pattern in the text using Rabin-Karp algorithm without hashing
    searchRabinKarp(pattern, text);

    return 0;
}