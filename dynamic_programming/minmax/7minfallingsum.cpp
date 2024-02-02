#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>
// https://leetcode.com/problems/minimum-falling-path-sum/description/
using namespace std;
// recursive solution
// class Solution {
// public:
//     int solve(vector<vector<int>>& matrix, size_t i, size_t j) {
//         if (j < 0 || j >= matrix[0].size()) {
//             return INT_MAX - 1;
//         }
//         if (i == matrix.size() - 1) {
//             return matrix[i][j];
//         }
//         int result = INT_MAX - 1;
//         int left = solve(matrix, i + 1, j - 1);
//         int bottom = solve(matrix, i + 1, j);
//         int right = solve(matrix, i + 1, j + 1);
//         result = min(left, min(bottom, right));
//         return result + matrix[i][j];
//     }
//
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         size_t minval = 0; // Use the size_t type for indices to match the
//         vector's size_type int result=INT_MAX-1; for (size_t i = 0; i <
//         matrix[0].size(); i++) {
//             result=min(result,solve(matrix, 0, i));
//         }
//         return result;
//     }
// };
// memoizng the above solution
// class Solution {
// public:
//     int solve(vector<vector<int>>& matrix, size_t i, size_t
//     j,vector<vector<int>>&memo) {
//          if (j < 0 || j >= matrix[0].size()) {
//             return INT_MAX - 1;
//         }
//         if (memo[i][j]!= INT_MAX-1) {
//             return memo[i][j];
//         }
//         if (i == matrix.size() - 1) {
//             return memo[i][j]=matrix[i][j];
//         }
//         int result = INT_MAX - 1;
//         int left = solve(matrix, i + 1, j - 1,memo);
//         int bottom = solve(matrix, i + 1, j,memo);
//         int right = solve(matrix, i + 1, j + 1,memo);
//         result = min(left, min(bottom, right));
//         return memo[i][j]=result + matrix[i][j];
// //            // now what to do you at start of the solution
//
//     }
//
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(),
//         INT_MAX - 1)); int result=INT_MAX-1; for (size_t i = 0; i <
//         matrix[0].size(); i++) {
//             result=min(result,solve(matrix, 0, i, memo));
//             // solve(matrix, 0, i, memo);
//             // result=min(result,memo[0][i]);
//         }
//         // for (auto x : memo) {
//         //     for (auto y : x) {
//         //     std::cout<<y<<" ";
//         //     }
//         //     std::cout<<std::endl;
//         // }
//         return result;
//     }
// };



// iterative
//Iterative bottom-up solution -construction solution from the top
class Solution {
public:
    int customMin(int a, int b, int c){
        return min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int ans=INT_MAX;
        // we are doing the bottom up then the base case is at bottom

        for(int r=1;r<rows;r++){
            for(int c=0;c<cols;c++){
                int leftD,middle,rightd;
                // if c==0 just check the right  and middle
                if (c==0) {
                    
                rightd=matrix[r-1][c+1];
                middle=matrix[r-1][c];
                matrix[r][c]+=min(rightd,middle);
                }else if (c== cols-1) {
                    leftD=matrix[r-1][c-1];
                    middle=matrix[r-1][c];
                    matrix[r][c]+=min(leftD,middle);
                }else {
                    leftD=matrix[r-1][c+1];
                    middle=matrix[r-1][c];
                    rightd=matrix[r-1][c-1];
                    matrix[r][c]+=customMin(leftD, middle, rightd);
                }

            }
        }
    }
};
// good coding // top down recursive 
// class Solution {
//     public:
//         int solve(vector<vector<int>> &matrix, size_t r, size_t c) {
//             // here he is traversing from bottom to top (considering elemets
//             from
//             // bottom)
//             if (r == 0 and c < matrix[0].size() and c >= 0) {
//                 return matrix[r][c];
//             }
//             // as we are checking the left bot and right check it's bound
//             if (c >= matrix[0].size() or c < 0) {
//                 return INT_MAX;
//             }
//             return matrix[r][c] +
//                 min(min(solve(matrix, r - 1, c + 1), solve(matrix, r - 1,
//                 c)),
//                         solve(matrix, r - 1, c - 1));
//         }
//
//         int minFallingPathSum(vector<vector<int>> &matrix) {
//             // get the rows size and col size
//             int rows = matrix.size(), cols = matrix[0].size();
//             int ans = INT_MAX;
//             for (int c = 0; c < cols; c++) {
//                 ans = min(ans, solve(matrix, rows - 1, c));
//             }
//
//             return ans;
//         }
// };

// top down recursive with memo
// class Solution {
//     public:
//         int solve(vector<vector<int>> &matrix, size_t r, size_t c,
//                 vector<vector<int>> &dp) {
//             // here he is traversing from bottom to top (considering elemets from
//             // bottom)
//             if (r == 0 and c < matrix[0].size() and c >= 0) {
//                 return matrix[r][c];
//             }
//             // as we are checking the left bot and right check it's bound
//             if (c >= matrix[0].size() or c < 0) {
//                 return INT_MAX;
//             }
//             if (dp[r][c] != INT_MAX) {
//                 return dp[r][c];
//             }
//
//             return dp[r][c]=matrix[r][c] + min(min(solve(matrix, r - 1, c + 1, dp),
//                         solve(matrix, r - 1, c, dp)),
//                     solve(matrix, r - 1, c - 1, dp));
//         }
//
//         int minFallingPathSum(vector<vector<int>> &matrix) {
//             // get the rows size and col size
//             int rows = matrix.size(), cols = matrix[0].size();
//             vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
//             int ans = INT_MAX;
//             for (int c = 0; c < cols; c++) {
//                 ans = min(ans, solve(matrix, rows - 1, c, dp));
//             }
//             return ans;
//         }
// };
int main() {
    // vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> matrix = {{-80, -13, 22}, {83, 94, -5}, {73, -48, 61}};
    // vector<vector<int>> matrix =  {{-19,57},{-40,-5}};
    Solution s;
    std::cout << s.minFallingPathSum(matrix) << std::endl;
    return 0;
}
