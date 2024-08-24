#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int minCoins(int coins[], int counts[], int n, int amount) {
    int DP[amount + 1];
    DP[0] = 0;

    for (int i = 1; i <= amount; i++) {
        DP[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int subCoins = DP[i - coins[j]];
                if (subCoins != INT_MAX && subCoins + 1 < DP[i]) {
                    DP[i] = subCoins + 1;
                    if (counts != NULL)
                        counts[j]--;
                }
            }
        }
    }
    return DP[amount];
}

int main() {
    int coinsInfinite[] = {1, 3, 5,7};
    int amountInfinite = 15;
    int nInfinite = sizeof(coinsInfinite) / sizeof(coinsInfinite[0]);
    printf("Infinite coins : %d\n", minCoins(coinsInfinite, NULL, nInfinite, amountInfinite));

    int coinsFinite[] = {1, 3, 5};
    int countsFinite[] = {2, 1, 1};
    int amountFinite = 8;
    int nFinite = sizeof(coinsFinite) / sizeof(coinsFinite[0]);
    printf("Finite coins : %d\n", minCoins(coinsFinite, countsFinite, nFinite, amountFinite));

    return 0;
}