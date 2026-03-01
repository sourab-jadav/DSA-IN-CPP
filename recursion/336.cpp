#include <bits/stdc++.h>

using namespace std;

int find(vector<int> &coins, int n, int amount)
{
    if (n == 0)
    {
        return INT_MAX;
    }
    if (amount == 0)
    {
        return 0;
    }
    int result;
    if (amount - coins[n - 1] >= 0)
    {
        int result = min(find(coins, n - 1, amount), find(coins, n, amount - coins[n - 1]));
    }
    else
    {
        find(coins, n - 1, amount);
    }

    if (result == INT_MAX)
    {
        return INT_MAX;
    }
    else
    {
        return result + 1;
    }
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    return find(coins, n, amount);
}
int main()
{
    vector<int> vec{1, 2, 5};
    coinChange(vec, 11);
}