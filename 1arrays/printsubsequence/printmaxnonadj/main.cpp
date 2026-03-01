#include <bits/stdc++.h>

using namespace std;

int printmaxsum(int arr[], int n, int i, int dp[])
{

    if (i >= n)
    {
        return 0;
    }
    if (dp[i] != 0)
    {
        return dp[i];
    }
    return dp[i] = max(arr[i] + printmaxsum(arr, n, i + 2, dp), printmaxsum(arr, n, i + 1, dp));
}

int main(int argc, char const *argv[])
{
    // memoizing the above approach
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    cout << printmaxsum(arr, n, 0, dp);
    return 0;
}
