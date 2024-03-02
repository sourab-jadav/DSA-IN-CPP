#include <iostream>
#include <regex>
#include <string>
#include <vector>
// https://leetcode.com/problems/unique-paths-ii/description/
using namespace std;
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
class Solution {
    public:
        // recursive approach
        // int solve(vector<vector<int>>& obstacleGrid, int i, int j,
        // vector<vector<int>> dp){
        //     // finding  number of ways to reach from start to bottom right
        //     // writing the basecase
        //     if (i>=obstacleGrid.size() or j>=obstacleGrid[0].size() or
        //     obstacleGrid[i][j]==1) return 0;
        //     // we are at i j
        //     // here if we reached the bottom then return the result
        //     if (i== obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1) {
        //         return 1;
        //     }
        //     //adding the result of taking the bottom and taking the right
        //     return  solve(obstacleGrid, i+1, j, dp)+solve(obstacleGrid, i, j+1,
        //     dp);
        // }
        //
        int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {

        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                break;
            }
            dp[i][0]=1;
        }
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1){
                break;
            }
            dp[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
        }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>> obstacleGrid = {{0, 0}, {1, 1}, {0, 0}};
    std::cout << Solution().uniquePathsWithObstacles(obstacleGrid) << std::endl;
    return 0;
}

// sanitizer error in the code below

            // int m = obstacleGrid.size();
            // int n = obstacleGrid[0].size();
            //
            // vector<vector<int>> dp(m, vector<int>(n, 0));
            // // if (dp[m-1][n-1]==1) {
            // //     return 0;
            // // }
            //
            //     for (int i = m - 1; i >= 0; i--) {
            //         if (obstacleGrid[i][n - 1] == 1) {
            //             break;
            //         }
            //         dp[i][n - 1] = 1;
            //     }
            //
            //     for (int j = n - 1; j >= 0; j--) {
            //         if (obstacleGrid[m - 1][j] == 1) {
            //             break;
            //         }
            //         dp[m - 1][j] = 1;
            //     }
            //     for (int i = m - 2; i >= 0; i--) {
            //         for (int j = n - 2; j >= 0; j--) {
            //             if (obstacleGrid[i][j] == 0) {
            //                 dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            //             }
            //         }
            //     }
            // return dp[0][0];
            //
