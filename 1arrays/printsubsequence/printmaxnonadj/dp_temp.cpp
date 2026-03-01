#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]{3, 2, 7, 10};
    int n = 4;
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}