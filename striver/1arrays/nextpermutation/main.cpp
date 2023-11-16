#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverse(vector<int> &temp, int low, int high)
    {
        while (low < high)
        {
            swap(temp[low], temp[high]);
            low++;
            high--;
        }
    }
    void nextPermutation(vector<int> &nums)
    {
        // next_permutation(nums.begin(),nums.end());
        int n = nums.size();
        if (n <= 1)
        {
            return;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                int j = i + 1;
                while (nums[j] > nums[i] && j < n)
                {
                    j++;
                }
                swap(nums[i], nums[j - 1]);
                reverse(nums, i + 1, n - 1);
                return;
            }
        }
        reverse(nums, 0, n - 1);
    }
};
int main()
{
    Solution s;
    vector<int> arr{1, 2, 0, 3, 0, 1, 2, 4};
    s.nextPermutation(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}