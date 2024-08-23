#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int set[], int n, int sum)
{
if (sum == 0)
return true;
if (n == 0)
return false;
if (set[n - 1] > sum)
return isSubsetSum(set, n - 1, sum);

return isSubsetSum(set, n - 1, sum) || isSubsetSum(set, n - 1, sum - set[n - 1]);
}

int main()
{
int set[] = { 1,3,5,7,9 };
int sum = 12;
int n = sizeof(set) / sizeof(set[0]);
if (isSubsetSum(set, n, sum) == true)
printf("Yes");
else
printf("No");
return 0;
}