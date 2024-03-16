#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
        }
        return nums[l];
        
    }
};
int main() {
    Solution s;
    std::vector<int> v = {4,5,6,7,0,1,2};
    std::cout << s.findMin(v) << std::endl;
    
    return 0;
}


