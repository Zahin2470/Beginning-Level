#include<stdio.h>

#define MAX 1000000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int n, int w, int wi[], int vi[]) {
    int DP[n+1][w+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(i == 0 || j == 0)
                DP[i][j] = 0;
            else if(wi[i-1] <= j)
                DP[i][j] = max(vi[i-1] + DP[i-1][j-wi[i-1]], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    return DP[n][w];
}

int main() {
    int value[] = {3, 4, 5, 6};
    int weight[] = {2, 3, 4, 5};
    int W = 8;
    int n = sizeof(value)/sizeof(value[0]);
    printf("%d\n", knapsack(n, W, weight, value));
    return 0;
}