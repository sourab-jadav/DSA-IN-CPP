#include <bits/stdc++.h>
using namespace std;
// int removeDuplicates(vector<int> &nums)
// {
//     // each element should appear atmost twice
//     int n = nums.size();
//     // atmost means <= 2
//     for (int i = 1; i < n;)
//     {
//         int count = 1;
//         int j = i - 1;
//         while (nums[i] == nums[i - 1] && i < n)
//         {
//             count++;
//             i++;
//         }
//         if (count <= 2)
//         {
//             i++;
//             continue;
//         }
//         else
//         {
//             for (int m = j + 2, k = j + count; k < n; k++, m++)
//             {
//                 nums[m] = nums[k];
//             }
//             n = n - (count - 2);
//         }
//     }
//     return n;
// }
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
int main()
{
    cout << "hello world" << endl;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(nums);
    return 0;
}
