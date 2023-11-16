#include <bits/stdc++.h>

using namespace std;
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
    for (int k = n; k >= 2; k--)
    {
        int last = nums[k - 1];
        if (last == 0)
        {
            continue;
        }
        int i = k - 2;
        // while(nums[i]>last && i>=0){
        //     i--;
        // }
        int j;
        for (j = i; j >= 0; j--)
        {
            if (nums[j] < last)
            {
                break;
            }
        }
        if (j == -1)
        {
            continue;
        }
        else
        {
            swap(nums[j], nums[k - 1]);
            reverse(nums, j + 1, n - 1);
            return;
        }
    }
    reverse(nums, 0, n - 1);
}
int main()
{
    vector<int> arr{4, 2, 0, 2, 3, 2, 0};
    nextPermutation(arr);
}