#include <stdio.h>
#include <string.h>

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of the longest palindromic subsequence
int longestPalindromicSubsequence(char *str) {
    int n = strlen(str);
    int dp[n][n]; // dp[i][j] will store the length of LPS from index i to j

    // LPS of substring with length 1 is always 1
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Build the table for LPS starting from substrings of length 2 to n
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && len == 2)
                dp[i][j] = 2;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }

    return dp[0][n - 1]; // Return the length of LPS from index 0 to n-1
}

int main() {
    char str[] = "BBABCBCAB";
    int length = longestPalindromicSubsequence(str);
    printf("Length of longest palindromic subsequence: %d\n", length);
    return 0;
}