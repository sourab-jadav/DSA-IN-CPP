#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// let's recurse the shit
//
// apporach one failed at some testcase
// i think this approach is not so generalized .
// class Solution {
// public:
//   int solve(vector<int> &coins, int amount, int i) {
//     // the idea is to return fewest amount of money that can be made
//     // you follow the idea of include and don't include later
//     if (amount == 0) {
//       return 0;
//     }
//     if (amount - coins[i] >= 0) {
//       // return 1 + solve(coins, amount - coins[i], i); // this is where you
//       got stuck at input amount =3 and coins[2]
//         int result=solve(coins, amount-coins[i], i);
//         if (result==-1) {
//             return -1;
//         }else{
//             return result+1;
//         }
//     } else {
//       if (i > 0) {
//         return solve(coins, amount, i - 1);
//       }
//     }
//     return -1;
//   }
//   int coinChange(vector<int> &coins, int amount) {
//     int n = coins.size();
//     sort(coins.begin(), coins.end());
//     for (int i = n - 1; i >= 0; i--) {
//         int ans= solve(coins, amount, i);
//         if (ans!=-1) {
//             return ans;
//         }
//     }
//     return -1;
//   }
// };
// for some reason it is failing at
// coins =
// [186,419,83,408]
// amount =
// 6249
// Use Testcase
// Output
// -1
// Expected
// 20

// the right solution
// class Solution {
// public:
//   int solve(vector<int> &coins, int amount, int i) {
//     // the idea is to return fewest amount of money that can be made
//     // you follow the idea of include and don't include later
//     // when the number is subtractable you consider the result of including
//     the
//     // number and not including the number and finding the minimum of both
//     //
//     // when the number is not subtractable you don't consider that number
//     if (i < 0 || amount <= 0) {
//       return (amount == 0) ? 0:INT_MAX - 1;
//     }
//     int res = -1;
//     if (amount - coins[i] >= 0) {
//       // return 1 + solve(coins, amount - coins[i], i); // this is where you
//       got
//       // stuck at input amount =3 and coins[2]
//       int include = 1 + solve(coins, amount - coins[i], i);
//       int notinclude = 0 + solve(coins, amount, i - 1);
//       res = min(include, notinclude);
//     } else {
//       res = solve(coins, amount, i - 1);
//     }
//     return res;
//   }
//   int coinChange(vector<int> &coins, int amount) {
//     int n = coins.size();
//     int result=solve(coins, amount, n-1);
//     return (result!=INT_MAX-1)?result:-1;
//   }
// };
//
// memoizing the shit
// class Solution {
// public:
//   int solve(vector<int> &coins, int amount, int i) {
//     // the idea is to return fewest amount of money that can be made
//     // you follow the idea of include and don't include later
//     // when the number is subtractable you consider the result of including
//     the
//     // number and not including the number and finding the minimum of both
//     //
//     // when the number is not subtractable you don't consider that number
//     if (i < 0 || amount <= 0) {
//       return (amount == 0) ? 0:INT_MAX - 1;
//     }
//     int res = -1;
//     if (amount - coins[i] >= 0) {
//       // return 1 + solve(coins, amount - coins[i], i); // this is where you
//       got
//       // stuck at input amount =3 and coins[2]
//       int include = 1 + solve(coins, amount - coins[i], i);
//       int notinclude = 0 + solve(coins, amount, i - 1);
//       res = min(include, notinclude);
//     } else {
//       res = solve(coins, amount, i - 1);
//     }
//     return res;
//   }
//   int coinChange(vector<int> &coins, int amount) {
//     int n = coins.size();
//     int result=solve(coins, amount, n-1);
//     return (result!=INT_MAX-1)?result:-1;
//   }
// };
// memoize the solution
// class Solution {
//     public:
//         int coinChange(vector<int> &coins, int amount) {
//             unordered_map<int, int> memo;
//             solve(coins, amount, memo);
//             if (memo[amount] == INT_MAX - 1) {
//                 return -1;
//             } else {
//                 return memo[amount];
//             }
//         }
//
//         int solve(vector<int> &coins, int amount, unordered_map<int, int> &memo) {
//             auto it = memo.find(amount);
//             if (it != memo.end()) {
//                 return it->second;
//             }
//
//             if (amount == 0) {
//                 return 0;
//             }
//
//             int result = INT_MAX - 1;
//
//             for (int i = 0; i < (int)coins.size(); i++) {
//                 if (amount - coins[i] >= 0) {
//                     int subResult = solve(coins, amount - coins[i], memo);
//                     if (subResult != INT_MAX - 1) {
//                         result = min(result, subResult + 1);
//                     }
//                 }
//             }
//
//             return memo[amount] = result;
//         }
// };

// bottom up dp

class Solution {
    public:
        int coinChange(vector<int> &coins, int amount) {
            unordered_map<int, int> memo;
            return solve(coins, amount, memo);
        }

        int solve(vector<int> &coins, int amount, unordered_map<int, int> &memo) {
            // first we are solving for smaller amounts then we are solving the bigger
            // amounts with the smaller amounts we start from amount =1 and go till
            // amount = amount and solve for each amount and store the result in the
            // memo
            vector<int> dp(amount + 1, INT_MAX - 1);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < (int)coins.size(); j++) {
                    if (i - coins[j] >= 0) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            std::cout << dp[amount] << std::endl;
            return dp[amount];
        }
};
int main() {
    std::vector<int> coins{1, 2, 5};
    int amount = 11;
    Solution s;
    int res = s.coinChange(coins, amount);
    std::cout << res << std::endl;
}
