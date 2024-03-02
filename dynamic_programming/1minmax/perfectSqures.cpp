#include <algorithm>
#include <iostream>
// https://leetcode.com/problems/perfect-squares/description/?envType=list&envId=p1mnzpke

using namespace std;
// Example 1:
//
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// class Solution {
// public:
//     int solve(int n){
//         int result=0;
//         for(int i=1;i*i<n;i++){
//             result=max(result,max(solve(n-i*i),))
//
//         }
//     }
//     int numSquares(int n) {
//
//     }
// };

// class Solution {
// public:
//     int numSquares(int n) {
//         int dp[n+1];
//         dp[0]=0;
//         for(int i=1;i<=n;i++){
//             dp[i]=i;
//             for(int j=1;j*j<=i;j++){
//                 dp[i]=min(dp[i],dp[i-j*j]+1);
//             }
//         }
//         return dp[n];
//
//     }
// };
// recursive solution for the problem
// class Solution {
//     public:
//         int solve(int n) {
//             if (n == 0) {
//                 return 0;
//             }
//             int result = n;
//             for (int i = 1; i * i <= n; i++) {
//                 result = min(result, solve(n - i * i) + 1);
//             }
//             return result;
//         }
//         int numSquares(int n) { return solve(n); }
// };
//
//

class Solution {
    public:
        int solve(int n) {
            int dp[n+1];
            dp[0]=0; // you forgot this
            for(int i=1;i<=n;i++){
                dp[i]=i;
                for(int j=1;j*j<=i;j++){
                    dp[i]=min(dp[i],dp[i-j*j]+1);
                }
            }
            return dp[n];

        }
        int numSquares(int n) { return solve(n); }
};
int main() {
    Solution s;
    cout << s.numSquares(12) << endl;
    return 0;
}
