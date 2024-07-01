#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int start = -1, end = -1;
        while(l <= r) {
            int m = (l+r)/2;
            if(nums[m] == target) {
                start = m;
                r = m-1;
            } else if(nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        l = 0, r = n-1;
        while(l <= r) {
            int m = (l+r)/2;
            if(nums[m] == target) {
                end = m;
                l = m+1;
            } else if(nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return {start, end};
        
    }
};
int main() {
    Solution s;
    std::vector<int> v = {5,7,7,8,8,8,8,10};
    std::vector<int> res = s.searchRange(v, 8);
    for(auto i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


