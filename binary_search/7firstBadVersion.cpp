#include <iostream>
#include <vector>
#include <string>
using namespace std;
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// https://leetcode.com/problems/first-bad-version/?envType=list&envId=pb0os86r
class Solution {
public:
    bool isBadVersion(int n) {
        if(n >= 4) return true;
        return false;
    }
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while(l < r) {
            int m = l + (r-l)/2;
            if(isBadVersion(m)) r = m;
            else l = m+1;
        }
        return l;
        
    }
};
int main() {
    Solution s;
    std::cout << s.firstBadVersion(5) << std::endl;

    return 0;
}


