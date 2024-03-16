#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] > nums[m+1]) r = m;
            else l = m+1;
        }
        return l;
        
    }
};
int main() {
    Solution s;
    std::vector<int> v = {1,2,3,1};
    std::cout << s.findPeakElement(v) << std::endl;
    return 0;
}


