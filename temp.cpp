#include <algorithm>
#include <climits>
#include <iostream>
#include <regex>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int solve(vector<vector<int>>&traingle,int k,int i){
//         if (k<traingle.size()) {
//             return traingle[k][i]+min(solve(traingle, k+1, i),solve(traingle,
//             k+1, i+1));
//         }
//         return 0;
//     }
//     void minimumTotal(vector<vector<int>>& triangle) {
//         int result={};
//         result=solve(triangle,0,0);
//         std::cout<<result<<std::endl;
//     }
// };
// memoizing the above solution
class Solution {
public:
  int solve(vector<vector<int>> &traingle, int k, int i,
            vector<vector<int>> &memo) {
    if (k < traingle.size()) {
      if (memo[k][i] != -1) {
        return memo[k][i];
      }
      memo[k][i] = traingle[k][i] + min(solve(traingle, k + 1, i, memo),
                                        solve(traingle, k + 1, i + 1, memo));
      return memo[k][i];
    }
    return 0;
  }
  void minimumTotal(vector<vector<int>> &triangle) {
    int result = {};
    vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), -1));
    result = solve(triangle, 0, 0, memo);
    std::cout << result << std::endl;
  }
};
// bottom up approach
// class Solution {
// public:
//   void minimumTotal(vector<vector<int>> &triangle) {
//     int result = {};
//     vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), -1));
//     for (int i = 0; i < triangle.size(); i++) {
//       memo[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
//     }
//     for (int i = triangle.size() - 2; i >= 0; i--) {
//       for (int j = 0; j <= i; j++) {
//         memo[i][j] = triangle[i][j] + min(memo[i + 1][j], memo[i + 1][j + 1]);
//       }
//     }
//     std::cout << memo[0][0] << std::endl;
//   }
// };

// bottom up approach with space optimization
// class Solution {
// public:
//   void minimumTotal(vector<vector<int>> &triangle) {
//     int result = {};
//     vector<int> memo(triangle.size(), -1);
//     for (int i = 0; i < triangle.size(); i++) {
//       memo[i] = triangle[triangle.size() - 1][i];
//     }
//     for (int i = triangle.size() - 2; i >= 0; i--) {
//       for (int j = 0; j <= i; j++) {
//         memo[j] = triangle[i][j] + min(memo[j], memo[j + 1]);
//       }
//     }
//     std::cout << memo[0] << std::endl;
//   }
// };
int main() {
  // std::vector<std::vector<int>>vec{{2},{3,4},{6,5,7},{4,1,8,3}};
  vector<vector<int>> vec{{-10}};
  Solution s;
  s.minimumTotal(vec);

  // std::vector<std::vector<int>>vec{{-1},{2,3},{1,-1,-3}};
  // std::vector<std::vector<int>>memo(vec.size(),std::vector<int>(vec.size(),-1));
  // findShortest(vec, 0,0,memo);
  // findShortest(vec);
  // std::cout<<memo[0][0]<<std::endl;
}
