#include <iostream>
#include <algorithm>
#include <cstring> // for memset
using namespace std;

#define MAX 10000000

int dp[1001][1001]; // assuming maximum values for i and k
int amount[1001];
int c[1001];

int func(int i, int k)
{
    // 0(n x K x P)
    if (k == 0)
        return 0;
    if (k < 0 || i == 0)
        return MAX;
    if (dp[i][k] != -1)
        return dp[i][k];
    int r1 = MAX;
    for (int j = 1; j <= amount[i]; j++)
    {
        r1 = min(r1, func(i - 1, k - c[i] * j) + j);
    }
    int r2 = func(i - 1, k);
    int ans = min(r1, r2);
    dp[i][k] = ans;
    return dp[i][k];
}

int main()
{
    int n, k;
    cin >> n >> k; // assuming n is the number of items and k is the target sum

    memset(dp, -1, sizeof(dp)); // initializing dp array with -1

    for (int i = 1; i <= n; i++)
    {
        cin >> amount[i] >> c[i]; // input amount and cost of each item
    }

    int result = func(n, k);
    if (result >= MAX)
        cout << "Impossible" << endl;
    else
        cout << "Minimum number of items required: " << result << endl;

    return 0;
}
