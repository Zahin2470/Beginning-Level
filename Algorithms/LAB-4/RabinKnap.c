#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet

// Function to search for a pattern in a text using Rabin-Karp algorithm
void searchRabinKarp(char *pattern, char *text) {
    int M = strlen(pattern);
    int N = strlen(text);
    int q = 101; // A prime number for hashing

    // Calculate hash value for the pattern and the first window of text
    int patternHash = 0; 
    int windowHash = 0;
    int h = 1;

    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < M; i++) {
        patternHash = (d * patternHash + pattern[i]) % q;
        windowHash = (d * windowHash + text[i]) % q;
    }

    // Slide the window and check for a match
    for (int i = 0; i <= N - M; i++) {
        // Check if hash values match
        if (patternHash == windowHash) {
            // Check character by character for a match
            int j;
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            // Pattern found at index i
            if (j == M)
                printf("Pattern found at index %d\n", i);
        }

        // Calculate hash value for the next window
        if (i < N - M) {
            windowHash = (d * (windowHash - text[i] * h) + text[i + M]) % q;

            // Ensure the hash value is non-negative
            if (windowHash < 0)
                windowHash = (windowHash + q);
        }
    }
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog.";
    char pattern[] = "fox";

    // Search for the pattern in the text using Rabin-Karp
    searchRabinKarp(pattern, text);

    return 0;
}