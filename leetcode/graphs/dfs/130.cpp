#include <iostream>
#include <vector>
// https://leetcode.com/problems/surrounded-regions/description/

using namespace std;
class Solution {
    public:
        void dfs(vector<vector<char>> &board, int i, int j, int m, int n) {
            if (i >= 0 && j >= 0 && i < m && j < n) {
                if (board[i][j] == 'O') { // then this is the boundary start
                                          // the idea is to ignore these elements
                    board[i][j] = '1';
                    // now first go top

                    if (i > 1) {
                        dfs(board, i - 1, j, m, n);
                    }
                    // go bottom
                    if (i + 1 < m) {
                        dfs(board, i + 1, j, m, n);
                    }
                    // go left
                    if (j - 1 >= 0) {
                        dfs(board, i, j - 1, m, n);
                    }
                    if (j + 1 >= 0) {
                        dfs(board, i, j + 1, m, n);
                    }
                }
            }
        }
        void solve(vector<vector<char>> &board) {
            int m = board.size();
            int n = board[0].size();

            // traversing through the board
            // covering the rows 0 and n-1 traversing through the column
            for (int i = 0; i < n; i++) {
                dfs(board, 0, i, m, n);
                dfs(board, m - 1, i, m, n);
            }
            for (int i = 0; i < m; i++) {
                dfs(board, i, 0, m, n);
                dfs(board, i, n - 1, m, n);
            }
            // now cells with 1 should be 0 other than that all others should be X

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '1') {
                        board[i][j] = 'O';
                    } else {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};
int main() {
    vector<vector<char>> board
       {{'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution s;
    s.solve(board);
}
