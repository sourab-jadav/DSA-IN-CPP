#include <bits/stdc++.h>

using namespace std;
bool checkpartition(vector<int> &nums, int curr_sum, int total_sum, int n, vector<vector<int>> &t)
{
    if (n == 0)
    {
        t[n][curr_sum]= curr_sum == (total_sum - curr_sum);
        return t[n][curr_sum];
    }
    if (t[n][curr_sum] != -1)
    {
        return t[n][curr_sum];
    }
    t[n][curr_sum] = checkpartition(nums, curr_sum + nums[n - 1], total_sum, n - 1, t) || checkpartition(nums, curr_sum, total_sum, n - 1, t);
    cout << "something" << endl;
    return t[n][curr_sum];
}
bool canPartition(vector<int> &nums)
{
    int curr_sum{};
    for (auto x : nums)
    {
        curr_sum += x;
    }
    int n = nums.size();
    vector<vector<int>> t(n + 1, vector<int>(curr_sum + 1, -1));
    return checkpartition(nums, 0, curr_sum, n, t);
}
int main()
{
    vector<int> nums{1,5,11,5};
    bool result = canPartition(nums);
    cout << result;

    return 0;
}