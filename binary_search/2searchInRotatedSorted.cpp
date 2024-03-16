#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=list&envId=pb0os86r
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int l = 0, r = n-1;
        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
        }
        int rot = l;
        l = 0, r = n-1;
        while(l <= r) {
            int m = (l+r)/2;
            int real_m = (m+rot)%n;
            if(nums[real_m] == target) return real_m;
            if(nums[real_m] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }
};
int main() {
     Solution s;
     std::vector<int> v = {4,5,6,7,0,1,2};
        std::cout << s.search(v, 0) << std::endl;
    return 0;
}


