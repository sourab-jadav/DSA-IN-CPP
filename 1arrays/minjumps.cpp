#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int> &nums, int l)
{
    if (l >= nums.size() - 1)
        return 0;
    int jumps = INT_MAX;
    for (int i = l + 1; i <= l + nums[l]; i++)
        jumps = min(jumps, 1 + minJumps(nums, i));
    return jumps;
}
int main()
{
    // vector<int> nums{2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    vector<int> nums{2, 3, 1, 1, 4};
    cout << minJumps(nums, 0);
}
