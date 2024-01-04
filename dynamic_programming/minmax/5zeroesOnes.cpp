#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int solve(vector<string> &strs, int m, int n, int zero_count, int one_count, int i) {
            if ((zero_count == m && one_count == n) || i == (int)strs.size()) {
                return 0;
            }
            string temp = strs[i];
            int count = 0;
            for (auto &x : temp) {
                if (x == '0') {
                    count++;
                }
            }
            int result=-1;
            if (zero_count + count <= m && one_count + (int)temp.size() - count <= n) {
                int include = 1 + solve(strs, m, n, zero_count + count, one_count + (int)temp.size() - count, i + 1);
                int notinclude = 0 + solve(strs, m, n, zero_count, one_count, i + 1);
                result=max(include,notinclude);
            }else{
                result=solve(strs, m, n, zero_count, one_count, i+1);
            }
            return result;
        }

        int findMaxForm(vector<string> &strs, int m, int n) {
            return solve(strs, m, n, 0, 0, 0);
        }
};
int main() {
    vector<string> strs{"10","0","1"};
    Solution s;
    int result=s.findMaxForm(strs, 1, 1);
    std::cout<<result<<std::endl;
    return 0;
}
