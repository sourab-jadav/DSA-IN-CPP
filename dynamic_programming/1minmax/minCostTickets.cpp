#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/minimum-cost-for-tickets/
// Input: days = [1,4,6,7,8,20], costs = [2,7,15]
// Output: 11
// Explanation: For example, here is one way to buy passes that lets you travel
// your travel plan: On day 1, you bought a 1-day pass for costs[0] = $2, which
// covered day 1. On day 3, you bought a 7-day pass for costs[1] = $7, which
// covered days 3, 4, ..., 9. On day 20, you bought a 1-day pass for costs[0] =
// $2, which covered day 20. In total, you spent $11 and covered all the days of
// your travel. solving with the help of recursion we will have three options
// 1. we can buy a 1 day pass
// 2. we can buy a 7 day pass
// 3. we can buy a 30 day pass
// we will keep track of the minimum cost of the three options
//
// class Solution {
//     public:
//         int solve(vector<int> &days, vector<int> &costs, int i, vector<int>
//         &memo) {
//             if (i == days.size()) {
//                 return 0;
//             }
//             if (memo[i] != -1) {
//                 return memo[i];
//             }
//             int ans = INT_MAX;
//             int j = i;
//             for (int k = 0; k < 3; k++) {
//                 while (j < days.size() && days[j] < days[i] + (k == 0   ? 1
//                             : k == 1 ? 7
//                             : 30)) {
//                     j++;
//                 }
//                 ans = min(ans, costs[k] + solve(days, costs, j, memo));
//             }
//             memo[i] = ans;
//             return ans;
//         }
//         int mincostTickets(vector<int> &days, vector<int> &costs) {
//             vector<int> memo(days.size(), -1);
//             return solve(days, costs, 0, memo);
//         }
// };
// solution with dp
// 
class Solution {
    public:
        int mincostTickets(vector<int> &days, vector<int> &costs) {
            vector<int> dp(366, 0); // here we are using 366 because the maximum number of days is 365
            int j = 0;
            for (int i = 1; i < 366; i++) {
                if (i != days[j]) { // here we are checking if the current day is not in the days vector
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1],
                            dp[max(0, i - 30)] + costs[2]});
                    j++;
                }
            }
            return dp[days.back()];
        }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution s;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    std::cout << s.mincostTickets(days, costs) << std::endl;
    return 0;
}
