#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.com/problems/first-bad-version/?envType=list&envId=pb0os86r
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
                
        
    }
};
int main() {
    Solution s;
    std::vector<std::vector<int>> v = {{1,2}};
    std::vector<int> res = s.findRightInterval(v);
    for(auto i: res) std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}


