#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// recurse the shit
class Solution {
public:
    int solve(vector<vector<char>>&matrix,int i,int j){
        // if at current i j the value is 0
        // or i== rowsize or j==colsize  then return 0;
        if (i==(int)matrix.size()|| j==(int)matrix[0].size() || matrix[i][j]=='0') {
            return 0;
        }
        // now that the value is 1
        // we check right,bottom,diagonal

        return 1+min(solve(matrix, i, j+1),min(solve(matrix, i+1, j),solve(matrix, i+1, j+1)));
    }
  int maximalSquare(vector<vector<char>> &matrix) {
      // finding the maximum square
      // first you traverse through each element and look for max
      // imum square
      int row=matrix.size();
      int column=matrix[0].size();
      int result=INT_MIN;
      for(int i=0;i<row;i++){
          for(int j=0;j<column;j++){
              int x=solve(matrix, i, j); // you will get max number of 1's// possible
              result=max(result,x*x);                    
          }
      }
      std::cout<<result<<std::endl;
      return 0;
  }
};
//
//memoize the shit
// class Solution {
// public:
//     int solve(vector<vector<char>>&matrix,int i,int j,vector<vector<int>>&memo){
//         // if at current i j the value is 0
//         // or i== rowsize or j==colsize  then return 0;
//         if (i==(int)matrix.size()|| j==(int)matrix[0].size() || matrix[i][j]=='0') {
//             return 0;
//         }
//         if (memo[i][j]!=-1) {
//             return memo[i][j];
//         }
//         // now that the value is 1
//         // we check right,bottom,diagonal
//
//         return memo[i][j]=1+min(solve(matrix, i, j+1,memo),min(solve(matrix, i+1, j,memo),solve(matrix, i+1, j+1,memo)));
//     }
//   int maximalSquare(vector<vector<char>> &matrix) {
//       // finding the maximum square
//       // first you traverse through each element and look for max
//       // imum square
//       int row=matrix.size();
//       int column=matrix[0].size();
//       vector<vector<int>>memo(row,vector<int>(column,-1));
//       int result=INT_MIN;
//       for(int i=0;i<row;i++){
//           for(int j=0;j<column;j++){
//               int x=solve(matrix, i, j,memo); // you will get max number of 1's// possible
//               result=max(result,x*x);                    
//           }
//       }
//       for(auto &row:memo){
//           for(auto &x:row){
//               std::cout<<x<<" ";
//           }
//           std::cout<<std::endl;
//       }
//       return 0;
//   }
// };

// tabulize the shit
// thinking of the bottom up way
// class Solution {
// public:
//    
//     int solve(vector<vector<char>>&matrix){
//         int row=(int)matrix.size();
//         int column=(int)matrix[0].size();
//         int dp[row][column];
//         memset(dp, 0, sizeof(dp));
//         int result=0;
//         for(int i=0;i<row;i++){
//             if (matrix[i][column-1]=='1') {
//                dp[i][column-1]=1; 
//                result=1;
//             }
//         }
//         for(int j=0;j<column;j++){
//             if (matrix[row-1][j]=='1') {
//                 dp[row-1][j]=1;
//                 result=1;
//             }
//         }
//         // for selecting only first row and first column 
//         for(int i=row-2;i>=0;i--){
//             for(int j=column-2;j>=0;j--){
//                 if (matrix[i][j]=='1') {
//                 dp[i][j]=1+min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
//                 }
//                 result=max(result,dp[i][j]);
//             }
//         }
//         return result;
//     }
//
//   int maximalSquare(vector<vector<char>> &matrix) {
//       int res=solve(matrix);
//       return res*res;
//   }
// };

int main() {
  std::vector<std::vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                        {'1', '0', '1', '1', '1'},
                                        {'1', '1', '1', '1', '1'},
                                        {'1', '0', '0', '1', '0'}};
  Solution s;
  std::cout<<s.maximalSquare(matrix)<<std::endl;
  return 0;
}
