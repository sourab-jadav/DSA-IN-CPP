#include <iostream>
#include <memory_resource>
#include <vector>
// recursive approach
// class Solution {
// public:
//   int solve(int m, int n, std::vector<std::vector<int>> &memo) {
//     if (m <= 0 || n <= 0) {
//       return 0;
//     }
//     if (m == 1 && n == 1) {
//       return 1;
//     }
//     if (memo[m][n] != -1) {
//       return memo[m][n];
//     }
//
//     return memo[m][n] = solve(m - 1, n, memo) + solve(m, n - 1, memo);
//   }
//   int uniquePaths(int m, int n) {
//
//     std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
//     solve(m, n, memo);
//     return memo[m][n];
//   }
// };
// tabulizing the shit

class Solution {
public:
  int solve(int m, int n, std::vector<std::vector<int>> &memo) {
    if (m <= 0 || n <= 0) {
      return 0;
    }
    if (m == 1 && n == 1) {
      return 1;
    }
    if (memo[m][n] != -1) {
      return memo[m][n];
    }

    return memo[m][n] = solve(m - 1, n, memo) + solve(m, n - 1, memo);
  }
  void uniquePaths(int m, int n) {
    std::vector<std::vector<int>> memo(m + 1, std::vector<int>(n + 1, -1));
    solve(m, n, memo);

    std::cout<<memo[m][n]<<std::endl;

  }
};
int main() {
  Solution s;
 s.uniquePaths(3, 7);
  std::cout << "what is with how are you doing it so well" << std::endl;
  return 0;
}
