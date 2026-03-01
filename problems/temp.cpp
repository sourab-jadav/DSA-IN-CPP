#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1, cnt;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for (int n : nums)
            {
                if (n <= mid)
                    ++cnt;
            }
            // binary search on left
            if (cnt <= mid)
                low = mid + 1;
            else
                // binary search on right
                high = mid - 1;
        }
        return low;
    }
    // for github repository link go to my profile.
};
void reverse(vector<int> &vec, int low, int high)
{
    while (low < high)
    {
        swap(vec[low], vec[high]);
        low++;
        high--;
    }
}
int main()
{
    // vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    vector<int> nums{1, 2, 3, 4, 3};
    Solution s;
    cout << s.findDuplicate(nums);
}
