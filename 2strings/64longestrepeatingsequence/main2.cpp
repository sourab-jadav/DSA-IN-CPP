#include <bits/stdc++.h>

using namespace std;
// This function mainly returns LCS(str, str)
// with a condition that same characters at
// same index are not considered.
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
    // Create and initialize DP table
    int dp[n + 1] = {0};

    // Fill dp table (similar to LCS loops)
    for (int i = 1; i <= n; i++)
    {
        int new_a[n + 1] = {0};
        for (int j = 1; j <= n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i - 1] == str[j - 1] && i != j)
            {
                new_a[j] = 1 + dp[j - 1];
            }
            // If characters do not match
            else
            {
                new_a[j] = max(dp[j], new_a[j - 1]);
            }
        }
        for (int j = 0; j <= n; j++)
            dp[j] = new_a[j];
    }
    return dp[n];
}
// Driver Program
int main()
{
    string str = "axxxy";
    cout << "The length of the largest subsequence that "
         << " repeats itself is : " << findLongestRepeatingSubSeq(str);
    return 0;
}