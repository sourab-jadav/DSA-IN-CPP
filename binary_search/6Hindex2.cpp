#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.com/problems/h-index-ii/description/?envType=list&envId=pb0os86r
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int m = (l+r)/2;
            if(citations[m] == n-m) return n-m;
            if(citations[m] < n-m) l = m+1;
            else r = m-1;
        }
        return n-l;
    }
};
int main() {
    Solution s;
    std::vector<int> v = {3,0,6,1,5};
    std::cout << s.hIndex(v) << std::endl;
    return 0;
}


