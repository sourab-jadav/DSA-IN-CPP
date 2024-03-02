#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// https://leetcode.com/problems/ones-and-zeroes/description/
// class Solution {
//     public:
//         int solve(vector<pair<int, int>> &vec, int m, int n, int i) {
//             if (i == vec.size()) {
//                 return 0;
//             }
//             int ans = 0;
//             if (vec[i].first <= m && vec[i].second <= n) {
//                 ans = max(ans, 1 + solve(vec, m - vec[i].first, n -
//                 vec[i].second, i + 1));
//             }
//             ans = max(ans, solve(vec, m, n, i + 1));
//             return ans;
//         }
//         int findMaxForm(vector<string> &strs, int m, int n) {
//             vector<pair<int, int>> vec;
//             for (int i = 0; i < strs.size(); i++) {
//                 pair<int, int> p;
//                 for (auto x : strs[i]) {
//                     if (x == '0') {
//                         p.first++;
//                     } else {
//                         p.second++;
//                     }
//                 }
//                 vec.push_back(p);
//             }
//             return solve(vec, m, n, 0);
//         }
//
// };

// solving it using dp
class Solution {
    public:
        int findMaxForm(vector<string> &strs, int m, int n) {
            vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
            for (auto &s : strs) {
                int zeros = 0, ones = 0;
                for (auto c : s) {
                    if (c == '0')
                        zeros++;
                    else
                        ones++;
                }
                for (int i = m; i >= zeros; i--) {
                    for (int j = n; j >= ones; j--) {
                        dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                    }
                }
            }
            return dp[m][n];
        }
};

int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    // here the basic idea was to make the pairs of 0s and 1s and then find the
    // max pairs that can be made
    int m = 5, n = 3;
    Solution s;
    std::cout << s.findMaxForm(strs, m, n) << std::endl;
    return 0;
}
