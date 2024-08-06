#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define printxyz(arr, rows, cols)                                              \
  do {                                                                         \
    std::cout << std::endl;                                                    \
    for (int i = 0; i < rows; ++i) {                                           \
      for (int j = 0; j < cols; ++j) {                                         \
        std::cout << arr[i][j] << " ";                                         \
      }                                                                        \
      std::cout << std::endl;                                                  \
    }                                                                          \
    std::cout << std::endl;                                                    \
  } while (0)

// solving the problem using the recursive approach
// the constraints we can move
// toward right
// towards right and up
// towards right and down
// int collectGold(vector<vector<int>>&vec,int i,int j){
//     // if (i<0 or j<0 or i>=vec.size() or j>=vec[0].size()) {
//     //     return 0;
//     // }
//     if (i<0 or i==vec.size() or j==vec[0].size()) {
//         return 0;
//     }
//     return vec[i][j]+max(max(collectGold(vec, i+1, j+1),collectGold(vec, i-1, j+1)),collectGold(vec, i, j+1));
// }
//
// int solve(vector<vector<int>>vec){
//     int maxGold=0;
//     for(int i=0;i<vec.size();i++){
//         int goldCollected=collectGold(vec, i, 0);
//         maxGold=max(maxGold,goldCollected);
//     }
//     return maxGold;
// }
//


// dynamic programming solution :
//
int solveDP(vector<vector<int>>&vec){
    int n=vec.size();
    int m=vec[0].size();
    int dp[n][m];
    memset(dp, 0, sizeof dp);
    for(int i=0;i<n;i++){
        dp[i][0]=vec[i][0];
    }
    int result=0;
    for(int c=1;c<m;c++){
        for(int r=0;r<n;r++){
            // for a given r c 
            // we calculate it's left diag path
            // right diag path
            // and the left path
            int left=dp[r][c-1];
            int left_top=(r-1>=0)?dp[r-1][c-1]:0;
            int left_bottom=(r+1<n)?dp[r+1][c-1]:0;
            dp[r][c]=max(max(left_top,left_bottom),left)+vec[r][c];
            result=max(result,dp[r][c]);
        }
    }
    printxyz(dp, n, m);
    return result;
}
// further optimizing the dp solution
int f_optimize_dp(vector<vector<int>>vec){
    int n=vec.size();
    int m=vec[0].size();
    // int dp[n];
    // for(int i=0;i<n;i++){
    //     dp[i]=vec[i][0];
    // }
    // first column is constructed
    // i think using only column is not possible
    // let's try using two columns

    int dp[n][2];
    memset(dp, 0, sizeof dp);
    for(int i=0;i<n;i++){
        dp[i][0]=vec[i][0];
    }
    // first column is constructed
    // now construct the second columsn using the first column
    int result=0;
    for(int c=1;c<m;c++){
        for(int r=0;r<n;r++){
            int left=dp[r][0];
            int left_top=(r-1>=0)?dp[r-1][0]:0;
            int left_bottom=(r+1<n)?dp[r+1][0]:0;
            dp[r][1]=max(max(left_top,left_bottom),left)+vec[r][c];
            result=max(result,dp[r][1]);
        }
        // now that we have calculated the second column 
        // move the second column elements to the first column
        for(int r=0;r<n;r++){
            dp[r][0]=dp[r][1];
        }
    }
    return result;
}

// we can further optimize this solution 
// as we are only concerned with the last column



int main() {
  // vector<vector<int>>vec{{1, 3, 3},
  //                       {2, 1, 4},
  //                       {0, 6, 4}};
vector<vector<int>>vec{{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
  // get the max value for the first column
// vector<vector<int>>vec{ {1, 3, 1, 5},
//                       {2, 2, 4, 1},
//                       {5, 0, 2, 3},
//                       {0, 6, 1, 2}};
  int j=0;
  int k=0;
  int value=INT_MIN;
  int rows=vec.size();
  int cols=vec[0].size();
  // std::cout<<solve(vec)<<std::endl;
  // std::cout<<solveDP(vec)<<std::endl;
  std::cout<<f_optimize_dp(vec)<<std::endl;
  return 0;
}
