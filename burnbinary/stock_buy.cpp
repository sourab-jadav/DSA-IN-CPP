// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
// Function to calculate maximum
// profit possible by buying or
// selling stocks any number of times
int find(int ind, vector<int> &v, bool buy, vector<vector<int>> &memo)
{
    // No prices left
    if (ind >= v.size())
        return 0;
    // Already found
    if (memo[ind][buy] != -1)
        return memo[ind][buy];
    // Already bought, now sell
    if (buy)
    {
        return memo[ind][buy] = max(-v[ind] + find(ind + 1, v, !buy, memo), find(ind + 1, v, buy, memo));
    }
    // Otherwise, buy the stock
    else
    {
        return memo[ind][buy] = max(v[ind] + find(ind + 1, v, !buy, memo), find(ind + 1, v, buy, memo));
    }
}
// Function to find the maximum
// profit possible by buying and
// selling stocks any number of times
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n < 2)
        return 0;
    vector<vector<int>> v(n + 1, vector<int>(2, -1));
    return find(0, prices, 1, v);
}
// Driver Code
int main()
{
    // Given prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Function Call to calculate
    // maximum profit possible
    int ans = maxProfit(prices);
    // Print the total profit
    cout << ans << endl;
    return 0;
}